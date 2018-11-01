#include <iostream>
#include "counting_sort.h"

int main() {
    std::vector<int> ivec = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    std::vector<int> outvec;
    counting_sort(ivec, outvec, 6);
    for (const auto &e : outvec)
        std::cout << e << " ";
    std::cout << std::endl;
}
