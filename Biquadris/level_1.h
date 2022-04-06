#ifndef Level_1_H
#define Level_1_H

#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"


class Level1 : public Level {
    int cur_lvl = 1;
    bool random = true;
    std::ifstream inp;
    std::string file_name;

    public:
        Level1(bool random, std::string file_name = "");
        ~Level1() override;
        Block *next_block(int index) override;
        int getlvl() override;
        bool israndom() override;
        std::string getfile() override;
        void getblock() override;
};

#endif


