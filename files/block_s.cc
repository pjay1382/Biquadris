#include "block.h"
#include "block_s.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        ".SS.",
        "SS.."
};

vector<string> rotate2 {
        "....",
        "S...",
        "SS..",
        ".S.."
};

vector<vector<string>> sBlock::sBlockRotations = {rotate1, rotate2, rotate1, rotate2};

sBlock::sBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char sblock::get_block_type() { return 'S'; }

vector<vector<string>> sBlock::get_block() { return sBlockRotations; }

sBlock::~sBlock() {}
