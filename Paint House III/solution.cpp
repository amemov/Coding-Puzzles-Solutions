#include "solution.h"
std::vector<int> CountVisitedNodes(std::span<const int> edges) {
  constexpr int kSentinel = std::numeric_limits<int>::min();
  std::vector<int> visited_count(edges.size(), kSentinel);  // result
  std::vector<int> path(edges.size(), kSentinel);

  // Idea: run DFS on graph starting from index some index (assuming it is
  // holding sentinel value 'kSentinel') go until
  //       We face either of 1 or 2 cases:
  //          1. Cycle -> all nodes inside the cycle are assigned to the length
  //          of cycle
  //          2. No Cycle or was cycle before - doesn't matter, still need to go
  //          back and update each node that we visited with the value of last
  //          element from path + 1
  //
  // Complexity: Time O(n), since the graph has at least 1 cycle. With help of
  //             the DP, we can reduce redundant calculations,t herefore,
  //             we only visit each node just once.
  //             It could be O(n^2) if the graph could have 0 cycles because of
  //             case where we can have linked list, where first pass is n, next
  //             is n-1, ..., and therefore we get quadratic time complexity
  //
  //             Space O(1), because we only allocate the space for result
  //             variable and the graph is technically defined
  //             in the edges variable. 'path' variable in worst
  //             case might take O(n) which doesn't surpass the
  //             amount of space that we allocate for 'visited_count'

  for (size_t i = 0; i < edges.size(); ++i) {
    if (visited_count[i] != kSentinel) {
      continue;
    }

    size_t node = i;
    std::vector<size_t> stack;

    // goes until cycle or end of graph (no cycle)
    while (visited_count[node] == kSentinel && path[node] == kSentinel) {
      // size of stack corresponds to the curr index
      path[node] = stack.size();
      stack.push_back(node);
      // verify the node is not negative
      CHECK(edges[node] >= 0) << "CountVisitedNodes: Negative node in the "
                                 "graph detected. Node value: "
                              << edges[node];
      node = edges[node];
    }

    // #1 Found a new cycle
    if (visited_count[node] == kSentinel) {
      size_t cycle_length = stack.size() - path[node];
      for (size_t j = path[node]; j < stack.size(); ++j) {
        visited_count[stack[j]] = cycle_length;
      }
    }

    // #2 No cycle? But still need to backtrack and fill out visited_count for
    // each node that we visited
    while (!stack.empty()) {
      size_t v = stack.back();
      stack.pop_back();
      if (visited_count[v] == kSentinel) {
        visited_count[v] = visited_count[edges[v]] + 1;
      }
    }
  }

  return visited_count;
}