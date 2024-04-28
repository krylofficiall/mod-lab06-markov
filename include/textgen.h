//Copyright 2024 UNN-IASR
#pragma once
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <map>

typedef std::deque<std::string> prefix;
class TextGen {
 public:
    std::map<prefix, std::vector<std::string> > tab_state;
    prefix f;
    void StateTable(
        const std::map<prefix,
        std::vector<std::string>>&);
    TextGen();
    void create_tab(const std::string& text, int number);
    std::string generate(int number, unsigned int time_num);
};
