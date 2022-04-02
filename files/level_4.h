#ifndef Level_4_H
#define Level_4_H

#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"


class Level4 : public Level {
    int cur_lvl = 4;
    int streak = 0;
    bool random = true;
    std::ifstream inp;
    std::string file_name;

    public:
        Level4(bool random, std::string file_name = "");
        ~Level4() override;
        Block *next_block(int index) override;
        int getlvl() override;
        bool israndom() override;
        std::string getfile() override;
        void getblock() override;
        void set_streak(int st);
        void inc_streak();
};

#endif


