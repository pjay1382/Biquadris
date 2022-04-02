#ifndef HEAVY_H
#define HEAVY_H

#include "effects.h"
#include "gameboard.h"


class Heavy: public Effects {

    public:
        Heavy(Board *board);
        void add_effect(Gameboard &g) override;
        ~Heavy();
};

#endif

