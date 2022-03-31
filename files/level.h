#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "block.h"
#include "block_j.h"
#include "block_s.h"
#include "block_t.h"
#include "block_i.h"
#include "block_z.h"
#include "block_l.h"
#include "block_o.h"
#include "block_lvl4.h"


class Level {
    protected:
        vector<char> blocks;

    public:
        virtual ~Level();
        virtual Block *next_block(int index) = 0;
        virtual int lvl?() = 0;
        virtual bool random?() = 0;
        virtual std::string file?() = 0;
        virtual void get_block() = 0;
};

