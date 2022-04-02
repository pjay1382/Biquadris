#include "block.h"
#include "block_l.h"
#include <string>
#include <vector>
using namespace std;

vector<string> lrotate1 {
        "....",
        "....",
        "..L.",
        "LLL."
};

vector<string> lrotate2 {
        "....",
        "L...",
        "L...",
        "LL.."
};

vector<string> lrotate3 {
        "....",
        "....",
        "L...",
        "LLL."
};

vector <string> lrotate4 {
        "....",
        "LL..",
        ".L..",
        ".L.."
};

vector<vector<string>> lBlock::lBlockRotations = {lrotate1, lrotate2, lrotate3, lrotate4};

lBlock::lBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char lBlock::get_block_type() { return 'L'; }

vector<vector<string>> lBlock::get_block() { return lBlockRotations; }

lBlock::~lBlock() {}
