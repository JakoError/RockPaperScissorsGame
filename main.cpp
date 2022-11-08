#include <iostream>
#include <memory>
#include <unordered_map>
#include <map>
#include "AIGame.h"
#include <algorithm>

int main(int argc, char **argv) {

    std::shared_ptr<AIGame> aiGame = std::make_shared<AIGame>();
    if (argc > 1) {
        aiGame->setSeed((int) strtol(argv[1], nullptr, 10));
    }
    aiGame->playgame();
    return 0;
}
