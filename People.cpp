#include"People.h"


PEOPLE::PEOPLE(int side)
//构造函数
{
	nativeSide = side;
}

PEOPLE::~PEOPLE()
{
}

int PEOPLE::luozi(BOARD* board)
{
	CURSOR cur;
	COORDINATE coor;

	int action = 0;	//是否落子，落子才交换棋权，移动位置不交换。
	while (action == 0) {
		//更新光标
		//上一轮的新的变成这一轮的旧的
		cur.oldX = board->nativeCur.newX;
		cur.oldY = board->nativeCur.newY;
		system("cls");
		board->show();
		char decide;
		if (nativeSide == 1)
		{
			cout << "玩家●请落子，w/s/a/d控制方向，j落子,‘╋ ’表示可落子，‘**’表示不可落子: ";
		}
		else
		{
			cout << "玩家○请落子，w/s/a/d控制方向，j落子,‘╋ ’表示可落子，‘**’表示不可落子: ";

		}

		decide = _getch();  //控制台从键盘获得一个字符
		switch (decide)   //控制
		{
		case 'w':  //上
			cur.newX = (cur.oldX - 1 + MAX_ROW) % MAX_ROW;  //使光标纵坐标-1，但不能超出棋盘限制，循环
			cur.newY = cur.oldY;
			board->updateCursor(cur);	//更新光标
			break;
		case 's':  //下
			cur.newX = (cur.oldX + 1 + MAX_ROW) % MAX_ROW;
			cur.newY = cur.oldY;
			board->updateCursor(cur);
			break;
		case 'a':  //左
			cur.newX = cur.oldX;
			cur.newY = (cur.oldY - 1 + MAX_COL) % MAX_COL;
			board->updateCursor(cur);
			break;
		case 'd':  //右
			cur.newX = cur.oldX;
			cur.newY = (cur.oldY + 1 + MAX_COL) % MAX_COL;
			board->updateCursor(cur);
			break;
		case 'j':   //落子
			coor.x = cur.oldX;
			coor.y = cur.oldY;
			coor.side = nativeSide;
			board->add(coor);	//落子
			action = 1;	//表示已经落子，可以交换棋权
			break;
		}

	}
	system("cls");
	board->show();
	return 0;
}
