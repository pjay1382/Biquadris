#include <iostream>
#include "gameboard.h"
#include "textdisp.h"
#include <iomanip>
#include <vector>
#include "cell.h"
#include "block.h"
using namespace std;

textdisp::textdisp(int numRows, int numCols): numRows{numRows}, numCols{numCols} {}

void textdisp::displayboard(Gameboard* gb1, Gameboard* gb2) {
	cout << "HIGHSCORE:        " << gb1->set_highscore(1, true) << endl;
        cout << "Name: " << setfill(' ') << setw(5) << gb1->getName();
	cout << "     ";
	cout << "Name: " << setfill(' ') << setw(5) << gb2->getName() << endl;
	cout << "Score:" << setfill(' ') << setw(5) << gb1->getscore();
    	cout << "     " ;
	cout << "Score:" << setfill(' ') << setw(5) << gb2->getscore() << endl;
	cout << "level:" << setfill(' ') << setw(5) << gb1->getLvl();
    	cout << "     " ;
    	cout << "level:" << setfill(' ') << setw(5) << gb2->getLvl() << endl;
	cout <<"-----------     -----------" <<endl;
	int i, j, blindp1 = gb1->getSetBlind(-1), blindp2 = gb2->getSetBlind(-1);
	for (i  = 0; i < numRows; i++) {
		for(j = 0; j < numCols; j++) {
			if(blindp1 && j >=2 && j <= 8 && i >= 2 && i <= 11) { cout << '?'; continue; }
			if((gb1->getGameboardRef())[i][j].getPiece() == '.') cout << ' ';
			else cout << (gb1->getGameboardRef())[i][j].getPiece();
		}
		cout << "     " ;
		for(j = 0; j < numCols; j++) {
			if(blindp2 && j >=2 && j <= 8 && i >= 2 && i <= 11) { cout << '?'; continue; }
                        if((gb2->getGameboardRef())[i][j].getPiece() == '.') cout << ' ';
                        else cout << (gb2->getGameboardRef())[i][j].getPiece();
                }
		cout << endl;
	}
	cout <<"-----------     -----------" <<endl;
	cout <<"Next:           Next:      " << endl;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if(gb1->getNext()->getpreview()[i][j] == '.') cout << ' '; 
			else cout << gb1->getNext()->getpreview()[i][j];
		}
		cout << "      ";
		cout << "      ";
		for (j = 0; j < 4; j++){
                        if(gb2->getNext()->getpreview()[i][j] == '.') cout << ' ';
                        else cout << gb2->getNext()->getpreview()[i][j];
                }
		cout << endl;
	}
}
