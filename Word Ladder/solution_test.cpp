#include "solution.h"

#include <gtest/gtest.h>

// Small input - from LeetCode
TEST(ladder_len_test, small_input) {
  std::string_view begin_word = "hit";
  std::string_view end_word = "cog";
  std::vector<std::string> word_list = {"hot", "dot", "dog",
                                        "lot", "log", "cog"};

  EXPECT_EQ(LadderLength(begin_word, end_word, word_list), 5);
}

// Big input - generated with dcode.fr/word-letter-change
TEST(ladder_len_test, big_input) {
  std::string_view begin_word = "aard";
  std::string_view end_word = "ware";
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
  std::string_view begin_word = "stone";
  std::string_view end_word = "money";
  std::vector<std::string> word_list = {
      "stony", "store", "score", "scone", "shone", "phone", "phony", "money",
      "stone", "stoke", "smoke", "smote", "motel", "model", "moody", "honey"};

  EXPECT_EQ(LadderLength(begin_word, end_word, word_list), 0);
}

// Checks if program aborts on invalid end/begin_word during CHECK_EQ
TEST(ladder_len_test, wrong_input) {
  std::string_view begin_word = "ston";
  std::string_view end_word = "money";
  std::vector<std::string> word_list = {
      "stony", "store", "score", "scone", "shone", "phone", "phony", "money",
      "stone", "stoke", "smoke", "smote", "motel", "model", "moody", "honey"};

  ASSERT_DEATH({ LadderLength(begin_word, end_word, word_list); }, "");
}
