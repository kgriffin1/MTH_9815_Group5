// DataStructures_HW1.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.

// 

#include <iostream>
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"

int main()
{
    std::cout << "Starting Single Linked List Test Cases:" << std::endl;

    LinkedList<int> list;
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    // Adding elements to the list
    std::cout << "Adding elements: ";
    list.Add(a);
    list.Add(b);
    list.Add(c);
    std::cout << a << " " << b << " " << c << std::endl;

    // Displaying all elements in the list
    std::cout << "Current List: ";
    for (int i = 0; i < list.Size(); i++) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << std::endl;

    // Inserting elements
    std::cout << "Inserting " << d << " at index 1" << std::endl;
    list.Insert(d, 1);

    // Displaying all elements after insertion
    std::cout << "List after insertion: ";
    for (int i = 0; i < list.Size(); i++) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << std::endl;

    // Using the iterator
    std::cout << "Iterating through the list: ";
    auto iterator = list.Iterator();
    while (iterator.HasNext()) {
        std::cout << iterator.Next() << " ";
    }
    std::cout << std::endl;

    // Removing an element
    std::cout << "Removing element at index 2: ";
    std::cout << list.Remove(2) << std::endl;
    std::cout << "Now the list is: ";
    for (int i = 0; i < list.Size(); i++) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << std::endl;

    // Finding the index of an element
    std::cout << "Index of element " << b << ": " << list.IndexOf(b) << std::endl;

    // Adding another element
    std::cout << "Adding " << e << std::endl;
    list.Add(e);

    // Displaying final state of the list
    std::cout << "Final List: ";
    for (int i = 0; i < list.Size(); i++) {
        std::cout << list.Get(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Starting Doubly Linked List Test Cases:" << std::endl;

    DoublyLinkedList<int> dlList;
    int x = 15, y = 25, z = 35, w = 45, v = 55;

    // Adding elements
    dlList.Add(x);
    dlList.Add(y);
    dlList.Add(z);
    std::cout << "Added elements: " << x << ", " << y << ", " << z << std::endl;

    // Inserting element
    dlList.Insert(w, 1); // Insert w at index 1
    std::cout << "Inserted " << w << " at index 1" << std::endl;

    // Getting element
    std::cout << "Element at index 2: " << dlList.Get(2) << std::endl;

    // Removing element
    std::cout << "Removing element at index 2: ";
    std::cout << dlList.Remove(2) << std::endl;
    std::cout << "Now the list is: ";
    for (int i = 0; i < dlList.Size(); i++) {
        std::cout << dlList.Get(i) << " ";
    }
    std::cout << std::endl;

    // Using the iterator
    std::cout << "Iterating through list: ";
    auto diterator = dlList.Iterator();
    while (diterator.HasNext()) {
        std::cout << diterator.Next() << " ";
    }
    std::cout << std::endl;

    // Finding the index of an element
    std::cout << "Index of " << y << ": " << dlList.IndexOf(y) << std::endl;

    // Adding another element
    dlList.Add(v);
    std::cout << "Added " << v << std::endl;

    // Displaying final state of list
    std::cout << "Final List: ";
    diterator = dlList.Iterator();
    while (diterator.HasNext()) {
        std::cout << diterator.Next() << " ";
    }
    std::cout << std::endl;

    return 0;
}


