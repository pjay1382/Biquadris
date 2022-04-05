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
        	switch(block_type) {
			case 'S': nextBlock = new sBlock{isheavy};
			  	  break;
			case 'Z': nextBlock = new zBlock{isheavy};
		  		  break;
			case 'T': nextBlock = new tBlock{isheavy};
	  			  break;
			case 'I': nextBlock = new iBlock{isheavy};
				  break;
			case 'O': nextBlock = new oBlock{isheavy};
  				  break;
			case 'J': nextBlock = new jBlock{isheavy};
  				  break;
			case 'L': nextBlock = new lBlock{isheavy};
  				  break;
			default: return;
		}
		int newcol = curBlock->get_col();
		nextBlock->set_col(newcol);
		int newrow = curBlock->get_row();
        	nextBlock->set_row(newrow);
        	g.rmblock();
        	g.CurBlock(nextBlock);
        	if (!g.validmove(0, 0, 0)) {
			g.CurBlock(curBlock);
                        g.move(0, 0, 0);
                        delete nextBlock;
                        g.getSetGameOver(1);
		}
		else delete curBlock;
        }
}

Force::~Force() {}
