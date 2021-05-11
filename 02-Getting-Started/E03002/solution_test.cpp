#include <gtest/gtest.h>

#include <algorithm>

#include "solution.hpp"

TEST(E03002, basic)
{
    using Case = std::vector<int>;

    std::vector<Case> cases{
        {},
        {1},
        {3, 1, 5, 4},
        {1, 3, 4, 6, 8, 3, 4, 0, 2, 4, 7, 8, 4, 6, 8},
    };

    for (auto& c : cases) {
        merge_sort(c);

        EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
    }
}