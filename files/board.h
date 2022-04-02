#ifndef BOARD_H
#define BOARD_H

class Gameboard;

class Board {
    public:
        virtual void add_effect(Gameboard &g) = 0;
        virtual ~Board();
};


#endif
