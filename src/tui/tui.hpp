#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>

#include "../types.hpp"
namespace ft = ftxui;

enum class Movement { UP, DOWN, LEFT, RIGHT };

class Tui {
public:
    Tui() {}

    void run(const BoardType& board);

private:
    void move(Movement move);
    ft::Element createMainDom(const BoardType& board);
    std::vector<ft::Elements> fillGridWithGrid(const BoardType& board);
    ft::Element createGridBox(const BoardType& board, unsigned int startingCol, unsigned int startingRow);
    std::vector<ft::Elements> fillGridCells(const BoardType& board);
    // center is (4,4)
    unsigned int m_selectedCol = 4;
    unsigned int m_selectedRow = 4;
};
