#include "existing.h"
using namespace std;

Existing::Existing(int row, int lvl): row{row}, lvl{lvl} {}

Existing::~Existing() {}

int Existing::getRow() { return row; }

void Existing::setRow(int ro) { row = ro; }

int Exsiting::getLevel() { return lvl; }

void Existing::setRemove(bool remove) { removed = remove; }

bool Existing::getRemove() { return removed; }
