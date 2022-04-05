#ifndef TEXTDISP_H
#define TEXTDISP_H

class Gameboard;

class textdisp {
	int numRows;
	int numCols;
	public:
	textdisp(int numRows, int numCols);
	void displayboard(Gameboard* gb1, Gameboard* gb2);
};

#endif
