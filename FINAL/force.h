#ifndef FORCE_H
#define FORCE_H

#include "effects.h"
#include "gameboard.h"
#include <memory>

class Force: public Effects {
    char block_type;
    public:
        Force(std::shared_ptr<Board> board, char block_type);
        void add_effect(Gameboard &g) override;
        ~Force();
};

#endif

