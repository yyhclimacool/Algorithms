/*
 * SELECTION-SORT psudo-code:
 * for j = 1 to A.length - 1
 *     min_idx = j
 *     for i = j + 1 to A.length
 *         if A[i] < A[min_idx]
 *             min_idx = i
 *     swap(A[j], A[min_idx]
 */

#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &lhs) {
	auto n = lhs.size();
	if (n == 0) return;
	for (size_t j = 0; j < n - 1; ++j) {
		size_t min_idx = j;
		for (size_t i = j + 1; i < n; ++i)
			if (lhs[i] < lhs[min_idx])
				min_idx = i;
		std::swap(lhs[j], lhs[min_idx]);
	}
}

int main()
{
	std::vector<int> ivec = { 5,2,4,6,1,3,8,13,0,34,62,99,7 };
	selection_sort(ivec);
	for (const auto &e : ivec)
		std::cout << e << " ";
	std::cout << std::endl;
	return 0;
}
