#ifndef EFFECTS_H
#define EFFECTS_H

#include "board.h"

class Effects: public Board {
    protected:
        Board *board;
    public:
        Effects(Board *board);
        void add_effect(Gameboard *g) override;
        virtual ~Effects();
}

#endif
