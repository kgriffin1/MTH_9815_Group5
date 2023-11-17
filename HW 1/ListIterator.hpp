#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "Node.hpp"

template <typename T>
class ListIterator {
public:
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* startNode) : current(startNode) {}

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
};

#endif // LISTITERATOR_HPP
