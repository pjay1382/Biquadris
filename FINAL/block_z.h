#ifndef BLOCK_Z_H
#define BLOCK_Z_H
#include "block.h"
#include <string>
#include <vector>

class zBlock : public Block {
        static std::vector<std::vector<std::string>> zBlockRotations;

        public:
                zBlock(bool heavy_effect);
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~zBlock() override;
};

#endif
