#ifndef BLOCK_T_H
#define BLOCK_T_H
#include "block.h"
#include <string>
#include <vector>

class tBlock : public Block {
        static std::vector<std::vector<std::string>> tBlockRotations;

        public:
                tBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~tBlock() override;
};

#endif
