#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

std::tuple<int, int, int> find_max_subarray(const std::vector<int> &ivec) {
	auto sz = ivec.size();
	int maxsum = 0;
	int left = 0, right = 0;
	for (int i = 0; i < sz; ++i) {
		int sum = 0;
		for (int j = i; j < sz; ++j) {
			sum += ivec[j];
			if (sum > maxsum) {
				maxsum = sum;
				left = i;
				right = j;
			}
		}
	}
	return std::make_tuple(left, right, maxsum);
}

std::tuple<int, int, int> find_max_subarray_dp(const std::vector<int> &ivec) {
	int low = 0;
	int high = 0;
	int this_sum = 0;
	int max_sum = 0;
	int sz = ivec.size();
	for (int i = 0; i < sz; ++i) {
		this_sum += ivec[i];
		if (this_sum > max_sum) {
			max_sum = this_sum;
			high = i;
		}
		else if (this_sum < 0) {
			this_sum = 0;
			low = i + 1;
		}
	}
	return std::make_tuple(low, high, max_sum);
}

int main()
{
	std::vector<int> ivec = { 0,13,-3,25,40,-3,-16,-23,18,20,-8,12,-5,-22,15,-4,7 };
	auto ret = find_max_subarray(ivec);
	std::cout << "low : " << std::get<0>(ret) << ", high : " << std::get<1>(ret) << ", Maximum subarray : " << std::get<2>(ret) << std::endl;
	ret = find_max_subarray_dp(ivec);
	std::cout << "low : " << std::get<0>(ret) << ", high : " << std::get<1>(ret) << ", Maximum subarray : " << std::get<2>(ret) << std::endl;
	return 0;
}
