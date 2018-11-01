#include "counting_sort.h"

void counting_sort(const std::vector<int> &ivec, std::vector<int> &outvec, int k) {
    std::vector<int> counting_vec(k+1, 0); 
    outvec.clear();
    outvec.resize(ivec.size());
    for(size_t i = 0; i < ivec.size(); ++i)
        ++counting_vec[ivec[i]]; 

    for (size_t i = 1; i <= k; ++i)
        counting_vec[i] = counting_vec[i] + counting_vec[i-1];

    for (int i = ivec.size()-1; i >= 0; --i) {
        outvec[counting_vec[ivec[i]] - 1] = ivec[i];
        --counting_vec[ivec[i]];
    }   
}
