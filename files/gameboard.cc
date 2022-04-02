#include "gameboard.h"
#include "cell.h"

#include <vector>

using namespace std;

Gameboard::Gameboard(int columns, int rows, string name, int level): columns{columns}, rows{rows}, name{name}, level{level}  {
    this->build();
}

Gameboard::~Gameboard() { 
    delete curBlock;
    delete nextBlock;
    delete Level;
}

void Gameboard::build() {
    for (int i = 0; i < rows; ++i) {
        board.push_back(vector<Cell>);
        for (int j = 0; j < columns; ++j) {
            board[i].push_back(Cell(i, j));
        }
    }
}

void Gameboard::restart() {
    board.clear();
    this->build();
    curScore = 0;
}

int Gameboard::getscore() {
	return cur_score;
}

bool Gameboard::move(int lr, int ud, int rotate_amt) {
	bool flag = true;
	int i, j, actual_rotate = (curBlock->getrotate() + rotate_amt) % 4;
	if( lr == ud && rotate_amt == ud && ud == 0) {
		for(i = 1; i <= 4; ++i) {
			for(j = 1; j <= 4; ++j) {
				int pos_ud_nomove = curBlock->getY() + i - 1;
				int pos_ud_move = curBlock->getY() + i - 1 + ud;
				int pos_lr_nomove = curBlock->getX() + j - 1;
				int pos_lr_move = curBlock->getX() + j - 1 + lr;
				char board_piece_nomove = curBlock->getBlock()[curBlock->get_rotate()][i - 1][j - 1];
				char board_piece_move = curBlock->getBlock()[actual_rotate][i - 1][j - 1];
				if(board_piece_nomove != '.') {
					if(pos_ud_nomove < 0 || pos_ud_nomove>= rows || pos_lr_nomove < 0 || pos_ul_nomove >= columns) 
						flag = false;
					if(board[pos_ud_nomove][pos_lr_nomove].isoccupied)
						flag = false;
				}
				if(board_piece_move != '.') {
					if(pos_ud_move < 0 || pos_ud_move >= columns || pos_lr_move < 0 || pos_lr_move >= rows)
						flag = false;
					if(board[pos_ud_move][pos_lr_move].isoccupied && 
							(pos_ud_move < curBlock->getY() || pos_ud_move < (curBlock->getY()+3) || 
							 pos_lr_move < curBlock->getX() || pos_lr_move < (curBlock->getX()+3)))
						flag = false;
					if(board[pos_ud_move][pos_lr_move].isoccupied && curBlock->getBlock()[curBlock->getrotate()][i+up][j+lr] == '.')
						flag = false;
				}
			}
		}
	}
	if(flag == false) return false;	
	this->remblock();
	for(i = 1; i <= 4; ++i) {
		for(j = 1; j <= 4; ++j) {
			if(board_piece_move != '.') {
				board[pos_ud_move][pos_ul_move].setPiece(board_piece_move);
			}
		}
	}
	curBlock->setX(curBlock->getX() + lf);
	curBlock->setY(curBlock->getY() + ud);
	curBlock->set_rotate(actual_rotate);
	return true;
}

void Gameboard::addOldBlocks(int lvl) {
	vector<Existing> oldBlock;
	int i, j;
	for(j = 1; j <= 4; ++j) {
		for(i = 1; i <= 4; ++i) {
			(curBlock->getBlock()[curBlock->get_rotate()][j - 1][i - 1] != '.') ? block.push_back(Existing((curBlock->getY()+i-1), lvl)) : continue;
		}
	}
	oldBlocks.push_back(oldBlock);
}

void Gameboard::set(int row, int col, char block_piece) {
	board[row][col].setPiece(block_piece);
}

void Gameboard::unset(int row, int col) {
	board[row][col].unsetPiece();
}

void Gameboard::adjustboard() {
	if(oldBlocks[oldBlocks.size()-1][0].getLevel() == 4) {
		if(curBlock->getType() != '*') {
			//streak++
		} else {
			streak = 0;
		}
	}
	int lines_cleared=0, i, j, k, l;
	for(i = 1; i <= 4; ++i) {
		if(curBlock->getY()+i-1 < rows) {
			int flag = 1;
			for(j = 1; j <= 4; ++j) {
				(!board[curBlock()getY()+i-1][j-1].isoccupied) ? {flag = 0; break;} : continue;
			}
			if(flag) {
				int row_cleared = curBlock->getY()+i-1;
				for(k = 0; k < columns, ++k) {
					bool delete = true;
					for(l = 0; l < 4; ++l) {
						if(oldBlocks[k][l].getY() == row_cleared) 
							oldBlocks[k][l].setClear(true);
						if(!oldBlocks[k][l].getClear())
							delete = false;
						if(oldBlocks[k].size() == 1)
							break;
					}
					if(delete true) {
						int lvl_gen = oldBlocks[k][0].getLevel();
						score+=pow((1+lvl_gen), 2);
						oldBlocks.erase(oldBlocks.begin()+k);
					}
				}
				for(k = lines_cleared-1; k > 0; --k) {
					for(l = 0; l < columns; ++l) {
						(board[k][l].isoccupied) ? board[k+1][j].setPiece(board[k][l].getPiece()) : board[k+1][j].unsetPiece();
					}
				}
				for(k = 1; k <= columns; ++k) {
					board[0][k-1].unsetPiece();
				}
				++lines_cleared;
			}
		}
	}
	if(lines_cleared) {
		for(i = 0; i < oldBlocks.size(); ++i) {
			for(j = 0; j < 4; j++) {
				oldBlocks[i][j].setRow(oldBlocks[i][j].getY() + lines_cleared);
				if(oldBlocks[i].size() == 1)
					break;
			}
		}
		score+ = pow((lvl+lines_cleared), 2);
		//if(lvl == 4) //streak=0
	}
	if(lines_cleared >= 2) 
		!iseffect;
	delte curBlock;
}

void Gameboard::rmblock() {
	int i, j;
	 for(i = 1; i <= 4; ++i) {
		 for(j = 1; j <= 4; ++j) {
			 int pos_ud_nomove = curBlock->getY() + i - 1;
			 int pos_lr_nomove = curBlock->getX() + j - 1;
			 char board_piece_nomove = curBlock->getBlock()[curBlock->get_rotate()][i - 1][j - 1];
			 if(board_piece_nomove != '.') {
				 board[pos_ud_nomove][pos_lr_nomove].unsetPiece();
			 }
		 }
	 }
}

void Gameboard::lvlchange(int lvl, string sequence) {
	delete level;
	if(lvl == 4) {
		(random)?level = new Level4(true):level = new Level4(false, sequence);
		this->lvl = lvl;
	} else if(lvl == 3) {
		(random)?level = new Level3(true):level = new Level3(false, sequence);
		this->lvl = lvl;
        } else if(lvl == 2) {
		(random)?level = new Level2(true):level = new Level2(false, sequence);
		this->lvl = lvl;
        } else if(lvl == 1) {
		(random)?level = new Level1(true):level = new Level1(false, sequence);
		this->lvl = lvl;
        } else if(lvl == 0) {
		level = new Level0(sequence);
	}
}

void Gameboard::CurBlock(Block* current) {
	curBlock = current;
}

void Gameboard::NextBlock(Block* next) {
        nextBlock = next;
}

Block* Gameboard::getCur() { return curBlock; }
Block* Gameboard::getNext() { return nextBlock; }
Level* Gameboard::getLevel() { return level; }
string Gameboard::getName() { return name; }
int Gameboard::getLvl() { return lvl; }

int Gameboard::getSeteffectneeded(int effect) {
	if(effect == -1) {
		(iseffect)? return 1 : return 0;
	} else if(effect == 0) {
		iseffect = false;
		return -1;
	} else {
		iseffect = true;
		return -1;
	}
}

int Gameboard::getSetBlind(int eff_blind) {
        if(eff_blind == -1) {
                (blind)? return 1 : return 0;
        } else if(eff_blind == 0) {
                blind = false;
                return -1;
        } else {
                blind = true;
                return -1;
        }
}

int Gameboard::getSetForce(int eff_force) {
        if(eff_force == -1) {
                (force)? return 1 : return 0;
        } else if(eff_force == 0) {
                force = false;
                return -1;
        } else {
                force = true;
                return -1;
        }
}

int Gameboard::getSetHeavy(int eff_heavy) {
        if(eff_heavy == -1) {
                (heavy)? return 1 : return 0;
        }
        else if(eff_heavy == 0) {
                heavy = false;
                return -1;
        } else if (eff_heavy == 1) {
                heavy = true;
                return -1;
        }
}

void Gameboard::add_effect(Gameboard &g) {}

int Gameboard::getSetGameOver(int over) {
        if(over == -1) {
                (isgameOver)? return 1 : return 0;
        }
        else if(over == 0) {
                isgameOver = false;
                return -1;
        } else if (over == 1) {
                isgameOver = true;
                return -1;
        }
}

int Gameboard::set_highscore(int hiscore, bool get) {
	(get) ? return highscore;
	highscore = hiscore;
	return -1;
}

int Gameboard::getCols() { return columns; }
int Gameboard::getRows() { return rows; }
<vector<vector<Cell>>& Gameboard::getGameboardRef() { return board; }
