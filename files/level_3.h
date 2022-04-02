#ifndef Level_3_H
#define Level_3_H

#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"


class Level3 : public Level {
    int cur_lvl = 3;
    bool random = true;
    std::ifstream inp;
    std::string file_name;

    public:
        Level3(bool random, std::string file_name = "");
        ~Level3() override;
        Block *next_block(int index) override;
        int get_lvl() override;
        bool is_random() override;
        std::string get_file() override;
        void get_block() override;
};

#endif


