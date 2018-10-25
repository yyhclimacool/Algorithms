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

    // Priority queue
    int heap_maximum() { return _vec[0]; }
    bool heap_extract_max(int &);
    void heap_increase_key(std::vector<int>::size_type, int);
    void heap_insert(int);
private:
    std::vector<int> _vec;
    std::vector<int>::size_type _heap_size;
};

#endif // _HEAP_
