#include "solution.h"

#include <gtest/gtest.h>

// Small input - from LeetCode
TEST(ladder_len_test, small_input) {
  std::string begin_word = "hit";
  std::string end_word = "cog";
  std::vector<std::string> word_list = {"hot", "dot", "dog",
                                        "lot", "log", "cog"};

  EXPECT_EQ(LadderLength(begin_word, end_word, word_list), 5);
}

// Big input - generated with dcode.fr/word-letter-change
TEST(ladder_len_test, big_input) {
  std::string begin_word = "aard";
  std::string end_word = "ware";
  std::vector<std::string> word_list = {
      "aare", "bare", "care", "dare", "eare", "fare", "gare", "hare", "kare",
      "lare", "mare", "nare", "oare", "pare", "rabe", "race", "rade", "rafe",
      "rage", "rahe", "rake", "rale", "rame", "rane", "rape", "rara", "rarf",
      "rari", "rark", "raro", "rarp", "rars", "rase", "rate", "rave", "rawe",
      "raye", "raze", "rere", "rore", "sare", "tare", "vare", "ware", "yare"};

  EXPECT_EQ(LadderLength(begin_word, end_word, word_list), 3);
}

// Some silly input from gpt
TEST(ladder_len_test, silly_input) {
  std::string begin_word = "stone";
  std::string end_word = "money";
  std::vector<std::string> word_list = {
      "stony", "store", "score", "scone", "shone", "phone", "phony", "money",
      "stone", "stoke", "smoke", "smote", "motel", "model", "moody", "honey"};

  EXPECT_EQ(LadderLength(begin_word, end_word, word_list), 0);
}

// Main function to run all tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}