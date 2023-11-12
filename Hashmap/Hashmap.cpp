#pragma once

#include "Hashmap.hpp"
#include <stdexcept>

// Constructor.
template <typename K, typename V>
Hashtable<K, V>::Hashtable(std::shared_ptr<EqualityPredicate<K>> pred, std::shared_ptr<Hasher<K>> hasher, long size) :
m_table(size), m_pred(pred), m_hasher(hasher) {}

// Copy constructor.
template <typename K, typename V>
Hashtable<K, V>::Hashtable(const Hashtable<K, V>& source) : 
m_table(source.m_table), m_pred(source.m_pred), m_hasher(source.m_hasher) {}

// Virtual destructor.
template <typename K, typename V>
Hashtable<K, V>::~Hashtable() {}

// Setter.
template <typename K, typename V>
void Hashtable<K, V>::set(const K& key, const V& value)
{
    long index = m_hasher->hash(key) % m_table.size();      // Find the index of the key array for storing the value.
    for (auto& val : m_table[index])
    {
        if (m_pred->isEqual(key, val.first))                // If the key is already in the hash table, update the corresponding value.
        {
            val.second = value;
            return;
        }
    }
    m_table[index].push_back(std::make_pair(key, value));   // Otherwise, add the key-value pair to the array at the index returned by the hashing function.
}

// Getter.
template <typename K, typename V>
V& Hashtable<K, V>::get(const K& key)
{
    long index = m_hasher->hash(key) % m_table.size();  // Find the index of the key array for returning the value.
    for (auto& val : m_table[index])                    // Loop through the elements of the values array at the index.
    {
        if (m_pred->isEqual(key, val.first))            // If we find a matching key, return the value.
        {
            return val.second;
        }
    }
    throw std::out_of_range("Key not found.");          // Throw an error if the key isn't in the table.
}

// Clear one key-value pair.
template <typename K, typename V>
void Hashtable<K, V>::clear(const K& key) 
{
    long index = m_hasher->hash(key) % m_table.size();          // Find the index of the key array for clearing the key-value pair.
    auto& bucket = m_table[index];                              // Utilize iterators this time since we will erase the element.
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (m_pred->isEqual(it->first, key))                    // If we find a matching key, erase the key-value pair and terminate early.
        {
            bucket.erase(it);
            return;
        }
    }
}

// Clear all key-value pairs.
template <typename K, typename V>
void Hashtable<K, V>::clear() 
{
    for (auto& bucket : m_table) // Delegates to the vector clear function. Loops through all value vectors and clears the elements.
    {
        bucket.clear();
    }
}

// Copy assignment operator.
template <typename K, typename V>
Hashtable<K, V>& Hashtable<K, V>::operator=(const Hashtable<K, V>& source) 
{
    // Avoid self assignment.
    if (this != &source)
    {
        // Copy state.
        m_table = source.m_table;
        m_pred = source.m_pred;
        m_hasher = source.m_hasher;
    }

    return *this;
}

// Access/assignment operator.
template <typename K, typename V>
V& Hashtable<K, V>::operator[](const K& key)
{
    long index = m_hasher->hash(key) % m_table.size();      // Find the index of the key array for the key-value pair.
    for (auto& val : m_table[index])                        // If the key is present in the table, return the value.
    {
        if (m_pred->isEqual(key, val.first))
        {
            return val.second;
        }
    }
    
    // If key is not found, create a new key-value pair.
    m_table[index].emplace_back(std::make_pair(key, V()));  // Construct a key-value pair with a default value.
    return m_table[index].back().second;                    // Return a reference to the value of the key-value pair for assignment.
}