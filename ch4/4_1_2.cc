#include <iostream>
#include <vector>
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

int main()
{
	std::vector<int> ivec = { 0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	auto ret = find_max_subarray(ivec);
	std::cout << "low : " << std::get<0>(ret) << ", high : " << std::get<1>(ret) << ", Maximum subarray : " << std::get<2>(ret) << std::endl;
	return 0;
}
