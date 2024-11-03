#include "solution.h"

int Solution::ladderLength(std::string beginWord, std::string endWord,
                           std::vector<std::string>& wordList) {
  /*Find shortest sequence to reach endWord -> Graph problem
    Shortest path is guaranteed by BFS. DFS would also find a path, but does not
    guarantee the shortest path.
    Time: O(N * M^2) Space: O(N * M^2), where N - words in wordList,
    M - length of words in wordList M^2 comes from finding all possible 
    1 letter changes in a word, and then we need to store them in hashMap */

  // Base case: endWord is NOT in wordList
  if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
    return 0;
  }

  // Create hashMap to store possible paths for every letter change for each word
  std::unordered_map<std::string, std::vector<std::string> > neighborsMap;
  int WORD_LEN = beginWord.length();  // words are of equal length

  // Go through each word and create store possible combinations
  // associated with a given word
  // E.g neighborsMap[h*t] = {hot, hit}
  for (std::string word : wordList) {
    for (int i = 0; i < WORD_LEN; ++i) {
      std::string pattern =
          word.substr(0, i) + '*' + word.substr(i + 1, WORD_LEN);
      neighborsMap[pattern].push_back(word);
    }
  }

  // Run BFS on neighborsMap. If we reached the word, return result
  // If can't, while-loop will eventually run out of element in queue and return 0
  int result = 1;
  std::set<std::string> visited;
  std::deque<std::string> queue;
  queue.push_back(beginWord);
  visited.insert(beginWord);

  // Explore Graph layer by layer, increment result after each layer got
  // processed
  while (!queue.empty()) {
    int queueSize = queue.size();
    for (int i = 0; i < queueSize; ++i) {
      std::string word = queue.front();
      queue.pop_front();
      // Reached the endWord?
      if (word == endWord) {
        return result;
      }

      // Given combinations, see where we can go and only go through elements
      // That we haven't added to visited set yet
      for (int j = 0; j < WORD_LEN; ++j) {
        std::string pattern =
            word.substr(0, j) + '*' + word.substr(j + 1, WORD_LEN);
        for (std::string neighbor : neighborsMap[pattern]) {
          if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            queue.push_back(neighbor);
          }
        }
      }
    }
    ++result;
  }

  // Haven't found a path to endWord
  return 0;
}