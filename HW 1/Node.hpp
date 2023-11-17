#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) : data(data), next(nullptr) {}
};

#endif // NODE_HPP

