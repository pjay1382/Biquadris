#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <vector>
#include <string>



class Gameboard {
    int columns;
    int rows;
    vector<vector<Cell>> board;
    vector<vector<Existing>> oldblocks;
    std::string name;
    bool random = true;
    bool effect? = false;
    bool blind = false;
    bool force = false;
    bool heavy = false;
    bool gameOver? = false;
    Level*  level;
    int lvl;
    int curScore = 0;
    int highScore = 0;
    Block *curBlock = nullptr;
    Block *nextBlock = nullptr;

    public:
    Gameboard(int columns, int rows,string name, int level);
    ~Gameboard();
    void build();
    void restart();
    void set(int row, int col, char block_piece);
    void unset(int row, int col);
    bool move(int left, int right, int rotate_pos);
    void addOldBlock(int lvl);
    void lvlChange(int lvl, string sequence);
    void adjustboard();
    void CurBlock(Block* current);
    void NextBlock(Block* next);
    Block* getCur();
    Block* getNext();
    Level* getLevel();
    int getLvl();
    int score?();
    int set_highscore(int hiscore, bool get);
    std::string getName();
    int effectneeded?(int effect);
    int blind?(int eff_blind);
    int heavy?(int eff_heavy);
    int force?(int eff_force);
    int GameOver?(int over);
    void remblock();
    vector<vector<Cell>>& getGameboardRef();
};

#endif
