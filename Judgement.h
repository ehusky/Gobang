#pragma once
#include"Board.h"

class JUDGE
{
public:
	JUDGE();
	~JUDGE();
	int decide(BOARD* board);	//判断在(X,Y)情况下有没有胜局。返回值0：继续，1/2：当前玩家胜利，3：平局
private:

};
