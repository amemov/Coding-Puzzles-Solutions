#ifndef SOLUTION_H
#define SOLUTION_H

#include <limits>
#include <span>
#include <vector>

#include "absl/log/check.h"

// Returns a vector where each index [i] is the number of different nodes that
// you can visit if you perform the process starting from some node [i].
// Count Visited Nodes in a Directed Graph ( LeetCode 2876 )
std::vector<int> CountVisitedNodes(std::span<const int> edges);

#endif  // SOLUTION_H   