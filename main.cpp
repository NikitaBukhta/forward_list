#include "forward_list"

template <typename T>
void output_list(const ForwardList<T> &list){
    size_t list_size = list.get_size();
    for (size_t i {0}; i < list_size; ++i){
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv){
    ForwardList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(22);
    list.push_back(44);

    output_list(list);
    std::cout << std::endl;

    list.pop_front();
    output_list(list);
    std::cout << std::endl;

    list.pop_back();
    output_list(list);
    std::cout << std::endl;

    list.push_front(101);
    output_list(list);
    std::cout << std::endl;

    list.insert(33, 0);
    list.insert(756, list.get_size());
    list.insert(1, list.get_size());
    list.insert(645, 3);
    output_list(list);
    std::cout << std::endl;

    list.remove_at(3);
    output_list(list);
    std::cout << std::endl;

    return 0;
}