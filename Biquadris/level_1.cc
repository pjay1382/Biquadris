#include "level_1.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "block.h" 

using namespace std;

Level1::Level1(bool random, string file_name): random{random}, 
    file_name{file_name} {}


Level1::~Level1() {}


Block *Level1::next_block(int index) {
    int num;
    if (!(random)) {
        getblock();
        num = index % blocks.size();        
    } else {
        blocks.clear();
        blocks = {'Z', 'Z', 'S', 'S', 'L', 'T', 'O', 'J', 'I'};
        num = rand() % blocks.size();
    }
    if (blocks[num] == 'Z') { 
        return new zBlock{false};
    } else if (blocks[num] == 'S') {
        return new sBlock{false};
    } else if (blocks[num] == 'L') {
        return new lBlock{false};
    } else if (blocks[num] == 'T') {
        return new tBlock{false};
    } else if (blocks[num] == 'O') {
        return new oBlock{false};
    } else if (blocks[num] == 'J') {
        return new jBlock{false};
    } else if (blocks[num] == 'I') {
        return new iBlock{false};
    }
}



int Level1::getlvl() { return cur_lvl; }


bool Level1::israndom() { return random; }


string Level1::getfile() { return file_name; }


void Level1::getblock(){
	if (!(random)) {
        char block_piece;
        inp.open(file_name);
        while(inp>>block_piece) {
                blocks.push_back(block_piece);
        }
    }
}
