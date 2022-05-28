#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

template <typename T>
class ForwardList{
private:
    class Node{
    public:
        Node *next;
        T data;

        Node(T data = T(), Node *next = nullptr);
    };

    size_t size;
    Node *head;

public:
    ForwardList(void);

    ~ForwardList(void);

    void push_front(const T &data);

    void push_back(const T &data);

    size_t get_size(void) const;

    void pop_front(void);

    void pop_back(void);

    void insert(const T &data, const size_t index);

    void remove_at(const size_t index);

    T& operator[] (const size_t index) const;
};

#endif // !FORWARD_LIST_H