#ifndef BLOCK_LVL4_H
#define BLOCK_LVL4_H
#include "block.h"
#include <string>
#include <vector>

class lvl4Block : public Block {
        static std::vector<std::vector<std::string>> lvl4BlockRotations;

        public:
                lvl4Block();
                virtual char get_block_type() override;
                virtual std::vector<std::vector<std::string>> get_block() override;
                virtual ~lvl4Block() override;
};

#endif
