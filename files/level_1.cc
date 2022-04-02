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
        get_block();
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



int Level1::getlvl() { return cur_lvl; }


bool Level1::israndom() { return random; }


string Level1::getfile() { return file_name; }


void Level1::getblock(){
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
