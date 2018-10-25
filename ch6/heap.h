#ifndef _HEAP_
#define _HEAP_

#include <iostream>
#include <vector>
#include <string>

class MaxHeap {
    friend std::ostream &operator<<(std::ostream &os, const MaxHeap &_heap);
public:
    MaxHeap(){}
    MaxHeap(const std::vector<int> &ivec) : _vec(ivec), _heap_size(ivec.size()) {}
    ~MaxHeap(){}

    void max_heapify(std::vector<int>::size_type i);
    void build_max_heap();
    void heap_sort();
private:
    std::vector<int> _vec;
    std::vector<int>::size_type _heap_size;
};

#endif // _HEAP_
