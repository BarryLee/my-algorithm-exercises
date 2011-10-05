#include "heap.h"
#include <stdexcept>

template<class T>
Heap<T>::Heap(const vector<T> &vec): arr(vec), sz(vec.size())
{
    for (size_t i = arr.size()/2; i >= 0; i--)
        heapify(i);
}

template<class T>
T& Heap<T>::pop()
{
    if (sz) {
        T temp = arr[0];
        arr[0] = arr[sz-1];
        arr[sz---1] = arr[0];
        heapify(0);
        return temp;
    } else 
        throw std::runtime_error("empty heap!");
}

template<class T>
const T& Heap<T>::top() const
{
    if (sz)
        return arr[0];
    else
        throw std::runtime_error("empty heap!");
}

template<class T>
void Max_heap<T>::heapify(size_t idx)
{
    size_t max = idx,
           lc = left(idx),
           rc = right(idx);

    if (lc < sz && arr.at(max) < arr.at(lc))
        max = lc;
    if (rc < sz && arr.at(max) < arr.at(rc))
        max = rc;
    if (max != idx) {
        T temp = arr.at(idx);
        arr.at(idx) = arr.at(max);
        arr.at(max) = temp;
        heapify(max);
    }
}

template<class T>
void Max_heap<T>::insert(const T &elem)
{
    if (++sz > arr.size())
        arr.reserve(sz);
    i = sz-1;
    arr[i] = elem;
    while (arr[i] > arr[parent(i)]) {
        exchange(i, parent(i));
        i = parent(i);
    }
}
    
