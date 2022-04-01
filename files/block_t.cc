#include "block.h"
#include "block_t.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "TTT.",
        ".T.."
};

vector<string> rotate2 {
        "....",
        ".T..",
        "TT..",
        ".T.."
};

vector<string> rotate3 {
        "....",
        "....",
        ".T..",
        "TTT."
};

vector <string> rotate4 {
        "....",
        "T...",
        "TT..",
        "T..."
};

vector<vector<string>> tBlock::tBlockRotations = {rotate1, rotate2, rotate3, rotate4};

tBlock::tBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char tblock::get_block_type() { return 'T'; }

vector<vector<string>> tBlock::get_block() { return tBlockRotations; }

tBlock::~tBlock() {}
