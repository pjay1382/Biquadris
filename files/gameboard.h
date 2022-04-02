#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <vector>
#include <string>
class Gameboard: public Board {
    int columns;
    int rows;
    std::vector<std::vector<Cell>> board;
    std::vector<std::vector<Existing>> oldblocks;
    std::string name;
    bool random = true;
    bool iseffect = false;
    bool blind = false;
    bool force = false;
    bool heavy = false;
    bool isgameOver = false;
    Level*  level;
    int lvl;
    int curScore = 0;
    int highScore = 0;
    Block *curBlock = nullptr;
    Block *nextBlock = nullptr;
    public:
    Gameboard(int columns, int rows, std::string name, int lvl);
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
    int getscore();
    int set_highscore(int hiscore, bool get);
    std::string getName();
    int getSeteffectneeded(int effect);
    int getSetBlind(int eff_blind);
    int getSetHeavy(int eff_heavy);
    int getSetForce(int eff_force);
    virtual void add_effect(Gameboard &g) override;
    int getSetGameOver(int over);
    void remblock();
    vector<vector<Cell>>& getGameboardRef();
};
#endif
