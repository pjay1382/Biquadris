#include "block.h"
#include "block_lvl4.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "....",
        "*..."
};

vector<vector<string>> lvl4Block::lvl4BlockRotations = {rotate1, rotate1, rotate1, rotate1};

lvl4Block::lvl4Block() : Block(5, 0, 0, false, false) {}

char lvl4Block::get_block_type() { return '*'; }

vector<vector<string>> jBlock::get_block() { return jBlockRotations; }

lvl4Block::~lvl4Block() {}
