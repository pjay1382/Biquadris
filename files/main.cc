#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "blind.h"
#include "force.h"
#include "heavy.h"
#include "gameboard.h"
#include "block.h"
#include "level.h"
#include "level_0.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "level_4.h"
using namespace std;

int main(int argc, char* argv[]) {
	string player1, player2, cla, player1_file = "sequence1.txt", player2_file = "sequence2.txt";
	int numCol, numRow, i=0, startinglvl=0;
	cout<<"Enter player1 name, then player2 name:"<<endl;
	cin>>player1>>player2;
	cout<<"Number of rows and columns"<<endl;
	cin>>numRow>>numCol;
	numRow += 3;
	while(i < argc) {
		if(argv[i] == "-seed") { srand(stoi(argv[++i])); continue; }
		else if(argv[i] == "-scriptfile1") {  player1_file = argv[++i]; continue; }
		else if(argv[i] == "-scriptfile2") {  player2_file = argv[++i]; continue; }
		else if(argv[i] == "-startlevel") { startinglvl = stoi(argv[++i]); continue; }
		++i;
	}
	Gameboard* gp1 = new Gameboard(numCol, numRow, player1, startinglvl);
	Gameboard* gp2 = new Gameboard(numCol, numRow, player2, startinglvl);
	int p1curlvl = startinglvl, p2curlvl = startinglvl, p1nextlvl = startinglvl, p2nextlvl = startinglvl;
	vector<string> seq;
	string cmd;
	Board* lp1(gp1);
	Board* lp2(gp2);
	if(startinglvl > 0) {
		gp1->setrandom(true);
		gp1->lvlChange(startinglvl);
		gp2->setrandom(true);
		gp2->lvlChange(startinglvl);
	} else {
		gp1->setrandom(false);
		gp1->lvlChange(startinglvl, player1_file);
		gp2->setrandom(false);
                gp2->lvlChange(startinglvl, player2_file);
	}
	gp1->CurBlock((gp1->getLevel())->next_block(0));
	gp2->CurBlock((gp2->getLevel())->next_block(0));
	gp1->NextBlock((gp1->getLevel())->next_block(1));
	gp2->NextBlock((gp2->getLevel())->next_block(1));
	gp2->move(0,0,0);
	gp1->move(0,0,0);
	int p1orp2 = -1, p1 = 1, p2 = 1, hiscore = 0;
	while(1) {
		p1orp2++;
		//print
		bool reset = false;
		if(p1orp2 % 2 == 0) Gameboard* curboard = gp1;
		else Gameboard* curboard = gp2;
		while(1) {
			string cmd;
			cin>>cmd;
			if(cmd == "left") curboard->move(-1,0,0);
			if(cmd == "right") curboard->move(1,0,0);
			if(cmd == "down") curboard->move(0,1,0);
			if(cmd == "clockwise") curboard->move(0,0,1);
			if(cmd == "counterclockwise") curboard->move(0,0,-1);
			if(cmd == "drop") {
				while(curboard->move(0,1,0)){}
				curboard->addOldBlock((p1orp2 % 2 == 0) ? p1curlvl : p2curlvl);
				curboard->adjustboard();
			}
			if(cmd == "levelup") {
				int curlvl = curboard->getLvl();
				if(curlvl < 4) {
					curboard->setrandom(true);
					curboard->lvlChange(curlvl);
					if(p1orp2 % 2 == 0) {
						p1curlvl = curlvl;
						p1nextlvl = curlvl;
					} else {
						p2curlvl = curlvl;
						p2nextlvl = curlvl;
					}
				}
				//print
				continue;
			}
			if(cmd == "leveldown") {
				int curlvl = curboard->getLvl();
				if(curlvl > 0) {
					if(curlvl == 0) {
						curboard->setrandom(false);
						if(p1orp2 % 2 == 0) curboard->lvlchange(curlvl, player1_file);
						else curboard->lvlchange(curlvl, player2_file);
					}
					else {
						curboard->setrandom(true);
						curboard->lvlchange(curlvl);
					}
					if(p1orp2 % 2 == 0) {
                                                p1curlvl = curlvl;
                                                p1nextlvl = curlvl;
                                        } else {
                                                p2curlvl = curlvl;
                                                p2nextlvl = curlvl;
                                        }
				}
				//print
				continue;;
			}
			if(cmd == "norandom") {
				int curlvl = curboard->getLvl();
				if(curlvl == 3 || curlvl == 4) {
					string txtname;
					if(seq.empty()) cin>>txtname;
					else {
						txtname = seq.front();
						seq.erase(seq.begin());
					}
					ifstream fi{txtname};
					curboard->setrandom(false);
					curboard->lvlchange(curlevel, txtname);
				}
				//print
				continue;
			}
			if(cmd == "random") {
				int curlvl = curboard->getlvl();
				if(curlvl == 3 || curlvl == 4) curboard->setrandom(true);
				//print
				continue;
			}
			if(cmd == "sequence") {
				string txtname;
				string fileseq;
				if(seq.empty()) cin>>txtname;
				else {
					txtname = seq.front();
					seq.erase(seq.begin());
				}
				ifstream fi{txtname};
				while(fi >> fileseq) seq.push_back(fileseq);
				continue;
			}
			if(cmd == "restart") {
				reset = true;
				gp1->restart();
				gp2->restart();
				p1orp2 = -1;
				p1 = 1;
				p2 = 1;
				gp1->CurBlock((gp1->getLevel())->next_block(0));
				gp2->CurBlock((gp2->getLevel())->next_block(0));
				gp1->NextBlock((gp1->getLevel())->next_block(1));
			 	gp2->NextBlock((gp2->getLevel())->next_block(1));
				gp2->move(0,0,0);
				gp1->move(0,0,0);
				break;
			}
			if(cmd == "quit") return 0;
			if(curboard->getCur()->get_heavy_level()) {
				bool flag = curboard->move(0,1,0);
				if(!flag) {
					curboard->addOldBlock((p1orp2 % 2 == 0) ? p1curlvl : p2curlvl);
		 			curboard->adjustboard();
					break;
				}
			}
			if(curboard->getCur()->get_effect_heavy()) {
				if(cmd == "right" || cmd == "left") {
					int i = 0;
					for(i = 0; i < 2; i++) curboard->move(0,1,0);
					bool flag = curboard->move(0,1,0);
					curboard->move(0,-1,0);
					if(!flag) {
						curboard->addOldBlock((p1orp2 % 2 == 0) ? p1curlvl : p2curlvl);
						curboard->adjustboard();
						break;
					}
				}
			}
			//print
		}
		int p1score = gp1->getscore(), p2score = gp2->getscore();
		if(p1score > hiscore || p2score > hiscore) {
			hiscore = (p1score <= p2score) ? p2score : p1score;
			gp1->set_highscore(hiscore, false);
		}
		if(reset) continue;
		if(curboard->getSetHeavy(-1)) curboard->getSetHeavy(0);
		if(curboard->getSetBlind(-1)) curboard->getSetBlind(0);
		if(curboard->getSetForce(-1)) curboard->getSetForce(0);
		if(curboard->getLvl() == 4) {
			Block* star = curboard->getLevel()->next_block(0);
			if(star->get_block_type() == '*') {
				curboard->CurBlock(star);
				while(curboard->move(0,1,0)) {}
				curboard->addOldBlock(4);
				curboard->adjust();
			} else delete star;
		}
		if(curboard->getSeteffectneeded(-1)) {
			//print
			cout << "Type which effect do you want, blind, force, or heavy" << endl;
			string effect_name;
			while(1) {
				if(seq.empty()) cin>>effect_name;
				else {
					effect_name = seq.front();
					seq.erase(seq.begin());
				}
				if(effect_name == "heavy") {
					if(p1orp2 % 2 == 0) {
						gp2->getSetHeavy(1);
						delete lp2;
						lp2 = new Heavy(lp2); 
						lp2->add_effect(*gp2);
					} else {
						gp1->getSetHeavy(1);
                                                delete lp1;
                                                lp1 = new Heavy(lp1);
                                                lp1->add_effect(*gp1);
					}
					break;
				} else if(effect_name == "blind") {
					if(p1orp2 % 2 == 0) {
                                                gp2->getSetBlind(1);
                                                delete lp2;
                                                lp2 = new Blind(lp2);
                                                lp2->add_effect(*gp2);
                                        } else {
                                                gp1->getSetBlind(1);
                                                delete lp1;
                                                lp1 = new Blind(lp1);
                                                lp1->add_effect(*gp1);
                                        }
                                        break;
                                } else if(effect_name == "force") {
					char block_name;
					cout << "Enter the block you want to force to your opponent's board" << endl;
					if(seq.empty()) cin >> block_name;
					else {
						block_name = seq.front().front();
						seq.erase(seq.begin());
					}
					if(p1orp2 % 2 == 0) {
                                                gp2->getSetForce(1);
                                                delete lp2;
                                                lp2 = new Force(lp2);
                                                lp2->add_effect(*gp2);
						if(gp2->getSetGameOver(-1)) {
							cout << "Gameover!" <<endl;
							cout << player1 << " won!" << endl;
							return 0;
						}
                                        } else {
                                                gp1->getSetForce(1);
                                                delete lp1;
                                                lp1 = new Force(lp1);
                                                lp1->add_effect(*gp1);
						if(gp1->getSetGameOver(-1)) {
                                                        cout << "Gameover!" <<endl;
                                                        cout << player2 << " won!" << endl;
                                                        return 0;
                                                }
                                        }
                                        break;
                                }
				curboard->getSeteffectneeded(0);
			}
			int counter_block = 0;
			if(p1orp2 % 2 == 0) ++p1;
			else ++p2;
			curboard->CurBlock(curboard->getNext());
			curboard->NextBlock(curboard->getLevel()->next_block(counter_block));
			if(!curboard->move(0,0,0)) {
				cout << "Gameover!" << endl;
				if(p1orp2 % 2 == 0) cout << player2 << " won!" << endl;
				else cout << player1 << " won!" << endl;
				return 0;
			}
			curboard->move(0,0,0);
			if(p1orp2 % 2 == 0) {
				p1curlvl = p1nextlvl;
				p1nextlvl = curboard->getLvl();
			} else {
				p2curlvl = p2nextlvl;
                                p2nextlvl = curboard->getLvl();
			}
		}
	}
}

