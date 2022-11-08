#include "AIGame.h"


AIGame::AIGame() {
    this->seed_int_ = (int) time(nullptr);
    this->rand_generator = std::minstd_rand(this->seed_int_);
}

AIGame::~AIGame() = default;

void AIGame::setSeed(int seed) {
    this->seed_int_ = seed;
    rand_generator = std::minstd_rand(this->seed_int_);
}

int AIGame::generate_random_num() {
    // random num range
    std::uniform_int_distribution<int> distribution{0, 2};
    // generate random num
    int res = distribution(rand_generator);
    return res;
}

bool AIGame::isValid(std::string &input, std::set<std::string> &rule) {
    // transform player's input into upper style
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    // remove useless character
    input.erase(std::remove_if(input.begin(), input.end(),
                               [](char n) { return (n < 'A' || n > 'Z'); }), input.end());
    return rule.count(input) != 0;
}

int AIGame::ValidInput(std::string &player_choose) {
    if (!isValid(player_choose, this->input_rule_)) {
        return -1;
    }
    return this->rule_[player_choose];
}

int AIGame::WinOrLoss(int player_choose, int computer_choose) {
    //get which computer choose
    std::string computer_choose_str = standard_rule_[computer_choose];

    //judge who wins
    std::cout << "The ai played " << computer_choose_str << "." << std::endl;

    if (player_choose == computer_choose) {
        //tie
        std::cout << "You and the AI both played " << computer_choose_str << std::endl;
        return 0;
    }
    if (player_choose - computer_choose == 1 || player_choose - computer_choose == -2) {
        //player win
        std::cout << "You win!" << std::endl;
        return 1;
    } else {
        //player lose
        std::cout << "The AI wins :(" << std::endl;
        return -1;
    }
}

void AIGame::playgame() {
    std::string enter_intro = "Enter (R)ock, (P)aper, or (S)cissors for your move: ";
    std::string replay_game_str = "Would you like to replay the game?";
    std::string replay_game_intro = "Enter (Y)es or (N)o: ";
    std::string tie_replay_message = "Keep playing util someone wins.";

    std::string input_str;
    int player_choose;

    while (true) {
        do {
            std::cout << enter_intro;
            getline(std::cin, input_str);
            player_choose = this->ValidInput(input_str);
        } while (player_choose == -1);//-1 represent invalid

        int computer_choose = generate_random_num();
        int play_res = this->WinOrLoss(player_choose, computer_choose);
        if (play_res != 0) {
            std::string replay_message;
            while (true) {
                std::cout << replay_game_str << std::endl;
                std::cout << replay_game_intro;
                getline(std::cin, replay_message);
                if (!isValid(replay_message, replay_info_)) {
                    std::cout << "invalid replay input" << std::endl;
                    continue;
                }
                break;
            }

            if (replay_message[0] == 'Y') {
                //replay
                continue;
            } else {
                //not replay
                break;
            }
        } else {
            //tie
            std::cout << tie_replay_message << std::endl;
            continue;
        }
    }
}
