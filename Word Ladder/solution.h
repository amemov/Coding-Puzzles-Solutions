#ifndef SOLUTION_H
#define SOLUTION_H

#include <set>
#include <deque>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"

// This function return the number of words in the shortest transformation 
// sequence from begin_word to end_word. Returns 0 if no such sequence.
// Word Ladder Problem (LeetCode 127)
int LadderLength(std::string begin_word, std::string end_word,
                 std::vector<std::string>& word_list);

#endif  // SOLUTION_H
