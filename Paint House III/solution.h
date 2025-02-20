#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <span>
#include "absl/log/check.h"

// Returns a vector where each index [i] is the number of different nodes that
// you can visit if you perform the process starting from some node [i].
// Count Visited Nodes in a Directed Graph ( LeetCode 2876 )
int CostToPaintNeighborhood(std::span<const int> cost, std::span<const int> houses, int m, int n, int target);

#endif  // SOLUTION_H    