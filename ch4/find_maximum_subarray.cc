#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

std::tuple<int, int, int> find_maximum_cross_subarray(std::vector<int> &ivec, int low, int mid, int high) {
	int left_sum = 0;
	int left_max = INT_MIN;
	int left_idx;
	for (int i = mid; i >= low; --i) {
		left_sum += ivec[i];
		if (left_sum > left_max) {
			left_max = left_sum;
			left_idx = i;
		}
	}
	int right_sum = 0;
	int right_max = INT_MIN;
	int right_idx;
	for (int j = mid + 1; j <= high; ++j) {
		right_sum += ivec[j];
		if (right_sum > right_max) {
			right_max = right_sum;
			right_idx = j;
		}
	}
	return std::make_tuple(left_idx, right_idx, left_max + right_max);
}

std::tuple<int, int, int> find_maximum_subarray(std::vector<int> &ivec, int low, int high) {
	if (low == high)
		return std::make_tuple(low, high, ivec[low]);
	else {
		int mid = (low + high) / 2;
		auto left_ret = find_maximum_subarray(ivec, low, mid);
		auto right_ret = find_maximum_subarray(ivec, mid + 1, high);
		auto cross_ret = find_maximum_cross_subarray(ivec, low, mid, high);

		if (std::get<2>(left_ret) >= std::get<2>(right_ret) && 
			std::get<2>(left_ret) >= std::get<2>(cross_ret))
			return left_ret;
		else if (std::get<2>(right_ret) >= std::get<2>(left_ret) &&
			std::get<2>(right_ret) >= std::get<2>(cross_ret))
			return right_ret;
		else
			return cross_ret;
	}
}

int main()
{
	std::vector<int> ivec = { 0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	auto ret = find_maximum_subarray(ivec, 0, ivec.size() - 1);
	std::cout << "low : " << std::get<0>(ret) << ", high : " << std::get<1>(ret) << ", Maximum subarray : " << std::get<2>(ret) << std::endl;
	return 0;
}
