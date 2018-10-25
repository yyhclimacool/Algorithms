#include "heap.h"
#include <limits.h>

void MaxHeap::max_heapify(std::vector<int>::size_type i) {
    auto l = 2 * (i + 1) - 1;
    auto r = 2 * (i + 1);
    decltype(l) largest = 0;
    if (l <= _heap_size - 1 && _vec[l] > _vec[i])
        largest = l;
    else 
        largest = i;
    if (r <= _heap_size - 1 && _vec[r] > _vec[largest])
        largest = r;

    if (largest != i) {
        std::swap(_vec[i], _vec[largest]);
        max_heapify(largest);
    }
}

void MaxHeap::build_max_heap() {
    if (_vec.empty() || _heap_size == 0)
        return;
    for (int i = _vec.size() / 2 - 1; i >= 0; --i) {
        max_heapify(i);
    }
}

void MaxHeap::heap_sort() {
    build_max_heap();
    for (std::vector<int>::size_type i = _heap_size - 1; i != 0; --i) {
        std::swap(_vec[0], _vec[i]);
        _heap_size -= 1;
        max_heapify(0);
    }
}

bool MaxHeap::heap_extract_max(int &max) {
    if (_heap_size < 1) {
        std::cerr << "Heap Underflow!" << std::endl;
        return false;
    }
    max = _vec[0];
    std::swap(_vec[0], _vec[_heap_size-1]);
    --_heap_size;
    max_heapify(0);
}

void MaxHeap::heap_increase_key(std::vector<int>::size_type i, int key) {
    if (i >= _heap_size) {
        std::cerr << "Heap Overflow!" << std::endl;
        return;
    }
    if (key <= _vec[0]) {
        std::cerr << "ERROR: New key is not bigger than max heap!" << std::endl;
    }
    _vec[i] = key;
    while(i != 0 && _vec[(i+1)/2 - 1] < _vec[i]) {
        std::swap(_vec[i], _vec[(i+1)/2 - 1]);
        i = (i+1)/2 - 1;
    }
}

void MaxHeap::heap_insert(int key) {
    if (_heap_size == _vec.size()) {
        _vec.push_back(key);
        _heap_size = _vec.size();
    } else {
        _vec[(_heap_size++) - 1] = INT_MIN;
    }
    heap_increase_key(_heap_size-1, key);
}

std::ostream &operator<<(std::ostream &os, const MaxHeap &_heap) {
    for (const auto & i : _heap._vec)
        os << i << " ";

    return os;
}
