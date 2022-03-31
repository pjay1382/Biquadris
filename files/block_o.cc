#include "block.h"
#include "block_o.h"
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

vector<vector<string>> oBlock::oBlockRotations = {rotate1, rotate2, rotate3, rotate4};

oBlock::oBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char oblock::get_block_type() { return 'O'; }

vector<vector<string>> oBlock::get_block() { return oBlockRotations; }

oBlock::~oBlock() {}
