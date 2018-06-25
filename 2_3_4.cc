/*
 * INSERTION_SORT recursive version
 * 
 * // for j = 2 to A.length
 * //    key = A[j]
 * //    // insert A[j] to sorted A[1..j-1]
 * //    i = j - 1
 * //    while i > 0 and A[i] > key
 * //        A[i+1] = A[i]
 * //        ++i
 * //    A[i+1] = key
 *
 *
 * insertion_recursive_sort(A, n)
 *     if n == 1
 *         return
 *     insertion_recursive_sort(A, n-1)
 *     key = A[n]
 *     i = n-1
 *     while i > 0 and A[i] > key
 *         A[i+1] = A[i]
 *         ++i
 *     A[i+1] = key
 *
 *         / c            n = 1
 * T(n) = <
 *         \ T(n-1) + cn  other
 */

#include <iostream>
#include <vector>

void insertion_recursive_sort(std::vector<int> &arr, std::vector<int>::size_type n) {
    if (n == 1)
    	return;
    insertion_recursive_sort(arr, n-1);
    auto key = arr[n-1];
    auto i = n-2;
    while (i > 0 && arr[i] > key) {
    	arr[i+1] = arr[i];
    	--i;
    }
    arr[i+1] = key;
}


int main(int argc, char *argv[]) {
	std::vector<int> ivec {3,5,2,7,5,9,3,4,2,10,8};
	insertion_recursive_sort(ivec, ivec.size());
	for (const auto &e : ivec)
		std::cout << e << " " ;
	std::cout << std::endl;
	return 0;
}
