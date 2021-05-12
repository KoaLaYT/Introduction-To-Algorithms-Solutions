#include "solution.hpp"
#include <algorithm>

bool has_sum(std::vector<int> array, int sum)
{
    std::sort(array.begin(), array.end());

    for (auto it = array.begin(); it != array.end(); ++it) {
        int  target = sum - *it;
        auto found = target <= *it
                         ? std::binary_search(array.begin(), it, target)
                         : std::binary_search(it + 1, array.end(), target);
        if (found) return true;
    }

    return false;
}