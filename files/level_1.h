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
    ifstream inp;
    std::string file_name;

    public:
        Level1(bool random, std::string file_name = "");
        ~Level1() override;
        Block *next_block(int index) override;
        int get_lvl() override;
        bool is_random() override;
        std::string get_file() override;
        void get_block() override;
};

#endif


