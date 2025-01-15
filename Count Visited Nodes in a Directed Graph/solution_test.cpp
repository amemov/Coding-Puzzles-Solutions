#include "solution.h"

#include <gtest/gtest.h>

// Small input - from LeetCode
TEST(visited_nodes_test, small_input_0) {
  EXPECT_EQ(CountVisitedNodes({1, 2, 0, 0}), std::vector<int>({3, 3, 3, 4}));
}

// Antother small input - from LeetCode
TEST(visited_nodes_test, small_input_1) {
  EXPECT_EQ(CountVisitedNodes({1, 2, 3, 4, 0}),
            std::vector<int>({5, 5, 5, 5, 5}));
}

// Some good input
TEST(visited_nodes_test, good_input) {
  EXPECT_EQ(CountVisitedNodes({8,  17, 14, 8, 14, 12, 16, 11, 4, 14,
                               19, 6,  8,  8, 2,  10, 2,  1,  1, 18}),
            std::vector<int>(
                {5, 2, 2, 5, 3, 6, 4, 6, 4, 3, 5, 5, 5, 5, 2, 6, 3, 2, 3, 4}));
}

// Some input that doesn't pass
// TEST(visited_nodes_test , wrong_input) {
//  EXPECT_EQ(CountVisitedNodes(), 0);
//}
