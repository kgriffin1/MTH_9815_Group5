// This is a program written as an exercise for Baruch MFE MTH 9815.
// Exercise Number: 1.3
// 
// Author: Kevin Griffin
// Initial Release Date: 11/11/2023
// 
// Revision: A
// 
// Program Objective:   Write a hash table class that maps keys to values. To accomplish this, I will utilize composition to implement a Hashtable class
//                      which has shared pointers to a hashing function and equality predicate as member data. Member functions will allow for getting,
//                      setting, and clearing key-value pairs. Additionally, the [] operator will be overloaded to allow for Python-style assignment and
//                      access.
// 

#pragma once

#include <vector>       // I utilize vectors rather than arrays to allow for dynamic resizing of the hash table.
#include <memory>       // Needed for shared pointers.

template <typename K>
class EqualityPredicate
{
    // Abstract base class for equally comparing two elements. 
    //

public:
    virtual ~EqualityPredicate() {};
    virtual bool isEqual(const K& elem1, const K& elem2) const = 0;
};

template <typename K>
class Hasher
{
    // Abstract base class for generating a hash value (array index) from a key.
    //

public:
    virtual ~Hasher() {};
    virtual long hash(const K& key) const = 0;
};

template <typename K, typename V>
class Hashtable
{
private:
    std::vector<std::vector<std::pair<K,V>>> m_table;   // Vector of vectors of key-value pairs. Allows for dynamic resizing of both the key array
                                                        // and corresponding value array.
    std::shared_ptr<EqualityPredicate<K>> m_pred;       // Pointer to equality predicate. 
    std::shared_ptr<Hasher<K>> m_hasher;                // Pointer to hashing function.

public:
    // Constructors.
    Hashtable(std::shared_ptr<EqualityPredicate<K>> pred, std::shared_ptr<Hasher<K>> haser, long size = 10); // Constructor.
    Hashtable(const Hashtable& source);                 // Copy constructor.

    // Destructor.
    virtual ~Hashtable();                               // Virtual destructor.    

    // Getters and Setters.
    void set(const K& key, const V& value);             // Add a key-value pair to the table.
    V& get(const K& key);                               // Return a value corresponding to the input key.
    
    // Clearing a key/value pair(s).
    void clear(const K& key);                           // Clear one key-value pair.
    void clear();                                       // Clear all key-value pairs.

    // Operators.
    Hashtable& operator = (const Hashtable& source);    // Copy assignment operator.
    V& operator [](const K& key);                       // Access/assignment operator.
};

#include "Hashmap.cpp"