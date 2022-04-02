#include "blind.h"
#include "gameboard.h"

using namespace std;

Blind::Blind(Board *board) : Effects{board} {}

void Blind::add_effect(Gameboard &g) {
	board->add_effect(g);
}

Blind::~Blind() {}
