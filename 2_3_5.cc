
#include <iostream>
#include <vector>

int bin_search(std::vector<int> &ivec, int ival) {
	if (ivec.empty())
		return -1;
	int low = 0;
	int high = ivec.size() - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ivec[mid] == ival)
			return mid;
		else if (ivec[mid] > ival)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low > high)
		return -1;
}

int main(int argc, char *argv[])
{
	std::vector<int> ivec = { 3,5,7,8,9,12,23,53,56,67,97 };
	int res = bin_search(ivec, 7);
	if (res != -1)
		std::cout << "found 7" << std::endl;
	else
		std::cout << "7 not found" << std::endl;
    return 0;
}
