#ifndef Level_2_H
#define Level_2_H

#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"


class Level2 : public Level {
    int cur_lvl = 2;
    bool random = true;
    std::ifstream inp;
    std::string file_name;

    public:
        Level2(bool random, std::string file_name = "");
        ~Level2() override;
        Block *next_block(int index) override;
        int getlvl() override;
        bool israndom() override;
        std::string getfile() override;
        void getblock() override;
};

#endif


