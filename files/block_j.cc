#include "jBlock.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 { // no rotation
        "....",
        "....",
        "J...",
        "JJJ."
};

vector<string> rotate2 { // rotate 90 degrees clockwise
        "....",
        "JJ..",
        "J...",
        "J..."
};

vector<string> rotate3 { // rotate 180 degrees clockwise
        "....",
        "....",
        "JJJ.",
        "..J."
};

vector <string> rotate4 { // rotate 270 degrees clockwise
        "....",
        ".J..",
        ".J..",
        "JJ.."
};

const vector<vector<string>> jBlock::jBlockRotations = {rotate1, rotate2, rotate3, rotate4};

jBlock::jBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char jblock::get_block_type() { return 'J'; }

vector<vector<string>> jBlock::get_block() { return jBlockRotations; }

jBlock::~jBlock() {}
