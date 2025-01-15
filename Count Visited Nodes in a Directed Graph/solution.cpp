#include "solution.h"
std::vector<int> CountVisitedNodes(const std::vector<int>& edges) {
  std::vector<int> visited_count(edges.size(), -1);  // result
  absl::flat_hash_set<size_t> path;
  std::vector<size_t> path_stack;

  // Idea: run DFS on graph starting from index some index (assuming it is
  // holding sentinel value -1) go until
  //       We face either of 2 cases:
  //          1. "First-time" cycle -> all nodes that led to the cycle get
  //          updated to the the number of nodes in path
  //          2. Found node that was part of cycle -> we update all nodes
  //                  in the path with (current number of nodes + value of
  //                  previously computed cycle that we just faced)
  //             OR maybe we should somehow get to the element on top of path
  //             and just get element from top,
  //                give it this value, then deduct this counter by -1 and give
  //                this value to next vertex, and so on?
  // Logic: We run from 0 and we go until we face either of 2 cases
  //        OR if problem constaint didn't say that there is at least 1 cycle,
  //           worst-case our graph is just a linked list w/o cycle.
  //        We only consider nodes that are still set to sentinel value of -1.
  // Complexity: Time O(n), since the graph has at least 1 cycle. With help of
  // the DP, we can reduce redundant calculations,
  //             therefore, we only visit each node just once
  //             It could be O(n^2) if the graph could have 0 cycles because of
  //             case where we can have linked list, where first pass is n, next
  //             is n-1, ..., and therefore we get quadratic time complexity
  //             Space O(1), because we only allocate the space for result
  //             variable and the graph is technically defined
  //                         in the edges variable. 'path' variable in worst
  //                         case might take O(n) which doesn't surpass the
  //                         amount of space that we allocate for
  //                         'visited_count'
  for (size_t i = 0; i < edges.size(); ++i) {
    if (visited_count[i] == -1) {
      // path.insert(i);
      size_t node = i;

      // goes until cycle or end of graph (no cycle)
      while (path.find(node) == path.end() && visited_count[node] == -1) {
        path.insert(node);
        path_stack.push_back(node);
        node = edges[node];
      }

      // Cycle found. Is it case #1 where we see cycle for 1st time?
      if (visited_count[node] == -1) {
        // upd visited_count for all elements in path with path.size
        int counter = path.size();
        for (const auto& vertex : path) {
          // if(visited_count[vertex] == -1){
          visited_count[vertex] = counter;
          //}
        }
        // #2 we found previously computed cycle
      } else {
        // upd everything in the path with path.size + visited_count[node]
        int counter = path.size() + visited_count[node];
        size_t vertex = path_stack.front();
        visited_count[vertex] = counter;
      }

      path.clear();
      path_stack.clear();
    }
  }

  return visited_count;
}