#include <iostream>
#include <vector>
#include <string>

class MaxHeap {
public:
    MaxHeap(){}
    MaxHeap(const std::vector<int> &ivec) : _vec(ivec), _heap_size(ivec.size()) {}
    ~MaxHeap(){}

    void max_heapify(std::vector<int>::size_type i);
    void build_max_heap();
private:
    std::vector<int> _vec;
    std::vector<int>::size_type _heap_size;
};
