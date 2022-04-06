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
#include "textdisp.h"
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {
	string player1, player2, cla, player1_file = "sequence1.txt", player2_file = "sequence2.txt";
	int numCol, numRow, i=1, startinglvl=0;
	cout<<"Enter player1 name, then player2 name:"<<endl;
	cin>>player1>>player2;
	cout<<"Number of rows and columns"<<endl;
	cin>>numRow>>numCol;
	numRow += 3;
	srand(246);
	for(i = 1; i < argc; i++) {
		string flag = argv[i];
		string arg = argv[i+1];
		if(flag == "-seed") srand(stoi(arg));
		if(flag == "-scriptfile1") player1_file = arg;
		if(flag  == "-scriptfile2") player2_file = arg;
		if(flag == "-startlevel") { startinglvl = stoi(arg); cout<<arg<<endl; }
		++i;
	}
	Gameboard* gp1 = new Gameboard(numCol, numRow, player1, startinglvl);
	Gameboard* gp2 = new Gameboard(numCol, numRow, player2, startinglvl);
	auto tdisp = make_unique<textdisp>(numRow, numCol);
	int p1curlvl = startinglvl, p2curlvl = startinglvl, p1nextlvl = startinglvl, p2nextlvl = startinglvl;
	string cmd;
	shared_ptr<Board> lp1(gp1);
	shared_ptr<Board> lp2(gp2);
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
	gp1->NextBlock((gp1->getLevel())->next_block(1));
        gp1->move(0,0,0);
	gp2->CurBlock((gp2->getLevel())->next_block(0));
	gp2->NextBlock((gp2->getLevel())->next_block(1));
	gp2->move(0,0,0);
	int p1orp2 = -1, p1 = 1, p2 = 1, hiscore = 0;
	while(1) {
		tdisp->displayboard(gp1, gp2);
		p1orp2++;
		bool reset = false;
		Gameboard* curboard = (p1orp2 % 2 == 0) ? gp1 : gp2;
		while(1) {
			string cmd;
			cin>>cmd;
			if(cmd == "left" && curboard->validmove(-1,0,0)) { curboard->move(-1,0,0); tdisp->displayboard(gp1, gp2); }
			if(cmd == "up" && curboard->validmove(0,-1,0)) { curboard->move(0,-1,0); tdisp->displayboard(gp1, gp2); }
			if(cmd == "right" && curboard->validmove(1,0,0)) { curboard->move(1,0,0); tdisp->displayboard(gp1, gp2); }
			if(cmd == "down" && curboard->validmove(0,1,0)) { curboard->move(0,1,0); tdisp->displayboard(gp1, gp2); }
			if(cmd == "clockwise" && curboard->validmove(0,0,1)) { curboard->move(0,0,1); tdisp->displayboard(gp1, gp2); }
			if(cmd == "counterclockwise" && curboard->validmove(0,0,5)) { curboard->move(0,0,5); tdisp->displayboard(gp1, gp2); }
			if(cmd == "drop") {
				while(curboard->validmove(0,1,0)) { curboard->move(0,1,0); tdisp->displayboard(gp1, gp2); }
				curboard->addOldBlock((p1orp2 % 2 == 0) ? p1curlvl : p2curlvl);
				curboard->adjustboard();
				break;
			}
			if(cmd == "levelup") {
				int curlvl = curboard->getLvl();
				++curlvl;
				if(curlvl <= 4) {
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
				cout << p1curlvl << endl;
				tdisp->displayboard(gp1, gp2);
				continue;
			}
			if(cmd == "leveldown") {
				int curlvl = curboard->getLvl();
				--curlvl;
				if(curlvl >= 0) {
					if(curlvl == 0) {
						cout<<curlvl<<endl;
						curboard->setrandom(false);
						if(p1orp2 % 2 == 0) curboard->lvlChange(curlvl, player1_file);
						else curboard->lvlChange(curlvl, player2_file);
					}
					else {
						curboard->setrandom(true);
						curboard->lvlChange(curlvl);
					}
				}
					if(p1orp2 % 2 == 0) {
                                                p1curlvl = curlvl;
                                                p1nextlvl = curlvl;
                                        } else {
                                                p2curlvl = curlvl;
                                                p2nextlvl = curlvl;
                                        }
				cout<<curboard->getLvl()<<endl;	
				tdisp->displayboard(gp1, gp2);
				continue;
			}
			if(cmd == "norandom") {
				int curlvl = curboard->getLvl();
				if(curlvl == 3 || curlvl == 4) {
					string txtname;
					cin>>txtname;
					curboard->setrandom(false);
					curboard->lvlChange(curlvl, txtname);
				}
				tdisp->displayboard(gp1, gp2);
				continue;
			}
			if(cmd == "random") {
				int curlvl = curboard->getLvl();
				if(curlvl == 3 || curlvl == 4) curboard->setrandom(true);
				tdisp->displayboard(gp1, gp2);
				continue;
			}
			if(cmd == "sequence") {
				string txtname;
				cin>>txtname;
				curboard->setrandom(false);
				curboard->lvlChange(curboard->getLvl(), txtname);
				continue;
			}
			if(cmd == "restart") {
				reset = true;
				gp1->restart();
				gp1->CurBlock((gp1->getLevel())->next_block(0));
				gp1->NextBlock((gp1->getLevel())->next_block(1));
				gp1->move(0,0,0);
				gp2->restart();
				gp2->CurBlock((gp2->getLevel())->next_block(0));
                                gp2->NextBlock((gp2->getLevel())->next_block(1));
                                gp2->move(0,0,0);
				p1orp2 = -1;
				p1 = 1;
				p2 = 1;
				break;
			}
			if(cmd == "quit") return 0;
			if(curboard->getLvl() >= 3) {
				if(curboard->validmove(0,1,0))
					curboard->move(0,1,0);
				else {
					curboard->addOldBlock((p1orp2 % 2 == 0) ? p1curlvl : p2curlvl);
					curboard->adjustboard();
					break;
				}
			}
			if(curboard->getSetHeavy(-1)) {
				if(cmd == "right" || cmd == "left") {
					int i = 0;
					for(i = 0; i < 2; i++) {if(curboard->validmove(0,1,0)) curboard->move(0,1,0); else break;}
					if(curboard->validmove(0,1,0) == false) {
						if(p1orp2 % 2 == 1) curboard->addOldBlock(p2curlvl);
						else curboard->addOldBlock(p1curlvl);
						curboard->adjustboard();
						break;
					}
				}
			}
			tdisp->displayboard(gp1, gp2);
		}
		int p1score = gp1->getscore(), p2score = gp2->getscore();
		hiscore = max(max(p1score, p2score), hiscore);
		gp2->set_highscore(hiscore, false);
		gp1->set_highscore(hiscore, false);
		if(reset) continue;
		if(curboard->getSetHeavy(-1)) curboard->getSetHeavy(0);
		if(curboard->getSetBlind(-1)) curboard->getSetBlind(0);
		if(curboard->getSetForce(-1)) curboard->getSetForce(0);
		if(curboard->getLvl() == 4) {
			Block* star = curboard->getLevel()->next_block(0);
			if(star->get_block_type() != '*') delete star;
			else {
				curboard->CurBlock(star);
				while(curboard->validmove(0,1,0)) {curboard->move(0,1,0);}
				curboard->addOldBlock(curboard->getLvl());
				curboard->adjustboard();
			}
		}
		if(curboard->getSeteffectneeded(-1)) {
			tdisp->displayboard(gp1, gp2);
			cout << "Type which effect do you want, blind, force, or heavy" << endl;
			string effect_name;
			while(1) {
				cin>>effect_name;
				if(effect_name == "heavy") {
					if(p1orp2 % 2 == 0) {
						gp2->getSetHeavy(1);
						lp2.reset(new Heavy(lp2)); 
						lp2->add_effect(*gp2);
					} else {
						gp1->getSetHeavy(1);
                                                lp1.reset(new Heavy(lp1));
                                                lp1->add_effect(*gp1);
					}
					break;
				} else if(effect_name == "blind") {
					if(p1orp2 % 2 == 0) {
                                                gp2->getSetBlind(1);
                                                lp2.reset(new Blind(lp2));
                                                lp2->add_effect(*gp2);
                                        } else {
                                                gp1->getSetBlind(1);
                                                lp1.reset(new Blind(lp1));
                                                lp1->add_effect(*gp1);
                                        }
                                        break;
                                } else if(effect_name == "force") {
					char block_name;
					cout << "Enter the block you want to force to your opponent's board" << endl;
					cin >> block_name;
					if(p1orp2 % 2 == 0) {
                                                gp2->getSetForce(1);
                                                lp2.reset(new Force(lp2, block_name));
                                                lp2->add_effect(*gp2);
						if(gp2->getSetGameOver(-1)) {
							cout << "Gameover!" <<endl;
							cout << player1 << " won!" << endl;
							return 0;
						}
                                        } else {
                                                gp1->getSetForce(1);
                                                lp1.reset(new Force{lp1, block_name});
                                                lp1->add_effect(*gp1);
						if(gp1->getSetGameOver(-1)) {
                                                        cout << "Gameover!" <<endl;
                                                        cout << player2 << " won!" << endl;
                                                        return 0;
                                                }
                                        }
					tdisp->displayboard(gp1, gp2);
                                        break;
                                }
			}
			curboard->getSeteffectneeded(0);
		}
		curboard->CurBlock(curboard->getNext());
		if (p1orp2 % 2 == 0) { ++p1; curboard->NextBlock(curboard->getLevel()->next_block(p1)); }
		else { ++p2; curboard->NextBlock(curboard->getLevel()->next_block(p2)); }
		if(curboard->validmove(0,0,0) == false) {
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
