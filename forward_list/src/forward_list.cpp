#include "forward_list.h"

template <typename T>
ForwardList<T>::ForwardList(void){
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
ForwardList<T>::~ForwardList(void){
    Node *current {this->head};
    Node *next;

    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void ForwardList<T>::push_front(const T &data){
    if (this->head == nullptr){
        this->head = new Node(data);
    }
    else{
        Node *new_head = new Node(data);
        new_head->next = head;
        // we make swap to do new_head the main ForwardList head;
        std::swap(head, new_head);
    }

    ++size;
}

template <typename T>
void ForwardList<T>::push_back(const T &data){
    if (this->head == nullptr){
        this->head = new Node(data);
    }
    else{
        Node *current = this->head;

        while (current->next != nullptr){
            current = current->next;
        }

        current->next = new Node(data);
    }

    ++size;
}

template <typename T>
size_t ForwardList<T>::get_size(void) const{
    return size;
}

template <typename T>
void ForwardList<T>::pop_front(void){
    Node *temp {this->head};
    this->head = this->head->next;

    delete temp;

    --size;
}

template <typename T>
void ForwardList<T>::pop_back(void){
    Node *new_end {this->head};

    /* -1 because cycle started from zero and -1 because we need 
     * the element befor previous;
     */
    for (size_t i {0}; i < size - 2; ++i){
        new_end = new_end->next;
    }

    delete new_end->next;
    new_end->next = nullptr;

    --size;
}

template <typename T>
void ForwardList<T>::insert(const T &data, const size_t index){
    if (index > this->size)
        throw std::out_of_range("ForwardList size is " 
            + std::to_string(this->size) + ", but you want " 
            + std::to_string(index));

    if (index == 0){
        this->push_front(data);
    }
    else if (index == (this->size)){
        this->push_back(data);
    }
    else{
        Node *current {this->head};
        /* -1 because we need to insert element into index
         * position;
         */
        for (size_t i {0}; i < index - 1; ++i){
            current = current->next;
        }

        Node *new_elem = new Node(data);
        new_elem->next = current->next;
        current->next = new_elem;
        ++size;
    }
}

template <typename T>
void ForwardList<T>::remove_at(const size_t index){
    if (index > this->size)
        throw std::out_of_range("ForwardList size is " 
            + std::to_string(this->size) + ", but you want " 
            + std::to_string(index));

    if (index == 0){
        this->pop_front();
    }
    else if (index == (this->size)){
        this->pop_back();
    }
    else{
        Node *current {this->head};
        /* -1 because we need to find previous of removed
         * element;
         */
        for (size_t i {0}; i < index - 1; ++i){
            current = current->next;
        }

        Node *removed_elem {current->next};
        /* make pointer to the next element so as not to lose 
         * the sequence of the ForwardList 
         */
        current->next = removed_elem->next;
        delete removed_elem;

        --size;
    }
}

template <typename T>
T& ForwardList<T>::operator[] (const size_t index) const {
    Node *current {this->head};
    size_t i = 0;

    while (current != nullptr && i < index){
        current = current->next;
        ++i;
    }

    if (i != index)
        throw std::out_of_range("ForwardList size is " 
            + std::to_string(this->size) + ", but you want " 
            + std::to_string(index));
    
    return current->data;
}