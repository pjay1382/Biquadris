#include "block.h"
#include "block_z.h"
#include <string>
#include <vector>
using namespace std;

vector<string> zrotate1 {
        "....",
        "....",
        "ZZ..",
        ".ZZ."
};

vector<string> zrotate2 {
        "....",
        ".Z..",
        "ZZ..",
        "Z..."
};

vector<vector<string>> zBlock::zBlockRotations = {zrotate1, zrotate2, zrotate1, zrotate2};

zBlock::zBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char zBlock::get_block_type() { return 'Z'; }

vector<vector<string>> zBlock::get_block() { return zBlockRotations; }

zBlock::~zBlock() {}
