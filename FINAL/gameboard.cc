#include "gameboard.h"
#include "cell.h"
#include "block.h"
#include "level_0.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "level_4.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

Gameboard::Gameboard(int columns, int rows, string name, int level): columns{columns}, rows{rows}, name{name}, lvl{lvl}  {
    build();
}

Gameboard::~Gameboard() { 
    delete curBlock;
    delete nextBlock;
    delete level;
}

void Gameboard::build() {
    for (int i = 0; i < rows; ++i) {
	vector<Cell> cellrow;
        for (int j = 0; j < columns; ++j) {
            cellrow.emplace_back(Cell(i, j, this));
        }
	board.push_back(cellrow);
    }
}

void Gameboard::restart() {
    board.clear();
    this->build();
    curScore = 0;
}

int Gameboard::getscore() {
	return curScore;
}

bool Gameboard::validmove(int lr, int ud, int rotate_amt) {
	int i, j, actual_rotate = (curBlock->get_rotate() + rotate_amt) % 4;
	if (lr == 0 && ud == 0 && rotate_amt == 0) {
		for (i = 1; i <= 4; ++i) {
			for (j = 1; j <= 4; ++j) {
				int pos_ud_nomove = curBlock->get_row() + i - 1;
				int pos_lr_nomove = curBlock->get_col() + j - 1;
				char board_piece_nomove = curBlock->get_block()[curBlock->get_rotate()][i - 1][j - 1];
				if (board_piece_nomove != '.' && 
						(pos_ud_nomove < 0 || pos_ud_nomove >= rows ||
						 pos_lr_nomove < 0 || pos_lr_nomove >= columns)) return false;
				if (board_piece_nomove != '.' && board[pos_ud_nomove][pos_lr_nomove].isoccupied()) return false;
                                }

			}
		return true;
	}
	for (i = 1; i <= 4; ++i) {
		 for (j = 1; j <= 4; ++j) {
			 int pos_ud_move = curBlock->get_row() + i - 1 + ud;
			 int pos_lr_move = curBlock->get_col() + j - 1 + lr;
			 char board_piece_move = curBlock->get_block()[actual_rotate][i - 1][j - 1];
			 if (board_piece_move != '.' && 
					 (pos_ud_move < 0 || pos_ud_move >= rows || 
					  pos_lr_move < 0 || pos_lr_move >= columns)) return false;	
			 if (board_piece_move != '.' && board[pos_ud_move][pos_lr_move].isoccupied() &&
					 (pos_ud_move < curBlock->get_row() || pos_ud_move > curBlock->get_row() + 3 ||
					  pos_lr_move < curBlock->get_col() || pos_lr_move > curBlock->get_col() + 3 || 
					  curBlock->get_block()[curBlock->get_rotate()][i + ud - 1][j + lr - 1] == '.')) return false;
		 }
	}
	return true;
}

void Gameboard::move(int lr, int ud, int rotate_amt) {	
	int actual_rotate = (curBlock->get_rotate() + rotate_amt) % 4, i, j;
	rmblock();
	for (i = 1; i <= 4; ++i) {
		for (j = 1; j <= 4; ++j) {
			int pos_ud_move = curBlock->get_row() + i - 1 + ud;
                        int pos_lr_move = curBlock->get_col() + j - 1 + lr;
                        char board_piece_move = curBlock->get_block()[actual_rotate][i - 1][j - 1];
			if (board_piece_move != '.') board[pos_ud_move][pos_lr_move].setPiece(board_piece_move);
		}
	}
	curBlock->set_rotate(actual_rotate);
	curBlock->set_col(curBlock->get_col() + lr);
	curBlock->set_row(curBlock->get_row() + ud);
}

void Gameboard::addOldBlock(int lvl) {
	vector<Existing> oldBlock;
	int i, j;
	for(j = 1; j <= 4; ++j) {
		for(i = 1; i <= 4; ++i) {
			if (curBlock->get_block()[curBlock->get_rotate()][j - 1][i - 1] != '.') 
				oldBlock.push_back(Existing((curBlock->get_row()+i-1), lvl));
		}
	}
	oldblocks.push_back(oldBlock);
}

void Gameboard::set(int row, int col, char block_piece) {
	board[row][col].setPiece(block_piece);
}

void Gameboard::unset(int row, int col) {
	board[row][col].unsetPiece();
}

void Gameboard::setrandom(bool setter) { randomval = setter; }

void Gameboard::adjustboard() {
	if (oldblocks[oldblocks.size() - 1][0].getLevel() == 4) {
		if (curBlock->get_block_type() == '*') {
	       		static_cast<Level4*>(level)->set_streak(0);
		} else {
			static_cast<Level4*>(level)->inc_streak();
		}
	}
	int lines_cleared = 0, i, j, k, l;
	for (i = 0; i < 4; i++) {
		if (curBlock->get_row() + i < rows) {
			bool flag = true;
			for (j = 0; j < columns; j++) {
				if (!board[curBlock->get_row() + i][j].isoccupied()) {
					flag = false;
					break;
				}
			}
			if (flag) {
				int rows_cleared = curBlock->get_row() + i;
				for (k = oldblocks.size() - 1; k >= 0; k--) {
					bool deleted = true;
					for (l = 1; l <= 4; l++) {
						if (oldblocks[k][l-1].getRow() == rows_cleared) oldblocks[k][l-1].setRemove(true);
						if (oldblocks[k][l-1].getRemove() == false) deleted = false;
						if (oldblocks[k].size() == 1) break;
						continue;
					}
					if (deleted) {
                                                int lvl_gen = oldblocks[k][0].getLevel();
                                                curScore += pow((1 + lvl_gen), 2);
                                                oldblocks.erase(oldblocks.begin() + k);
                                        }
				}
				for (k = rows_cleared - 1; k > 0; k--) {
					for (l = 0; l < columns; l++) {
						if (board[k][l].isoccupied()) {
							board[k + 1][l].setPiece(board[k][l].getPiece());
						} else {
							board[k + 1][l].unsetPiece();
						}
					}
				}
				for (k = 0; k < columns; k++) {
					board[0][k].unsetPiece();
				}
				lines_cleared++;
			}
		}
	}
	if (lines_cleared > 0) {
		for (i = 0; i < oldblocks.size(); i++) {
                	for (j = 1; j <= 4; j++) {
                        	oldblocks[i][j-1].setRow(oldblocks[i][j-1].getRow() + lines_cleared);
				if (oldblocks[i].size() == 1) {break;}
                	}
        	}
		if (lvl == 4) static_cast<Level4*>(level)->set_streak(0);
		curScore  += (lvl + lines_cleared) * (lvl + lines_cleared);
	}
	delete curBlock;
	if (lines_cleared >= 2) iseffect = true;
}

void Gameboard::rmblock() {
	int i, j;
	 for(i = 1; i <= 4; ++i) {
		 for(j = 1; j <= 4; ++j) {
			 int pos_ud_nomove = curBlock->get_row() + i - 1;
			 int pos_lr_nomove = curBlock->get_col() + j - 1;
			 char board_piece_nomove = curBlock->get_block()[curBlock->get_rotate()][i - 1][j - 1];
			 if(board_piece_nomove != '.') {
				 board[pos_ud_nomove][pos_lr_nomove].unsetPiece();
			 }
		 }
	 }
}

void Gameboard::lvlChange(int lvlc, string sequence) {
	delete level;
	if(lvlc == 4) {
		if (randomval) level = new Level4(true); 
		else level = new Level4(false, sequence);
		lvl = lvlc;
	} else if(lvlc == 3) {
		if (randomval) level = new Level3(true); 
		else level = new Level3(false, sequence);
		lvl = lvlc;
        } else if(lvlc == 2) {
		if (randomval) level = new Level2(true); 
		else level = new Level2(false, sequence);
		lvl = lvlc;
        } else if(lvlc == 1) {
		if (randomval) level = new Level1(true); 
		else level = new Level1(false, sequence);
		lvl = lvlc;
        } else if(lvlc == 0) {
		level = new Level0(false, sequence);
		lvl = lvlc;
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
		if (iseffect == true) return 1; 
		else return 0;
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
                if (blind == true) return 1;
	        else return 0;
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
                if (force == true) return 1;
	        else return 0;
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
                if (heavy == true) return 1;
	        else return 0;
        }
        else if(eff_heavy == 0) {
                heavy = false;
                return -1;
        } else {
                heavy = true;
                return -1;
        }
}

void Gameboard::add_effect(Gameboard &g) {}

int Gameboard::getSetGameOver(int over) {
        if(over == -1) {
               if (isgameOver == true) return 1;
	       else return 0;
        }
        else if(over == 0) {
                isgameOver = false;
                return -1;
        } else {
                isgameOver = true;
                return -1;
        }
}

int Gameboard::set_highscore(int hiscore, bool get) {
	if(get == true) return highScore;
	highScore = hiscore;
	return -1;
}

int Gameboard::getCols() { return columns; }
int Gameboard::getRows() { return rows; }
vector<vector<Cell>>& Gameboard::getGameboardRef() { return board; }
