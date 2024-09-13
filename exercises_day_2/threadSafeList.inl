#ifndef SAFE_LIST_INL
#define SAFE_LIST_INL

#include "threadSafeList.hpp"

template <typename T>
T ts::SafeList<T>::back() const
{
    T element{};
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    element = m_list.back();
    lock.unlock();
    return element;
}

template <typename T>
T ts::SafeList<T>::front() const
{
    T element{};
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    element = m_list.front();
    lock.unlock();
    return element;
}

template <typename T>
void ts::SafeList<T>::insert(size_t pos, const T &element)
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    m_list.insert(std::next(m_list.begin(), pos), element);
}

template<typename T>
void ts::SafeList<T>::push_back(const T& element)
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    m_list.push_back(element);
}

template<typename T>
void ts::SafeList<T>::push_front(const T& element)
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    m_list.push_front(element);
}

template<typename T>
void ts::SafeList<T>::pop_back()
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    m_list.pop_back();
}

template<typename T>
void ts::SafeList<T>::pop_front()
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    m_list.pop_front();
}

template<typename T>
size_t ts::SafeList<T>::remove(T& element)
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    size_t res = m_list.remove(element);
    lock.unlock();
    return res;
}

template<typename T>
void ts::SafeList<T>::reverse()
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    size_t res = m_list.reverse();
}

template<typename T>
size_t ts::SafeList<T>::unique()
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    size_t res = m_list.unique();
    lock.unlock();
    return res;
}

template<typename T>
void ts::SafeList<T>::sort()
{
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    size_t res = m_list.sort();
}

template <typename T>
size_t ts::SafeList<T>::size() const
{
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    size_t size = m_list.size();
    lock.unlock();
    return size;
}

template <typename T>
bool ts::SafeList<T>::empty() const
{
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    bool res = m_list.empty();
    lock.unlock();
    return res;
}

#endif