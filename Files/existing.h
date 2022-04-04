#ifndef EXISTING_H
#define EXISTING_H

class Existing {
	int row;
	bool removed;
	int lvl;
	public:
	Existing(int row, int lvl);
	~Existing();
	int getRow();
	void setRow(int ro);
	int getLevel();
	void setRemove(bool remove);
	bool getRemove();
};

#endif
