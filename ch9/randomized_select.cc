#include "randomized_select.h"

int partition(std::vector<int> &a, int p, int r) {
    if (p <= r) {
        int i = p - 1;
        for (int j = p; j < r; ++j) {
            if (a[j] <= a[r]) {
                ++i;
                std::swap(a[i], a[j]);
            }
        }
        std::swap(a[++i], a[r]);
        return i;
    }
}

int randomized_partition(std::vector<int> &a, int p, int r) {
    int s = (r + p)/2;    // 此步骤模拟随机采样过程 random sampling
    std::swap(a[s], a[r]);
    return partition(a, p, r);
}

int randomized_select(std::vector<int> &a, int p, int r, int i) {
    if (p == r)
        return a[p];
    int q = randomized_partition(a, p, r);
    int k = q - p + 1;
    if (k == i)
        return a[q];
    else if (i < k)
        return randomized_select(a, p, q-1, i);
    else
        return randomized_select(a, q+1, r, i-k);
}
