#include "block.h"
#include "block_t.h"
#include <string>
#include <vector>
using namespace std;

vector<string> trotate1 {
        "....",
        "....",
        "TTT.",
        ".T.."
};

vector<string> trotate2 {
        "....",
        ".T..",
        "TT..",
        ".T.."
};

vector<string> trotate3 {
        "....",
        "....",
        ".T..",
        "TTT."
};

vector <string> trotate4 {
        "....",
        "T...",
        "TT..",
        "T..."
};

vector<vector<string>> tBlock::tBlockRotations = {trotate1, trotate2, trotate3, trotate4};

tBlock::tBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char tBlock::get_block_type() { return 'T'; }

vector<vector<string>> tBlock::get_block() { return tBlockRotations; }

tBlock::~tBlock() {}
