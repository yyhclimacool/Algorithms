#ifndef _RANDOMIZED_SELECT
#define _RANDOMIZED_SELECT

#include <vector>

int partition(std::vector<int> &a, int p, int r);

int randomized_partition(std::vector<int> &a, int p, int r);

int randomized_select(std::vector<int> &a, int p, int r, int i);

#endif // _RANDOMIZED_SELECT
