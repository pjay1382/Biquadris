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



int Level0::getlvl() { return cur_lvl; }


bool Level0::israndom() { return random; }


string Level0::getfile() { return file_name; }


void Level0::getblock(){
        char block_piece;
        inp.open(file_name);
        while(inp>>block_piece) {
            blocks.push_back(block_piece);
        }
    }
