#include<string>
#include<windows.h>

#include"Player.h"
#include "People.h"
#include"Judgement.h"
#include"Machine.h"
int main()
{
	//引导信息
	SetConsoleTitle(L"欢迎来到仉淑艳的五子棋，请选择模式"); // 设置窗口标题
	cout << "！！！欢迎来到仉淑艳的五子棋，请选择模式！！！" << endl << endl;
	cout << "	1 : 人人模式" << endl;
	cout << "	2/anykey : 人机模式" << endl;
	cout << "输入您的选择：";
	int mode;
	cin >> mode;
	//对象指针
	BOARD* board = new BOARD();
	JUDGE* jud = new JUDGE();
	//父类指针，可以视情况指向子类对象
	PLAYER* player1;
	PLAYER* player2;
	//选手一为人，初始化时指定side
	player1 = new PEOPLE(1);
	//根据mode选择选手二
	if (mode == 1)
	{
		player2 = new PEOPLE(2);
	}
	else {
		player2 = new MACHINE(2);;
	}
	//直到分出输赢
	while (true)
	{
		player1->luozi(board);
		if (jud->decide(board) == 1)
			//产生了结果
		{
			break;
		}
		player2->luozi(board);
		if (jud->decide(board) == 1)
			//产生了结果
		{
			break;
		}
	}
	cin >> mode;//暂停一下
	return 0;
}