#ifndef BLIND_H
#define BLIND_H

#include "effects.h"
#include "board.h"


class Blind: public Effects {

    public:
        Blind(Board *board);
        void add_effect(Gameboard &g) override;
        ~Blind();
};

#endif

