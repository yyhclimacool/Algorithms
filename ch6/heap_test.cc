#include "heap.h"

int main() {
    std::vector<int> ivec = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    MaxHeap maxheap(ivec);
    maxheap.heap_sort();
    std::cout << maxheap << std::endl;
    return 0;
}
