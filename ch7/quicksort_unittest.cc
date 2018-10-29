#include "quicksort.h"
#include <iostream>

int main() {
    int a[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    quicksort(a, 0, 11);
    for (const auto & e : a)
        std::cout << e << " " ;
    std::cout << std::endl;
}
