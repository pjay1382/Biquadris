#include "force.h"
#include "gameboard.h"
#include <memory>
using namespace std;

Force::Force(shared_ptr<Board> board, char block_type) : Effects{board}, block_type{block_type} {}


void Force::add_effect(Gameboard &g) {
	board->add_effect(g);

	if(g.getSetForce(-1)) {
        	bool isheavy = false;
        	if (g.getLvl() >= 4) isheavy = true;
        	Block* nextBlock = nullptr;
        	Block* curBlock = g.getCur();
        	if (block_type == 'S') nextBlock = new sBlock{isheavy};
        	else if (block_type == 'Z') nextBlock = new zBlock{isheavy};
        	else if (block_type == 'T') nextBlock = new tBlock{isheavy};
		else if (block_type == 'I') nextBlock = new iBlock{isheavy};
		else if (block_type == 'O') nextBlock = new oBlock{isheavy};
		else if (block_type == 'J') nextBlock = new jBlock{isheavy};
		else if (block_type == 'L') nextBlock = new lBlock{isheavy};
        	else return;
        	nextBlock->set_col(curBlock->get_col());
        	nextBlock->set_row(curBlock->get_row());
        	g.rmblock();
        	g.CurBlock(nextBlock);
        	if (g.validmove(0, 0, 0)) delete curBlock;
		else {
                	g.CurBlock(curBlock);
                	g.move(0, 0, 0);
                	delete nextBlock;
			g.getSetGameOver(1);
        	}
	}
}

Force::~Force() {}
