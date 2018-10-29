#include "heap.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> ivec = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    MaxHeap maxheap(ivec);
    std::cout << "Original heap           --- " << maxheap << std::endl;
    maxheap.build_max_heap();
    std::cout << "After build             --- " << maxheap << std::endl;
    std::cout << "Heap maximum            --- " << maxheap.heap_maximum() << std::endl;
    maxheap.heap_insert(21);
    std::cout << "Insert 21 into max heap --- " << maxheap << std::endl;
    maxheap.heap_increase_key(7, 37);
    std::cout << "Increase key 7 - 37     --- " << maxheap << std::endl;
    maxheap.heap_delete(2);
    std::cout << "Delete key 2            --- " << maxheap << std::endl;
    return 0;
}
