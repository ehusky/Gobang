#pragma once
#include"Player.h"
# include"Board.h"

class PEOPLE : public PLAYER
{
public:
	PEOPLE(int side);	//构造函数
	~PEOPLE();
	int luozi(BOARD* board);	//落子
private:
};

