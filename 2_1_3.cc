#include <iostream>
#include <vector>

std::vector<int> add_bits(std::vector<int> &lhs, std::vector<int> &rhs) {
	if (lhs.size() != rhs.size())
		return std::vector<int>();
	int n = lhs.size();
	std::vector<int> res(n + 1, 0);
	for (int j = n - 1; j >= 0; --j) {
		res[j + 1] = res[j + 1] + lhs[j] + rhs[j];
		if (res[j + 1] >= 2) {
			res[j + 1] %= 2;
			res[j] = 1;
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	std::vector<int> lhs = { 1,1,0,0,1,0,1,0,0 };
	std::vector<int> rhs = { 0,0,0,1,1,1,1,0,1 };
	auto result = add_bits(rhs, lhs);
	for (const auto &e : result)
		std::cout << e << " ";
	std::cout << std::endl;
    return 0;
}
