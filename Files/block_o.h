#ifndef BLOCK_O_H
#define BLOCK_O_H
#include "block.h"
#include <string>
#include <vector>

class oBlock : public Block {
        static std::vector<std::vector<std::string>> oBlockRotations;

        public:
                oBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~oBlock() override;
};

#endif
