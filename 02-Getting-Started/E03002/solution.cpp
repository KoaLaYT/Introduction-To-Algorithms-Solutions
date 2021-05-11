#include "solution.hpp"

namespace impl {
void merge(std::vector<int>& array, int lo, int mi, int hi)
{
    auto it_lo = array.begin();
    auto it_mi = array.begin();
    auto it_hi = array.begin();
    std::advance(it_lo, lo);
    std::advance(it_mi, mi + 1);
    std::advance(it_hi, hi + 1);

    std::vector<int> left{it_lo, it_mi};
    std::vector<int> right{it_mi, it_hi};

    int i = 0;
    int j = 0;
    for (int k = lo; k <= hi; ++k) {
        if (i >= left.size())
            array[k] = right[j++];
        else if (j >= right.size())
            array[k] = left[i++];
        else if (left[i] <= right[j]) {
            array[k] = left[i++];
        } else {
            array[k] = right[j++];
        }
    }
}

void merge_sort(std::vector<int>& array, int lo, int hi)
{
    if (lo >= hi) return;
    int mi = lo + (hi - lo) / 2;
    merge_sort(array, lo, mi);
    merge_sort(array, mi + 1, hi);
    merge(array, lo, mi, hi);
}

};  // namespace impl

void merge_sort(std::vector<int>& array)
{
    return impl::merge_sort(array, 0, array.size() - 1);
}