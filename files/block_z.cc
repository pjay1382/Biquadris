#include "block.h"
#include "block_z.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> rotate1 {
        "....",
        "....",
        "ZZ..",
        ".ZZ."
};

vector<string> rotate2 {
        "....",
        ".Z..",
        "ZZ..",
        "Z..."
};

vector<vector<string>> zBlock::zBlockRotations = {rotate1, rotate2, rotate1, rotate2};

zBlock::zBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char zBlock::get_block_type() { return 'Z'; }

vector<vector<string>> zBlock::get_block() { return zBlockRotations; }

zBlock::~zBlock() {}
