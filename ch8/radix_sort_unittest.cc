#include <iostream>
#include "radix_sort.h"

int main() {
    std::vector<int> a{329, 457, 657, 839, 436, 720, 355};
    radix_sort(a, 3);
    for (const auto &e : a)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}
