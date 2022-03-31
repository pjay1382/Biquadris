#ifndef BLOCK_J_H
#define BLOCK_J_H
#include "block.h"
#include <string>
#include <vector>

class jBlock : public Block {
        static std::vector<std::vector<std::string>> jBlockRotations;

        public:
                jBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~jBlock() override;
};

#endif
