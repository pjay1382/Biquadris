#include "block.h"
#include "block_o.h"
#include <string>
#include <vector>
using namespace std;

vector<string> orotate1 {
        "....",
        "....",
        "OO..",
        "OO.."
};

vector<vector<string>> oBlock::oBlockRotations = {orotate1, orotate1, orotate1, orotate1};

oBlock::oBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char oBlock::get_block_type() { return 'O'; }

vector<vector<string>> oBlock::get_block() { return oBlockRotations; }

oBlock::~oBlock() {}
