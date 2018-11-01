#include <vector>
#include <iostream>

int count_in_area(const std::vector<int> &ivec, int k, \
    int a /* including */, int b /* including */) {  

    std::vector<int> counting_vec(k+1, 0);

    for (size_t i = 0; i < ivec.size(); ++i) 
        ++counting_vec[ivec[i]];

    for (size_t i = 1; i <= k; ++i)
        counting_vec[i] = counting_vec[i] + counting_vec[i-1];

    // a is smaller than b
    if (a == 0)
        return counting_vec[b];
    else
        return counting_vec[b] - counting_vec[a-1];
}

int main() {
    std::vector<int> ivec = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};

    std::cout << "[0, 1] : " << count_in_area(ivec, 6, 0, 1) << std::endl;
    std::cout << "[0, 5] : " << count_in_area(ivec, 6, 0, 5) << std::endl;
    std::cout << "[3, 6] : " << count_in_area(ivec, 6, 3, 6) << std::endl;
    std::cout << "[6, 6] : " << count_in_area(ivec, 6, 6, 6) << std::endl;

    return 0;
}
