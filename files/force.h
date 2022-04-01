#ifndef FORCE_H
#define FORCE_H

#include "effects.h"
#include "board.h"


class Force: public Effects {
    char block_type;
    public:
        Force(Board *board);
        void add_effect(Gameboard &g) override;
        ~Force();
};

#endif

