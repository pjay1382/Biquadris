#include "blind.h"
#include "board.h"

using namespace std;

Blind::Blind(Board *board) : Effects{board} {}

void Effect::add_effect(Gameboard &g) {
	board->add_effect(g);
}

Blind::~Blind() {}
