#include "effects.h"

Effects::Effects(std::shared_ptr<Board> board) : board{board} {}

void Effects::add_effect(Gameboard &g) {
        board->add_effect(g);
}


Effects::~Effects() {}
