#include "force.h"
#include "board.h"

using namespace std;

Force::Force(Board *board, char block_type) : Effects{board}, block_type{block_type} {}


void Force::add_effect(Gameboard &g) {
	absboard->apply(g);

	if(g.getSetForce()) {
        	bool isheavy = false;
        	if (g.getLevel() == 3 || g.getLevel() == 4) {
			isheavy = true;
            }

        	Block * oldBlock = g.getCurBlock();
        	Block * newBlock = nullptr;
        	if (block == 'I') {
			newBlock = new Iblock{isheavy};
            }
        	else if (block == 'J') {
                	newBlock = new Jblock{isheavy};
        	}
        	else if (block == 'L') {
                	newBlock = new Lblock{isheavy};
        	}
        	else if (block == 'O') {
                	newBlock = new Oblock{isheavy};
        	}
        	else if (block == 'S') {
                	newBlock = new Sblock{isheavy};
        	}
        	else if (block == 'Z') {
                	newBlock = new Zblock{isheavy};
        	}
        	else if (block == 'T') {
                	newBlock = new Tblock{isheavy};
        	}
        	else {
                	return;
        	}

        	newBlock->setX(oldBlock->getX());
        	newBlock->setY(oldBlock->getY());
        	g.unsetBlock();
        	g.setCurBlock(newBlock);

        	if (g.validMove(0, 0, 0)) {
			g.moveBlock(0, 0, 0);
                	delete oldBlock;
		} else {
                	g.setCurBlock(oldBlock);
                	g.moveBlock(0, 0, 0);
                	delete newBlock;
			g.setDead(true);
        	}
	}
}


Force::~Force() {}
