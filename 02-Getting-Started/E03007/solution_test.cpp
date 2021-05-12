#include "solution.hpp"

#include <gtest/gtest.h>

TEST(E03007, basic)
{
    struct Case {
        std::vector<int> array;
        int              sum;
        bool             expect;
    };

    std::vector<Case> cases{{{2, 3, 6, 1, 5}, 1, false},
                            {{2, 3, 6, 1, 5}, 2, false},
                            {{2, 3, 6, 1, 5}, 3, true},
                            {{2, 3, 6, 1, 5}, 4, true},
                            {{2, 3, 6, 1, 5}, 5, true},
                            {{2, 3, 6, 1, 5}, 6, true},
                            {{2, 3, 6, 1, 5}, 7, true},
                            {{2, 3, 6, 1, 5}, 8, true},
                            {{2, 3, 6, 1, 5}, 9, true},
                            {{2, 3, 6, 1, 5}, 10, false},
                            {{2, 3, 6, 1, 5}, 11, true},
                            {{2, 3, 6, 1, 5}, 12, false},
                            {{2, 3, 6, 1, 5}, 13, false}};

    for (auto& c : cases) {
        bool result = has_sum(c.array, c.sum);
        EXPECT_EQ(result, c.expect);
    }
}