#include "blind.h"
#include "gameboard.h"
#include <memory>
using namespace std;

Blind::Blind(shared_ptr<Board> board) : Effects{board} {}

void Blind::add_effect(Gameboard &g) {
	board->add_effect(g);
}

Blind::~Blind() {}
