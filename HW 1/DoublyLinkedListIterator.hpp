#ifndef DOUBLYLINKEDLISTITERATOR_HPP
#define DOUBLYLINKEDLISTITERATOR_HPP

#include "DNode.hpp"

template <typename T>
class DoublyLinkedListIterator {
private:
    DNode<T>* current;

public:
    DoublyLinkedListIterator(DNode<T>* startNode) : current(startNode) {}

    bool HasNext() const { return current != nullptr; }

    T& Next() {
        if (!current) {
            throw std::out_of_range("No more elements");
        }
        T& data = current->data;
        current = current->next;
        return data;
    }
};

#endif // DOUBLYLINKEDLISTITERATOR_HPP
