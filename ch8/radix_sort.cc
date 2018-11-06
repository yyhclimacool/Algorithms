#include "radix_sort.h"

/* 
 *
 *
 *
 */
void counting_sort_on_digit_i(std::vector<int> &a, std::vector<int> &b, int k, int i) {
    int div_num = 1;
    for (int t = 1; t < i; ++t)
        div_num *= 10;
    b.clear();
    b.resize(a.size());
    std::vector<int> c(k, 0);
    for (int j = 0; j < a.size(); ++j)
        ++c[(a[j] / div_num) % 10];
    for (int j = 1; j < k; ++j)
        c[j] = c[j] + c[j-1];
    for (int j = a.size() - 1; j >= 0; --j){
        b[c[(a[j] / div_num) % 10] - 1] = a[j];
        --c[(a[j] / div_num) % 10];
    }
}

void radix_sort(std::vector<int> &a, int d) {
    for (int i = 1; i <= d; ++i) {
        std::vector<int> temp_vec;
        counting_sort_on_digit_i(a, temp_vec, 10, i);
        a = temp_vec;
    }
}
