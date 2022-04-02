#include "level_0.h"
#include <fstream>
#include <iostream>
#include <string>
#include "block.h"

using namespace std;

Level0::Level0(bool random, string file_name): random{random},
    file_name{file_name} {}


Level0::~Level0() {}


Block *Level0::next_block(int index) {
    int num;
    getblock();
    num = index % blocks.size();        
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



int Level0::getlvl() { return cur_lvl; }


bool Level0::israndom() { return random; }


string Level0::getfile() { return file_name; }


void Level0::getblock(){
    if (!(random)) {
        char block_piece;
        inp.open(file_name);
        inp>>block_piece;
        while(true) {
            if(block_piece != nullptr) blocks.emplace_back(block_piece);
            else break;
            inp>>block_piece;
        }
    }
}
