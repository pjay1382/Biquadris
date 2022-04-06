#ifndef BLOCK_I_H
#define BLOCK_I_H
#include "block.h"
#include <string>
#include <vector>

class iBlock : public Block {
        static std::vector<std::vector<std::string>> iBlockRotations;

        public:
                iBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~iBlock() override;
};

#endif
