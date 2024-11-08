#ifndef SOLUTION_H
#define SOLUTION_H

#include <glog/logging.h>

#include <deque>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"

// This function return the number of words in the shortest transformation
// sequence from begin_word to end_word. Traverses word_list to construct the
// graph and then finds a shortest path from begin_word to end_word. Returns 0
// if no such sequence exists. Word Ladder Problem (LeetCode 127)
int LadderLength(std::string_view begin_word, std::string_view end_word,
                 const std::vector<std::string>& word_list);

#endif  // SOLUTION_H
