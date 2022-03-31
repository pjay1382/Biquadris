
#include "block.h"


Block::Block(int col, int row, int rotate, bool heavy_level, bool heavy_effect):
    col{col}, row{row}, rotate{rotate}, heavy_level{heavy_level}, 
    heavy_effect{heavy_effect} {}


Block::~Block() {}


int Block::get_row() { return row; }

int Block::get_col() { return col; } 

int Block::get_rotate() { return rotate; }

bool Block::heavy_level?() { return heavy_level; }

bool Block::effect_heavy?() { return heavy_effect; }

void Block::set_row(int r) { row = r; }

void Block::set_col(int c) { col = c; }

void Block::set_rotate(int rot) { rotate = rot; }

void Block::effect_heavy(bool eh) { heavy_effect = eh; }

void Block::effect_level(bool lh) { heavy_level = lh; }
