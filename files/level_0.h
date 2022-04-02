#ifndef Level_0_H
#define Level_0_H

#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"


class Level0 : public Level {
    int cur_lvl = 0;
    bool random = false;
    ifstream inp;
    std::string file_name;

    public:
        Level0(bool random, std::string file_name = "");
        ~Level0() override;
        Block *next_block(int index) override;
        int get_lvl() override;
        bool is_random() override;
        std::string get_file() override;
        void get_block() override;
};

#endif

