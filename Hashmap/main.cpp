#include "Hashmap.hpp"
#include <iostream>
#include <string>

// Implementation of Hasher for std::string.
class StringHasher : public Hasher<std::string>
{
public:
    long hash(const std::string& key) const override
    {
        // Create a hash value by summing up 13 * the integer values of each character in the string.
        long hash = 0;
        for (char c : key)
        {
            hash += 13 * int(c);
        }
        return hash;
    }
};

// Implementation of EqualityPredicate for std::string.
class StringEqualityPredicate : public EqualityPredicate<std::string>
{
public:
    bool isEqual(const std::string& elem1, const std::string& elem2) const override
    {
        return elem1 == elem2;
    }
};

void test_Hashtable()
{
    // Create an instance of the hashing funciton and predicate.
    auto hasher = std::make_shared<StringHasher>();
    auto predicate = std::make_shared<StringEqualityPredicate>();

    // Create a Hashtable.
    Hashtable<std::string, int> myMap(predicate, hasher, 10);

    // Test set and get functionalities.
    myMap.set("apple", 5);
    myMap.set("banana", 10);
    myMap.set("orange", 15);

    std::cout << "apple: " << myMap.get("apple") << std::endl;
    std::cout << "banana: " << myMap.get("banana") << std::endl;
    std::cout << "orange: " << myMap.get("orange") << std::endl;

    // Test operator [].
    myMap["pear"] = 20;                                     // Setting.
    std::cout << "pear: " << myMap["pear"] << std::endl;    // Getting.

    // Test clear.
    myMap.clear("banana"); // Clear just the banana entry.
    try
    {
        std::cout << "banana: " << myMap.get("banana") << std::endl;
    }
    catch (const std::out_of_range& err)
    {
        std::cout << "banana is not in the hash table." << std::endl;
    }

    // Test clear all.
    myMap.clear(); // This should clear apple, orange, and pear.

    try
    {
        std::cout << "apple: " << myMap.get("apple") << std::endl;
    }
    catch (const std::out_of_range& err)
    {
        std::cout << "apple is not in the hash table." << std::endl;
    }

    try
    {
        std::cout << "orange: " << myMap.get("orange") << std::endl;
    }
    catch (const std::out_of_range& err)
    {
        std::cout << "orange is not in the hash table." << std::endl;
    }
}

int main()
{
    test_Hashtable();
    return 0;
}