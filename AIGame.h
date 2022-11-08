#ifndef AI_GAME_AIGAME_H
#define AI_GAME_AIGAME_H

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <unordered_map>
#include <set>
#include <algorithm>

struct KeyValue {
    std::string key;
    int value;
};

class AIGame {
public:
    AIGame();

    ~AIGame();

    void setSeed(int seed);

    int generate_random_num();

    void playgame();

    int WinOrLoss(int player_choose, int computer_choose);

    static bool isValid(std::string &input, std::set<std::string> &rule);

    int ValidInput(std::string &player_choose);

    std::unordered_map<std::string, int> rule_ = {{"ROCK",     0},
                                                  {"R",        0},
                                                  {"PAPER",    1},
                                                  {"P",        1},
                                                  {"SCISSORS", 2},
                                                  {"S",        2}};
    std::vector<std::string> standard_rule_{"rock", "paper", "scissors"};
    std::set<std::string> input_rule_{"ROCK", "R", "PAPER", "P", "SCISSORS", "S"};
    std::set<std::string> replay_info_{"YES", "Y", "NO", "N"};

private:
    int seed_int_;
    std::minstd_rand rand_generator;
};


#endif //AI_GAME_AIGAME_H
