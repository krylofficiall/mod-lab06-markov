// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(test1, pref) {
  TextGen textgen;
  std::string words = "Fresh red Apple";
  prefix pref = {"Fresh", "red"};
  textgen.create_tab(words, 2);
  EXPECT_EQ(textgen.tab_state.find(pref),
  textgen.statetab.end());
}

TEST(test3, suf) {
    std::string words = "Fresh red apple";
    TextGen textgen;
    textgen.create_tab(words, 1);
    EXPECT_EQ(textgen.generate(5, 50), "Fresh Freshred");
}

TEST(test4, chooseSuf) {
    std::string words = "Fresh red apple, Fresh red banana, Fresh red qiwi";
    TextGen textgen;
    textgen.create_tab(words, 2);
    EXPECT_EQ(textgen.generate(9, 100), "Fresh Freshred Freshred");
}

TEST(test5, text) {
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string> > state = {
        { { "d" }, { "D", "d" } },
        { { "e" }, { "E", "e" } },
        { {"f"}, {"F"} }
    };
    TextGen textgen;
    typedef std::deque<std::string> prefix;
    prefix pref{ "d" };
    textgen.tab_state = state;
    textgen.f = pref;
    EXPECT_EQ(textgen.generate(10, 10), "d D ");
}
