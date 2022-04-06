#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <string>


class Block {
    protected:
        int col;
        int row;
        int rotate;
        bool heavy_level;
        bool heavy_effect;

    public:
        Block(int col, int row, int rotate, bool heavy_level, bool heavy_effect);
        virtual ~Block();
        int get_row();
        int get_col();
        int get_rotate();
        bool get_heavy_level();
        bool get_effect_heavy();
        void set_row(int r);
        void set_col(int c);
        void set_rotate(int rot);
        void set_effect_heavy(bool eh);
        void set_level_heavy(bool lh);
        virtual std::vector<std::vector<std::string>> get_block() = 0;
        virtual char get_block_type() = 0;
	std::vector<std::string> getpreview();
};

#endif
