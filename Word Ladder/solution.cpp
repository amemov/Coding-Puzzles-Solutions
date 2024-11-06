#include "solution.h"

int LadderLength(std::string begin_word, std::string end_word,
                 std::vector<std::string>& word_list) {
  // Find shortest sequence to reach end_word -> Graph problem
  // Shortest path is guaranteed by BFS. DFS would also find a path, but does
  // not guarantee the shortest path. Time: O(N * M^2) Space: O(N * M^2), where
  // N - words in word_list, M - length of words in word_list M^2 comes from
  // finding all possible 1 letter changes in a word, and then we need to store
  // them in neighbors_map (hash map)

  // Base case: end_word is NOT in word_list
  if (find(word_list.begin(), word_list.end(), end_word) == word_list.end()) {
    return 0;
  }

  // Create hashMap to store possible paths for every letter change
  // for each word
  absl::flat_hash_map<std::string, std::vector<std::string> > neighbors_map;
  int word_len = begin_word.length();  // words are of equal length

  // Go through each word and create store possible patterns
  // associated with a given word
  // E.g neighbors_map[h*t] = {hot, hit}
  for (std::string word_ : word_list) {
    for (int i = 0; i < word_len; ++i) {
      std::string pattern_ =
          word_.substr(0, i) + '*' + word_.substr(i + 1, word_len);
      neighbors_map[pattern_].push_back(word_);
    }
  }

  // Run BFS on neighbors_map. If we reached the word, return shortest_path
  // If can't, while-loop will eventually run out of element in words_queue 
  // and return 0
  int shortest_path = 1;
  std::set<std::string> visited_set;
  std::deque<std::string> words_queue;
  words_queue.push_back(begin_word);
  visited_set.insert(begin_word);

  // Explore Graph level by level, 
  // increment shortest_path after each level got processed
  while (!words_queue.empty()) {
    size_t queue_size = words_queue.size();
    
    for (int i = 0; i < queue_size; ++i) {
      std::string current_word = words_queue.front();
      words_queue.pop_front();
      
      if (current_word == end_word) {
        return shortest_path;
      }

      // Given combinations, see where we can go and only go through elements
      // That we haven't added to visited_set yet
      for (int j = 0; j < word_len; ++j) {
        std::string pattern_ =
            current_word.substr(0, j) + '*' + current_word.substr(j + 1, word_len);
        
        for (std::string neighbor_word : neighbors_map[pattern_]) {
          if (visited_set.find(neighbor_word) == visited_set.end()) {
            visited_set.insert(neighbor_word);
            words_queue.push_back(neighbor_word);
          }
        }
      }
    }
    ++shortest_path;
  }

  // Haven't found a path to end_word
  return 0;
}