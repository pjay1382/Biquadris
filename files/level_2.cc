#include "level_2.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "block.h" 

using namespace std;

Level2::Level2(bool random, string file_name): random{random}, 
    file_name{file_name} {}


Level2::~Level2() {}


Block *Level2::next_block(int index) {
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



int Level2::getlvl() { return cur_lvl; }


bool Level2::israndom() { return random; }


string Level2::getfile() { return file_name; }


void Level2::getblock(){
    if (!(random)) {
        char block_piece;
        inp.open(file_name);
        inp>>block_piece;
        while(true) {
            if(block_piece != "") blocks.emplace_back(block_piece);
            else break;
            inp>>block_piece;
        }
    }
}
