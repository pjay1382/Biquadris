#ifndef CELL_H
#define CELL_H

class Gameboard;
class Cell {
	int col;
	int row;
	char board_piece = '.';
	bool occupied = false;
	Gameboard* board;
	public:
	Cell(int col, int row, Gameboard* board);
	int getCol();
	int getRow();
	void setCol(int Col);
	void setRow(int Row);
	void setPiece(char my_piece);
	void unsetPiece();
	bool isoccupied();
	char getPiece();
};

#endif
