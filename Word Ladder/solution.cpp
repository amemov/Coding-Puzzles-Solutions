#include "solution.h"

int LadderLength(std::string_view begin_word, std::string_view end_word,
                 const std::vector<std::string>& word_list) {
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

  // Base case: begin_word and end_word lengths do not match
  CHECK_EQ(end_word.length(), begin_word.length())
      << "Lengths of begin_word and end_word DO NOT MATCH";

  // Create hashMap to store possible paths for every letter change
  // for each word
  size_t word_len = begin_word.length();  // words are of equal length
  absl::flat_hash_map<std::string, std::vector<std::string> > neighbors_map;

  // Pass word and index which to modify with '*'.
  // Returns pattern. E.g ("hot", 1) -> "h*t"
  auto generate_pattern = [](std::string word, size_t i) {
    word[i] = '*';
    return word;
  };

  // Go through each word. Generate and map possible patterns
  // associated with a given word
  // E.g word = "hot" => neighbors_map[h*t] = {hot, ...}
  for (auto& word : word_list) {
    for (size_t i = 0; i < word_len; ++i) {
      std::string pattern = generate_pattern(word, i);
      neighbors_map[pattern].push_back(word);
    }
  }

  // Run BFS on neighbors_map. If we reached the word, return shortest_path
  // If can't, while-loop will eventually run out of element in words_queue
  // and return 0
  int shortest_path = 1;
  absl::flat_hash_set<std::string> visited_set;
  std::deque<std::string> words_queue;
  words_queue.push_back(static_cast<std::string>(begin_word));
  visited_set.insert(static_cast<std::string>(begin_word));

  // Explore Graph level by level,
  // increment shortest_path after each level got processed
  while (!words_queue.empty()) {
    size_t queue_size = words_queue.size();

    for (size_t i = 0; i < queue_size; ++i) {
      std::string current_word = words_queue.front();
      words_queue.pop_front();

      if (current_word == end_word) {
        return shortest_path;
      }

      // Given combinations, see where we can go and only go through elements
      // That we haven't added to visited_set yet
      for (size_t j = 0; j < word_len; ++j) {
        std::string pattern = generate_pattern(current_word, j);

        for (const auto& neighbor_word : neighbors_map[pattern]) {
          if (!visited_set.contains(neighbor_word)) {
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