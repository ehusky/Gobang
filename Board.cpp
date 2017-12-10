# include"Board.h"

BOARD::BOARD()
//构造函数，初始化值
{
	//黑子和白子个数都置零
	blacks = 0;
	whites = 0;
	//光标置棋盘中间
	nativeCur.oldX = MAX_ROW / 2;
	nativeCur.oldY = MAX_COL / 2;
	nativeCur.newX = MAX_ROW / 2;
	nativeCur.newY = MAX_COL / 2;
	//当前落子初始为棋盘中间
	nativeCoor.x = MAX_ROW / 2;
	nativeCoor.y = MAX_COL / 2;
	nativeCoor.side = 0;
	//初始化棋盘和光标盘
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			chessBoard[i][j] = 0;	//置空
			cursor[i][j] = 0;	//置空
		}
	}
	//显示光标
	cursor[nativeCur.newX][nativeCur.newY] = 1;
}

BOARD::~BOARD()
{
}

int BOARD::add(COORDINATE coor)
//将coor添加到棋盘中
{
	//更新落子位置
	nativeCoor = coor;
	//根据战队添加到相应的vector，并更新长度(可以用来重现过程)
	if (coor.side == 1)
		//存储黑子
	{
		BLACK.push_back(coor);
		blacks++;
	}
	else {
		//存储白子
		WHITE.push_back(coor);
		whites++;
	}
	//显示到棋盘
	chessBoard[coor.x][coor.y] = coor.side;
	return 0;
}

int BOARD::updateCursor(CURSOR cur)
//更新光标的位置
{
	nativeCur = cur;
	//清除过去光标
	cursor[cur.oldX][cur.oldY] = 0;
	//显示现在光标
	cursor[cur.newX][cur.newY] = 1;
	return 0;
}

int BOARD::show() {
	//显示棋盘信息
	SetConsoleTitle(L"仉淑艳的五子棋 请落子 ‘╋ ’表示可落子，‘**’表示不可落子"); // 设置窗口标题
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	SMALL_RECT rc = { 0,0, 45, 100}; // 重置窗口位置和大小
	SetConsoleWindowInfo(hOut, true, &rc);
	//SetConsoleScreenBufferSize(hOut, size);
	cout << endl;
	for (int i = 0; i < MAX_ROW; i++)
	{
		cout << endl;
		cout << "  ";
		for (int j = 0; j < MAX_COL; j++)
		{
			if (cursor[i][j] == 1)
				//光标优先
			{
				if (chessBoard[i][j] == 0)
					//当前位置可以落子
				{
					cout << " ╋  ";
				}
				else
					//当前位置不可以落子
				{
					cout << " ** ";
				}

			}
			else
				//棋盘次之
			{
				switch (chessBoard[i][j])
				{
				case 0:
					cout << " · ";
					break;
				case 1:
					cout << " ● ";
					break;
				case 2:
					cout << " ○ ";
					break;
				default:
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

