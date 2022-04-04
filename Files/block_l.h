#ifndef BLOCK_L_H
#define BLOCK_L_H
#include "block.h"
#include <string>
#include <vector>

class lBlock : public Block {
        static std::vector<std::vector<std::string>> lBlockRotations;

        public:
                lBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~lBlock() override;
};

#endif
