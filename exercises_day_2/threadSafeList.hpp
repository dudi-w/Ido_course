#ifndef SAFE_LIST_HPP
#define SAFE_LIST_HPP

#include <list>
#include <functional>
#include <shared_mutex>
#include <mutex>

namespace ts{ //tread safe

template<typename T>
class SafeList
{
public:
    SafeList() = default;
    SafeList(SafeList const& other) = delete;
    SafeList& operator=(SafeList const& other) = delete;
    ~SafeList() = default;

public:
    T back() const;
    T front() const;
    size_t size() const;
    bool empty() const;
    void insert(size_t pos, const T& element);
    void push_back(const T& element);
    void push_front(const T& element);
    void pop_back();
    void pop_front();
    size_t remove(T& element);
    void reverse();
    size_t unique();
    void sort();

private:
    std::list<T> m_list;
    mutable std::shared_mutex m_mutex;
};

}// namespace se

#include "threadSafeList.inl"

#endif