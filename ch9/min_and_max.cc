#include <vector>
#include <iostream>

// 这里假设元素互异
void find_min_and_max(std::vector<int> &a, int &b, int &s) {
    size_t num = a.size();
    int min = 0, max = 0;
    size_t index = 0;
    if (num % 2 == 1) {
        min = max = a[0];
        index = 1;
    } else {
        max = a[0] > a[1] ? a[0] : a[1];
        min = a[0] < a[1] ? a[0] : a[1];
        index = 2;
    }
    for (; index < a.size(); index += 2) {
        int bigger = a[index] > a[index + 1] ? a[index] : a[index + 1];
        int smaller = a[index] < a[index + 1] ? a[index] : a[index + 1];
        if (bigger > max)
            max = bigger;
        if (smaller < min)
            min = smaller;
    }
    b = max;
    s = min;
}

int main() {
    std::vector<int> ivec = {5, 3, 1, 6, 9, 7, 8, 4, 12, 17, 23, 83, 0};
    int b, s;
    find_min_and_max(ivec, b, s);
    std::cout << "min : " << s << ", max : " << b << std::endl;
    return 0;
}
