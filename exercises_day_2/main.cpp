#include <thread>
#include <array>
#include <iostream>

#include "threadSafeList.hpp"

void push_elements(ts::SafeList<int>& list){
    for(int i = 0 ; i < 1000; ++i){
        list.push_back(i);
    }
}

int main(int argc, char const *argv[])
{
    ts::SafeList<int> myList;
    std::array<std::thread, 10> threads;
    for(size_t i = 0; i < 10 ; ++i){
        threads[i] = std::thread(push_elements, std::ref(myList));
    }
    for(size_t i = 0; i < 10 ; ++i){
        threads[i].join(); 
    }
    size_t size = myList.size();
    std::cout<<"myList.size() = "<<size<<std::endl;
    for(size_t i = 0; i < size; ++i){
        std::cout<<myList.front()<<",";
        myList.pop_front();
    }
    return EXIT_SUCCESS;
}
