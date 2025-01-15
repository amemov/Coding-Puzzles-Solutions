#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

#include "absl/container/flat_hash_set.h"
#include "absl/log/absl_check.h"

// This function return the number of ways to nodes it is possible to visit from
// given node in graph until the cycle is found. The graph 'edges' is defined as
// vector (0 indexed), where edges[i] indicates that there is an edge from node
// i to node edges[i]. Count Visited Nodes in a Directed Graph ( LeetCode 2876 )
std::vector<int> CountVisitedNodes(const std::vector<int>& edges);

#endif  // SOLUTION_H