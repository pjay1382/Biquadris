#include "heavy.h"
#include "board.h"

using namespace std;

Heavy::Heavy(Board *board) : Effects{board} {}

void Heavy::add_effect(Gameboard &g) {
	board->add_effect(g);
	
	if (g.getSetHeavy()) {
		g.getCur()->getSetHeavy(1);
	}
}

Heavy::~Heavy() {}