#include "level_4.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

using namespace std;

Level4::Level4(bool random, string file_name): random{random}, 
    file_name{file_name} { blocks.clear(); }


Level4::~Level4() {}


Block *Level4::next_block(int index) {
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
    } else if ((streak > 0) && (streak % 5 == 0)) {
        return new lvl4Block{true};
    } else if (blocks[num] == 'I') {
        return new iBlock{true};
    }
}



int Level4::getlvl() { return cur_lvl; }


bool Level4::israndom() { return random; }


string Level4::getfile() { return file_name; }


void Level4::getblock(){
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


void Level4::set_streak(int st) { streak = streak; }


void Level4::inc_streak() { streak += 1; }
