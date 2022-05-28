#include "forward_list.h"

template <typename T>
ForwardList<T>::Node::Node(T data, Node *next){
    this->data = data;
    this->next = next;
}