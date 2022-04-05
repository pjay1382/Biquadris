#include "cell.h"
using namespace std;

Cell::Cell(int col, int row, Gameboard* board): col{col}, row{row}, board{board} {}

int Cell::getCol() { return col; }
int Cell::getRow() { return row; }
void Cell::setCol(int Col) { col = Col; }
void Cell::setRow(int Row) { row = Row; }

void Cell::setPiece(char my_piece) {
	occupied = true;
	board_piece = my_piece;
}

void Cell::unsetPiece() {
	occupied = false;
	board_piece = '.';
}

bool Cell::isoccupied() { return occupied; }

char Cell::getPiece() { return board_piece; }
