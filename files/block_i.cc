#include "block.h"
#include "block_i.h"
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "....",
        "IIII"
};

vector<string> rotate2 {
        "I...",
        "I...",
        "I...",
        "I..."
};

vector<vector<string>> iBlock::iBlockRotations = {rotate1, rotate2, rotate1, rotate2};

iBlock::iBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char iBlock::get_block_type() { return 'I'; }

vector<vector<string>> iBlock::get_block() { return iBlockRotations; }

iBlock::~iBlock() {}
