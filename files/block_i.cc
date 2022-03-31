#include "block.h"
#include "block_j.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "J...",
        "JJJ."
};

vector<string> rotate2 {
        "....",
        "JJ..",
        "J...",
        "J..."
};

vector<string> rotate3 {
        "....",
        "....",
        "JJJ.",
        "..J."
};

vector <string> rotate4 {
        "....",
        ".J..",
        ".J..",
        "JJ.."
};

vector<vector<string>> jBlock::jBlockRotations = {rotate1, rotate2, rotate3, rotate4};

jBlock::jBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char jblock::get_block_type() { return 'J'; }

vector<vector<string>> jBlock::get_block() { return jBlockRotations; }

jBlock::~jBlock() {}
