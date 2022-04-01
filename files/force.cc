#include "force.h"
#include "board.h"

using namespace std;

Force::Force(Board *board, char bock_type) : Effects{board}, bock_type{block_type} {}


void Force::add_effect(Gameboard &g) {
	absboard->apply(g);

	if(g.getSetForce()) {
        	bool heavy = false;
        	if (g.getLevel() == 3 || g.getLevel() == 4) {
			heavy = true;
            }

        	Block * oldBlock = g.getCurBlock();
        	Block * newBlock = nullptr;
        	if (block == 'I') {
			newBlock = new Iblock{heavy};
            }
        	else if (block == 'J') {
                	newBlock = new Jblock{heavy};
        	}
        	else if (block == 'L') {
                	newBlock = new Lblock{heavy};
        	}
        	else if (block == 'O') {
                	newBlock = new Oblock{heavy};
        	}
        	else if (block == 'S') {
                	newBlock = new Sblock{heavy};
        	}
        	else if (block == 'Z') {
                	newBlock = new Zblock{heavy};
        	}
        	else if (block == 'T') {
                	newBlock = new Tblock{heavy};
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
