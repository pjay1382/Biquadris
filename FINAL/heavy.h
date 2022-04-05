#ifndef HEAVY_H
#define HEAVY_H

#include "effects.h"
#include "board.h"
#include <memory>

class Heavy: public Effects {

    public:
        Heavy(std::shared_ptr<Board> board);
        void add_effect(Gameboard &g) override;
        ~Heavy();
};

#endif

