#include"Judgement.h"


JUDGE::JUDGE()
{
}

JUDGE::~JUDGE()
{
}


int JUDGE::decide(BOARD* board) {
	//判断当前落子情况下有没有胜局，当前落子位置再BOARD里面有存储
	//胜局只能出现在当前落子位置为圆心的半径为4的圆周里面
	//遍历当前点周边，在同一条线第上找两边第一个和当前点落子不同的位置，若长度等于5，则赢
	//返回值0：继续，1:停止
	int vertical = 1;	//竖直方向
	int level = 1;	//水平方向
	int diagonal = 1;	//主对角线方向
	int sDiagonal = 1;//副对角线方向
	int m = board->nativeCoor.x;
	int n = board->nativeCoor.y;
	int side = board->nativeCoor.side;
	for (int i = 1; i <= 4; i++) //上
	{
		if (board->chessBoard[m - i][n] == side && m - i >=0)
			//当前m,n肯定不会越界，所以要限定变量不能越界
			vertical++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //下
	{
		if (board->chessBoard[m + i][n] == side && m + i < MAX_ROW)
			vertical++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //左
	{
		if (board->chessBoard[m][n - i] == side && n - i >= 0)
			level++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //右
	{
		if (board->chessBoard[m][n + i] == side && n + i < MAX_COL)
			level++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //左下
	{
		if (board->chessBoard[m + i][n - i] == side && n - i >= 0 && m + i < MAX_ROW)
			diagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //右上
	{
		if (board->chessBoard[m - i][n + i] == side && m - i >= 0 && n + i < MAX_COL)
			diagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //右下
	{
		if (board->chessBoard[m + i][n + i] == side && m + i < MAX_ROW && n + i < MAX_COL)
			sDiagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //左上
	{
		if (board->chessBoard[m - i][n - i] == side && m - i >= 0 && n - i >= 0)
			sDiagonal++;
		else
			break;
	}
	if (vertical == 5 || level == 5 || diagonal == 5 || sDiagonal == 5)
	{
		if (side == 1)
		{
			cout << "玩家●胜！！！" << endl;
			return 1;
		}
		else
		{
			cout << "玩家○胜！！！" << endl;
			return 1;
		}
	}
	//在没有输赢的情况下，如果没有地方可落子，则平局
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			//有子可落，返回0，表示继续
			if (board->chessBoard[i][j] == 0)
			{
				return 0;
			}
		}		
	}
	//无子可落，平局，返回3
	cout << "无子可落，平局！！！" << endl;
	return 1;
}