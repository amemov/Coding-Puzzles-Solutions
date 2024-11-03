#include "solution.h"

#include <gtest/gtest.h>

// Small input - from LeetCode
TEST(ladderLenTest, smallInput) {
  Solution obj;
  std::string beginWord = "hit";
  std::string endWord = "cog";
  std::vector<std::string> wordList = {"hot", "dot", "dog",
                                       "lot", "log", "cog"};

  EXPECT_EQ(obj.ladderLength(beginWord, endWord, wordList), 5);
}

// Big input - generated with dcode.fr/word-letter-change
TEST(ladderLenTest, bigInput) {
  Solution obj;
  std::string beginWord = "aard";
  std::string endWord = "ware";
  std::vector<std::string> wordList = {
      "aare", "bare", "care", "dare", "eare", "fare", "gare", "hare", "kare",
      "lare", "mare", "nare", "oare", "pare", "rabe", "race", "rade", "rafe",
      "rage", "rahe", "rake", "rale", "rame", "rane", "rape", "rara", "rarf",
      "rari", "rark", "raro", "rarp", "rars", "rase", "rate", "rave", "rawe",
      "raye", "raze", "rere", "rore", "sare", "tare", "vare", "ware", "yare"};

  EXPECT_EQ(obj.ladderLength(beginWord, endWord, wordList), 3);
}

// Some silly input from gpt
TEST(ladderLenTest, sillyInput) {
  Solution obj;
  std::string beginWord = "stone";
  std::string endWord = "money";
  std::vector<std::string> wordList = {
      "stony", "store", "score", "scone", "shone", "phone", "phony", "money",
      "stone", "stoke", "smoke", "smote", "motel", "model", "moody", "honey"};
  
  EXPECT_EQ(obj.ladderLength(beginWord, endWord, wordList), 0);
}

// Main function to run all tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}