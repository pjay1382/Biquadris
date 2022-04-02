#include "block.h"
#include "block_lvl4.h"
#include <string>
#include <vector>

vector<string> rotate1 {
        "....",
        "....",
        "....",
        "*..."
};

vector<vector<string>> lvl4Block::lvl4BlockRotations = {rotate1, rotate1, rotate1, rotate1};

lvl4Block::lvl4Block() : Block(5, 0, 0, false, false) {}

char lvl4Block::get_block_type() { return '*'; }

vector<vector<string>> lvl4Block::get_block() { return lvl4BlockRotations; }

lvl4Block::~lvl4Block() {}
