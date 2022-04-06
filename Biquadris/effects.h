#ifndef EFFECTS_H
#define EFFECTS_H

#include <memory>
#include "board.h"

class Effects: public Board {
    protected:
        std::shared_ptr<Board> board;
    public:
        Effects(std::shared_ptr<Board> board);
        void add_effect(Gameboard &g) override;
        virtual ~Effects();
};

#endif
