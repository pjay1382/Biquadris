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
        int get_lvl() override;
        bool is_random() override;
        std::string get_file() override;
        void get_block() override;
        void set_streak(int st);
        void inc_streak();
};

#endif


