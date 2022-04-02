#include "block.h"
#include "block_j.h"
#include <string>
#include <vector>
using namespace std;

vector<string> jrotate1 {
        "....",
        "....",
        "J...",
        "JJJ."
};

vector<string> jrotate2 {
        "....",
        "JJ..",
        "J...",
        "J..."
};

vector<string> jrotate3 {
        "....",
        "....",
        "JJJ.",
        "..J."
};

vector <string> jrotate4 {
        "....",
        ".J..",
        ".J..",
        "JJ.."
};

vector<vector<string>> jBlock::jBlockRotations = {jrotate1, jrotate2, jrotate3, jrotate4};

jBlock::jBlock(bool heavy_effect) : Block(0, 0, 0, false, heavy_effect) {}

char jBlock::get_block_type() { return 'J'; }

vector<vector<string>> jBlock::get_block() { return jBlockRotations; }

jBlock::~jBlock() {}
