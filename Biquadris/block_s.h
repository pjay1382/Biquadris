#ifndef BLOCK_S_H
#define BLOCK_S_H
#include "block.h"
#include <string>
#include <vector>

class sBlock : public Block {
        static std::vector<std::vector<std::string>> sBlockRotations;

        public:
                sBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~sBlock() override;
};

#endif
