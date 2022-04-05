#include "level_3.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "block.h" 

using namespace std;

Level3::Level3(bool random, string file_name): random{random}, 
    file_name{file_name} {}


Level3::~Level3() {}


Block *Level3::next_block(int index) {
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
        return new zBlock{true};
    } else if (blocks[num] == 'S') {
        return new sBlock{true};
    } else if (blocks[num] == 'L') {
        return new lBlock{true};
    } else if (blocks[num] == 'T') {
        return new tBlock{true};
    } else if (blocks[num] == 'O') {
        return new oBlock{true};
    } else if (blocks[num] == 'J') {
        return new jBlock{true};
    } else if (blocks[num] == 'I') {
        return new iBlock{true};
    }
}



int Level3::getlvl() { return cur_lvl; }


bool Level3::israndom() { return random; }


string Level3::getfile() { return file_name; }


void Level3::getblock(){
    if (!(random)) {
	char block_piece;
        inp.open(file_name);
        while(inp>>block_piece) {
		blocks.push_back(block_piece);
	}
    }
}
