#include "block.h"
#include "block_l.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "..L.",
        "LLL."
};

vector<string> rotate2 {
        "....",
        "L...",
        "L...",
        "LL.."
};

vector<string> rotate3 {
        "....",
        "....",
        "L...",
        "LLL."
};

vector <string> rotate4 {
        "....",
        "LL..",
        ".L..",
        ".L.."
};

vector<vector<string>> lBlock::lBlockRotations = {rotate1, rotate2, rotate3, rotate4};

lBlock::lBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char lBlock::get_block_type() { return 'L'; }

vector<vector<string>> lBlock::get_block() { return lBlockRotations; }

lBlock::~lBlock() {}
