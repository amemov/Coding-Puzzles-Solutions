#ifndef SOLUTION_H
#define SOLUTION_H

#include <deque>
#include <set>
#include <string>
#include <vector>
class Solution {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList);
};

#endif  // SOLUTION_H