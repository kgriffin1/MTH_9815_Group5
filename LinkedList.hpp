#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include "ListIterator.hpp"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int listSize;

public:
    LinkedList() : head(nullptr), listSize(0) {}

    void Add(T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        listSize++;
    }

    void Insert(T& value, int index) {
        if (index < 0 || index > listSize) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* newNode = new Node<T>(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        listSize++;
    }

    T& Get(int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    int IndexOf(T& value) {
        Node<T>* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    T& Remove(int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* temp = head;
        if (index == 0) {
            head = head->next;
        }
        else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        listSize--;
        T data = temp->data;
        delete temp;
        return data;
    }

    int Size() const { return listSize; }

    typename ListIterator<T>::Iterator Iterator() { return typename ListIterator<T>::Iterator(head); } //
};

#endif // LINKEDLIST_HPP