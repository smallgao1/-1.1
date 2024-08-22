#include "pushbox.h"

void SetPos(short x, short y)
{
	COORD pos = { x,y };
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput, pos);
}
void disdisplayInfo()
{
	//得到一个控制台输出句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//光标信息结构体
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(houtput, &cursorinfo);
	cursorinfo.bVisible = false;

	//设置光标信息
	SetConsoleCursorInfo(houtput, &cursorinfo);
}


int WelcomePage()
{
	int i = 0;
	system("title PushBox");
	system("mode con cols=80 lines=30");
	system("cls");
	system("color 0E");//背景黑色 前景淡黄色
	disdisplayInfo();//隐藏光标
	SetPos(10, 10);
	printf("\t\t Welcome to play box!\n\n");
	printf("\t\t Person:♀  Wall:▓ Box: ●  Target:○  Reach target：☆\n");
	printf("\t\t Up:↑\n\t\t Down:↓\n\t\t Left:← \n\t\t Right:→\n\n");
	printf("\t\t Press number 1 to start new game\n\t\t\n");
	printf("\t\t Press number 2 to choose level\n\t\t\n"); 
	printf("\t\t Press number 3 to quit from game\n\t\t\n");
	printf("\t\t Press right number to continue:");
	while (1)
	{
		i = getchar();//i为第一个字符
		while ((getchar()) != '\n');
		if (i >= 49 && i <= 51)
		{
			return i;
		}
		else
		{
			printf("\t\t Press right number to continue:");
		}
	}	
}

void DesignUI()
{
	int iCh;
	char cNum;
	iCh = WelcomePage();
	system("cls");
	SetPos(10, 10);
	if (iCh == '1')//开始第一关游戏
	{
		GetLevel1();
	}
	else if (iCh == '2') //开始选关卡
	{
		resel :
		printf("\n\t\t Please input level!(From 1 to 4):\n");
		printf("\n\t\t Intput 0 shows quit selection:");
		cNum = getchar();
		while ((getchar()) != '\n');
		switch (cNum)
		{
			case '0':
				system("cls");
				SetPos(13, 17);
				printf("already quit selection\n");
				Sleep(500);
				break;
			case '1':
				system("cls");
				GetLevel1();
				break;
			case '2':
				system("cls");
				GetLevel2();
				printf("                                                                    ");
				break;
			case '3':
				system("cls");
				GetLevel3();
				break;
			case '4':
				system("cls");
				GetLevel4();
				break;
			default:
				SetPos(13, 10);
				printf("Enter error!\n");
				system("cls");
				Sleep(500);
				goto resel;
				break;
		}
	}
	else if (iCh == '3')//退出
	{
		system("cls");
		system("color 0C");
		SetPos(26, 15);
		exit(0);
	}
}

//第一关
void GetLevel1()
{
	int aimap2[14][16] = {0};//表示原始地图感觉方便后续的修改 为什么要·4行·16列呢
	int i = 0, j = 0,boxcount=0;
	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	*/
	int aimap[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 3, 4, 2, 1, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 3, 4, 6, 4, 2, 2, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 3, 2, 4, 2, 4, 3, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 16; j++)
		{
			aimap2[i][j] = aimap[i][j];
			if (aimap[i][j] == TARGET || aimap[i][j] == TARGET_IN)
			{
				boxcount++;//
			}
		}
	}
	if (PlayGame(aimap, aimap2, boxcount, 1) != KEY_RETURN)
	{
		GetLevel2();
	}
}
/*第二关*/
void  GetLevel2() {
	int  aiMap2[14][16] = {0};/*表示原始地图*/
	int  i, j, iSum = 0; /*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	*/
	int aiMap[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 1, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 1, 1, 2, 4, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 1, 3, 3, 3, 1, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 1, 2, 4, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0 },
		{ 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 6, 2, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++) {
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*记录箱子个数*/
				iSum++;
		}

	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel3函数，进入第三关
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 2) != KEY_RETURN)
		GetLevel3();
}

/*第三关*/
void  GetLevel3() {
	int  aiMap2[14][16];/*表示原始地图*/
	int  i, j, iSum = 0;/*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	*/
	int aiMap[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 0, 0 },
		{ 0, 0, 1, 2, 4, 2, 1, 1, 1, 1, 4, 2, 2, 1, 0, 0 },
		{ 0, 0, 1, 2, 2, 4, 3, 3, 3, 3, 2, 4, 2, 1, 0, 0 },
		{ 0, 0, 1, 1, 2, 2, 2, 2, 1, 2, 6, 2, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++) {
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*记录箱子个数*/
				iSum++;
		}

	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel5函数，进入第五关
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 3) != KEY_RETURN)
		GetLevel4();
}
/*第四关*/
void  GetLevel4() {
	int  aiMap2[14][16] = {0};/*表示原始地图*/
	int  i, j, iSum = 0;/*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	*/
	int aiMap[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 3, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 2, 2, 4, 3, 3, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 2, 2, 4, 2, 1, 5, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 2, 1, 1, 4, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 6, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++) {
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*记录箱子个数*/
				iSum++;
		}
	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel7函数，进入第七关
	*/
	PlayGame(aiMap, aiMap2, iSum, 4);
}

/*
* @brief  玩游戏
* @param  原始地图  复制的原始地图  箱子的数量  关卡数
*/
int PlayGame(int aimap[][16], int aimap2[][16],int boxcount, int level)
{
	int i, j;
	int perx, pery;//人的坐标
	DIR dir=NO;
	int finpunumber;//箱子推入目标的个数
	int ret = 0;
	while (1)
	{
		ret = 0;
		dir = NO;
		//找到人的位置
		for (i = 0; i < 14; i++)
		{
			for (j = 0; j < 16; j++)
			{
				if (aimap[i][j] == PERSON)
				{
					goto over;
				}
			}
		over:
			if (aimap[i][j] == PERSON)
				break;//此时 i ,j即是人的坐标
		}
		perx = i;
		pery = j;
		finpunumber = PrintMap(aimap, level);
		if (finpunumber == boxcount)//箱子完成放置
		{
			SetPos(31, 8);
			SelectColor(0X0A);
			printf("YOU PASS THE FIRST LEVEL \n");
			Sleep(3000);
			return 0;
		}
		else
		{
			if (KEY_PRESS(VK_ESCAPE))
			{
				return KEY_RETURN;
			}
			else if (KEY_PRESS(VK_SPACE))
			{
				return KEY_NEXT;
			}
			else if (KEY_PRESS(VK_UP))
			{
				dir = UP;
			}
			else if (KEY_PRESS(VK_DOWN))
			{
				dir = DOWN;
			}
			else if (KEY_PRESS(VK_LEFT))
			{
				dir = LEFT;
			}
			else if (KEY_PRESS(VK_RIGHT))
			{
				dir = RIGHT;
			}

	    }
		 MoveBox(aimap, aimap2, perx, pery, dir);
	}
}
/*
* @brief 箱子的移动
* @param 原始数组，新数组，人的坐标 perx,pery, 方向
*/
void MoveBox(int aimap[][16], int aimap2[][16], int px, int py, DIR dir)
{
	//	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	int x1=0, y1=0;//沿dir方向的下一个位置坐标
	int x2=0, y2=0;//沿dir方向的 下 下 一个位置坐标
	switch (dir)
	{
	case UP:
		x1 = px - 1;
		y1 = py;
		x2 = px - 2;
		y2 = py;
		break;
	case DOWN:
		x1 = px + 1;
		y1 = py;
		x2 = px + 2;
		y2 = py;
		break;
	case LEFT:
		x1 = px;
		y1 = py - 1;
		x2 = px;
		y2 = py - 2;
		break;
	case RIGHT:
		x1 = px;
		y1 = py + 1;
		x2 = px;
		y2 = py + 2;
		break;
	default:
		break;
	}
	//对地图进行操作
	//判断下一步要走的位置
//	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	switch (aimap[x1][y1])
	{
	case WALL://下一位置是1墙体日墙
		break;
	case TARGET://下一位置是 3空目的地 或 2空地
	case SPACE://这个位置就变成人，根据人占用的初始位置是什么再去判断
		aimap[x1][y1] = PERSON;//人移动到下一个位置
		//人只能站在初始位置是 人 空目的地 空地上
		if (aimap2[px][py] ==  SPACE|| aimap2[px][py] == PERSON ||aimap2[px][py] == BOX)
		{
			aimap[px][py] = SPACE;
		}
		else if (aimap2[px][py] == TARGET|| aimap2[px][py] == TARGET_IN)
		{
			aimap[px][py] = TARGET;
		}
		break;
//	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
	case BOX://下一位置是4箱子或者是装了箱子的5目的地
	case TARGET_IN:
		if (aimap[x2][y2] == WALL|| aimap[x2][y2] == BOX || aimap[x2][y2] == TARGET_IN )//箱子的下一位置是 1墙 或者 4箱子 5放入箱子的目标
		{
			break;//不动
		}
		else if (aimap[x2][y2] == SPACE) //箱子的下一位置是2空地
		{
			aimap[x2][y2] = BOX;
			aimap[x1][y1] = PERSON;
		}
		else if (aimap[x2][y2] == TARGET)//箱子的下一个目标是3空目的地
		{
			aimap[x2][y2] = TARGET_IN;
			aimap[x1][y1] = PERSON;
		}
		if (aimap2[px][py] == SPACE || aimap2[px][py] == PERSON || aimap2[px][py] == BOX)
		{
			aimap[px][py] = SPACE;
		}
		else if (aimap2[px][py] == TARGET || aimap2[px][py] == TARGET_IN)
		{
			aimap[px][py] = TARGET;
		}
		break;
	}
}

/*
* @brief打印地图 每一个物体都占用两个字符
* @param 地图数组 关卡数
* @retval 箱子在目的地的个数
*/
int PrintMap(int aimap[][16], int level)
{
	int i = 0; 
	int j = 0;
	int finpushnumber = 0;
	SetPos(0, 0);
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j< 16; j++)
		{
			switch (aimap[i][j])
			{
			case 0:
				printf("  ");    //1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
				break;
			case 1:
				SelectColor(0x0E);//我的想法是让他们都占两个字符，然后就相当于都是宽字符
				printf("墙");//墙
				break;
			case 2:
				printf("  ");//空地
				break;
			case 3:
				SelectColor(0x0B);//目的地
				printf("○");
				break;
			case 4:
				SelectColor(0x0B);//箱子
				printf("●");
				break;
			case 5://箱子推至目的地时显示
				finpushnumber++;
				SelectColor(0x09);//箱子
				printf("☆");
				break;
			case 6:                /*小人*/
				SelectColor(0x0A);
				printf("♀");
				break;
			}
		}
		printf("\n");
	}
	SetPos(30, 4);
	SelectColor(0x0F);
	printf("\tYou are in Level %d!\n", level);
	SetPos(30, 5);
	printf("\tPress arrow keys to play the game!\n");
	SetPos(30, 6);
	printf("\tpress SPASE to the next level!\n");
	SetPos(30, 7);
	printf("\tpress ESC to return the home page!\n");
	return finpushnumber;//返回已经放入目标箱子地个数

}
//选择前景背景颜色
void SelectColor(int color)
{
	HANDLE stdouthandle = GetStdHandle((STD_OUTPUT_HANDLE));//获取标准输出的句柄
	SetConsoleTextAttribute(stdouthandle, color);
}
