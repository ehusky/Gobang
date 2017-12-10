#pragma once
# include<iostream>
# include<vector>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define MAX_ROW 20
#define MAX_COL 20

//坐标
typedef struct
{
	//标识坐标
	int x;
	int y;
	//标识战队,1:BLACK/2:WHITE/0:DEFAULT
	int side;
} COORDINATE;

//光标
typedef struct
{
	//旧坐标
	int oldX;
	int oldY;
	//新坐标
	int newX;
	int newY;
} CURSOR;

class BOARD
	//用来记录并更新棋盘信息
{
public:
	BOARD();
	~BOARD();
	int add(COORDINATE coor);	//存储棋子坐标
	int updateCursor(CURSOR cur);	//更新光标位置
	int show();	//打印棋盘
	CURSOR nativeCur;	//当前光标位置
	COORDINATE nativeCoor;	//落子位置
	int chessBoard[MAX_ROW][MAX_COL];	//棋盘信息
	int cursor[MAX_ROW][MAX_COL];	//光标盘信息
private:
	//数据记录
	int blacks;	//黑子个数
	int whites;	//白子个数
	//存储黑子
	vector<COORDINATE> BLACK;
	//存储白子
	vector<COORDINATE> WHITE;
};