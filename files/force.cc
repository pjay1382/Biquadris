#include "force.h"
#include "gameboard.h"

using namespace std;

Force::Force(Board *board, char block_type) : Effects{board}, block_type{block_type} {}


void Force::add_effect(Gameboard &g) {
	board->add_effect(g);

	if(g.getSetForce()) {
        	bool isheavy = false;
        	if (g.getLvl() >= 4) isheavy = true;
        	Block* nextBlock = nullptr;
        	Block* curBlock = g.getCur()
        	if (block == 'S') nextBlock = new sBlock{isheavy};
        	else if (block == 'Z') nextBlock = new zBlock{isheavy};
        	else if (block == 'T') nextBlock = new tBlock{isheavy};
		else if (block == 'I') nextBlock = new iBlock{isheavy};
		else if (block == 'O') nextBlock = new oBlock{isheavy};
		else if (block == 'J') nextBlock = new jBlock{isheavy};
		else if (block == 'L') nextBlock = new lBlock{isheavy};
        	else return;
        	nextBlock->setX(curBlock->getX());
        	nextBlock->setY(curBlock->getY());
        	g.unsetBlock();
        	g.setCurBlock(nextBlock);
        	if (g.move(0, 0, 0)) delete curBlock;
		else {
                	g.CurBlock(curBlock);
                	g.move(0, 0, 0);
                	delete nextBlock;
			g.getSetGameOver(1);
        	}
	}
}

Force::~Force() {}
