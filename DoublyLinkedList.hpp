#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "DNode.hpp"
#include "DoublyLinkedListIterator.hpp"

template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int listSize;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void Add(T& value) {
        DNode<T>* newNode = new DNode<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    void Insert(T& value, int index) {
        if (index < 0 || index > listSize) {
            throw std::out_of_range("Index out of range");
        }
        DNode<T>* newNode = new DNode<T>(value);
        if (index == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
        }
        else if (index == listSize) {
            Add(value);
        }
        else {
            DNode<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        listSize++;
    }

    T& Get(int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        DNode<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    int IndexOf(T& value) {
        DNode<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    T& Remove(int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        DNode<T>* toRemove = head;
        if (index == 0) {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
        }
        else {
            for (int i = 0; i < index; i++) {
                toRemove = toRemove->next;
            }
            toRemove->prev->next = toRemove->next;
            if (toRemove->next) {
                toRemove->next->prev = toRemove->prev;
            }
            else {
                tail = toRemove->prev;
            }
        }
        listSize--;
        T& data = toRemove->data;
        delete toRemove;
        return data;
    }

    int Size() const { return listSize; }

    DoublyLinkedListIterator<T> Iterator() { return DoublyLinkedListIterator<T>(head); }
};

#endif // DOUBLYLINKEDLIST_HPP
