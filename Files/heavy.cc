#include "heavy.h"
#include "gameboard.h"
#include <memory>
using namespace std;

Heavy::Heavy(shared_ptr<Board> board) : Effects{board} {}

void Heavy::add_effect(Gameboard &g) {
	board->add_effect(g);
	
	if (g.getSetHeavy(-1)) {
		g.getCur()->set_effect_heavy(1);
	}
}

Heavy::~Heavy() {}
