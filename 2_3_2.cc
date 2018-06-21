#include <iostream>
#include <vector>

// Merge with no sentinel
void merge(std::vector<int> &arr, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> lhs(n1, 0);
	std::vector<int> rhs(n2, 0);
	int i = 0;
	int j = 0;
	for (int k = p; k <= q; ++k) {
		lhs[i] = arr[k];
		++i;
	}
	for (int k = q + 1; k <= r; ++k) {
		rhs[j] = arr[k];
		++j;
	}
	i = 0; j = 0;
	int k = 0;
	for (k = p; k <= r; ++k) {
		if (i < n1 && j < n2 && lhs[i] <= rhs[j])
			arr[k] = lhs[i++];
		else if (i < n1 && j < n2 && rhs[j] < lhs[i])
			arr[k] = rhs[j++];
		else if (i == n1 && j < n2)
			arr[k] = rhs[j++];
		else if (j == n2 && i < n1)
			arr[k] = lhs[i++];
	}
}

void merge_sort(std::vector<int> &arr, int p, int r) {
	if (p < r) {
		int middle = (p + r) / 2;
		merge_sort(arr, p, middle);
		merge_sort(arr, middle + 1, r);
		merge(arr, p, middle, r);
	}
}

int main()
{
	std::vector<int> ivec = { 5,2,4,6,1,3,8,13,0,34,62,99,7 };
	merge_sort(ivec, 0, ivec.size() - 1);
	for (const auto &e : ivec)
		std::cout << e << " ";
	std::cout << std::endl;
	return 0;
}
