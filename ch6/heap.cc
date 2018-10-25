#include "heap.h"

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

std::ostream &operator<<(std::ostream &os, const MaxHeap &_heap) {
    for (const auto & i : _heap._vec)
        os << i << " ";

    return os;
}
