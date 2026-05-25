#include <SFML/Window.hpp>
#include <cstdint>
#include <iostream>
#include <print>
#include <random>
#include <string>

#include "sudoku.hpp"

void play(Sudoku game) {
    uint32_t seed;
    std::string prompt;
    std::print("do you want to enter a seed?(y/N)");
    std::cin >> prompt;
    if (prompt == "y") {
        std::print("enter a seed: ");
        std::cin >> seed;
        // NOTE: you should validate the seed first
        game.generateSudoku(seed, 5);
        game.printBoard();
    } else {
        game.generateSudoku(20);
        game.printBoard();
    }
}

int main() {

    std::random_device r{};

    Sudoku game{};
    play(game);

    std::string prompt;
    while (true) {
        std::print("do you want to play again?(y/N)");
        std::cin >> prompt;
        if (prompt == "y") {
            play(game);
        } else
            break;
    }
}
