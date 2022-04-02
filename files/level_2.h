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
    ifstream inp;
    std::string file_name;

    public:
        Level2(bool random, std::string file_name = "");
        ~Level2() override;
        Block *next_block(int index) override;
        int get_lvl() override;
        bool is_random() override;
        std::string get_file() override;
        void get_block() override;
};

#endif

