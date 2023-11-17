#ifndef DNODE_HPP
#define DNODE_HPP

template <typename T>
class DNode {
public:
    T data;
    DNode<T>* prev;
    DNode<T>* next;

    DNode(T data) : data(data), prev(nullptr), next(nullptr) {}
};

#endif // DNODE_HPP
