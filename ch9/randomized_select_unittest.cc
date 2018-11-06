#include <iostream>
#include <vector>

#include "randomized_select.h"

int main() {
    std::vector<int> ivec{3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
    int i;
    while(std::cin >> i) {
        std::cout << randomized_select(ivec, 0, 9, i) << std::endl;
    }
}
