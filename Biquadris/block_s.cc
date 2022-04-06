#include "block.h"
#include "block_s.h"
#include <string>
#include <vector>
using namespace std;

vector<string> srotate1 {
        "....",
        "....",
        ".SS.",
        "SS.."
};

vector<string> srotate2 {
        "....",
        "S...",
        "SS..",
        ".S.."
};

vector<vector<string>> sBlock::sBlockRotations = {srotate1, srotate2, srotate1, srotate2};

sBlock::sBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char sBlock::get_block_type() { return 'S'; }

vector<vector<string>> sBlock::get_block() { return sBlockRotations; }

sBlock::~sBlock() {}
