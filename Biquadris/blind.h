#ifndef BLIND_H
#define BLIND_H

#include "effects.h"
#include "board.h"
#include <memory>

class Blind: public Effects {

    public:
        Blind(std::shared_ptr<Board> board);
        void add_effect(Gameboard &g) override;
        ~Blind();
};

#endif

