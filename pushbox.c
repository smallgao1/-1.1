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
	//�õ�һ������̨������
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//�����Ϣ�ṹ��
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(houtput, &cursorinfo);
	cursorinfo.bVisible = false;

	//���ù����Ϣ
	SetConsoleCursorInfo(houtput, &cursorinfo);
}


int WelcomePage()
{
	int i = 0;
	system("title PushBox");
	system("mode con cols=80 lines=30");
	system("cls");
	system("color 0E");//������ɫ ǰ������ɫ
	disdisplayInfo();//���ع��
	SetPos(10, 10);
	printf("\t\t Welcome to play box!\n\n");
	printf("\t\t Person:��  Wall:�� Box: ��  Target:��  Reach target����\n");
	printf("\t\t Up:��\n\t\t Down:��\n\t\t Left:�� \n\t\t Right:��\n\n");
	printf("\t\t Press number 1 to start new game\n\t\t\n");
	printf("\t\t Press number 2 to choose level\n\t\t\n"); 
	printf("\t\t Press number 3 to quit from game\n\t\t\n");
	printf("\t\t Press right number to continue:");
	while (1)
	{
		i = getchar();//iΪ��һ���ַ�
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
	if (iCh == '1')//��ʼ��һ����Ϸ
	{
		GetLevel1();
	}
	else if (iCh == '2') //��ʼѡ�ؿ�
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
	else if (iCh == '3')//�˳�
	{
		system("cls");
		system("color 0C");
		SetPos(26, 15);
		exit(0);
	}
}

//��һ��
void GetLevel1()
{
	int aimap2[14][16] = {0};//��ʾԭʼ��ͼ�о�����������޸� ΪʲôҪ��4�С�16����
	int i = 0, j = 0,boxcount=0;
	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
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
/*�ڶ���*/
void  GetLevel2() {
	int  aiMap2[14][16] = {0};/*��ʾԭʼ��ͼ*/
	int  i, j, iSum = 0; /*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*��¼���Ӹ���*/
				iSum++;
		}

	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel3���������������
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 2) != KEY_RETURN)
		GetLevel3();
}

/*������*/
void  GetLevel3() {
	int  aiMap2[14][16];/*��ʾԭʼ��ͼ*/
	int  i, j, iSum = 0;/*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*��¼���Ӹ���*/
				iSum++;
		}

	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel5��������������
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 3) != KEY_RETURN)
		GetLevel4();
}
/*���Ĺ�*/
void  GetLevel4() {
	int  aiMap2[14][16] = {0};/*��ʾԭʼ��ͼ*/
	int  i, j, iSum = 0;/*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN)/*��¼���Ӹ���*/
				iSum++;
		}
	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel7������������߹�
	*/
	PlayGame(aiMap, aiMap2, iSum, 4);
}

/*
* @brief  ����Ϸ
* @param  ԭʼ��ͼ  ���Ƶ�ԭʼ��ͼ  ���ӵ�����  �ؿ���
*/
int PlayGame(int aimap[][16], int aimap2[][16],int boxcount, int level)
{
	int i, j;
	int perx, pery;//�˵�����
	DIR dir=NO;
	int finpunumber;//��������Ŀ��ĸ���
	int ret = 0;
	while (1)
	{
		ret = 0;
		dir = NO;
		//�ҵ��˵�λ��
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
				break;//��ʱ i ,j�����˵�����
		}
		perx = i;
		pery = j;
		finpunumber = PrintMap(aimap, level);
		if (finpunumber == boxcount)//������ɷ���
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
* @brief ���ӵ��ƶ�
* @param ԭʼ���飬�����飬�˵����� perx,pery, ����
*/
void MoveBox(int aimap[][16], int aimap2[][16], int px, int py, DIR dir)
{
	//	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	int x1=0, y1=0;//��dir�������һ��λ������
	int x2=0, y2=0;//��dir����� �� �� һ��λ������
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
	//�Ե�ͼ���в���
	//�ж���һ��Ҫ�ߵ�λ��
//	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	switch (aimap[x1][y1])
	{
	case WALL://��һλ����1ǽ����ǽ
		break;
	case TARGET://��һλ���� 3��Ŀ�ĵ� �� 2�յ�
	case SPACE://���λ�þͱ���ˣ�������ռ�õĳ�ʼλ����ʲô��ȥ�ж�
		aimap[x1][y1] = PERSON;//���ƶ�����һ��λ��
		//��ֻ��վ�ڳ�ʼλ���� �� ��Ŀ�ĵ� �յ���
		if (aimap2[px][py] ==  SPACE|| aimap2[px][py] == PERSON ||aimap2[px][py] == BOX)
		{
			aimap[px][py] = SPACE;
		}
		else if (aimap2[px][py] == TARGET|| aimap2[px][py] == TARGET_IN)
		{
			aimap[px][py] = TARGET;
		}
		break;
//	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	case BOX://��һλ����4���ӻ�����װ�����ӵ�5Ŀ�ĵ�
	case TARGET_IN:
		if (aimap[x2][y2] == WALL|| aimap[x2][y2] == BOX || aimap[x2][y2] == TARGET_IN )//���ӵ���һλ���� 1ǽ ���� 4���� 5�������ӵ�Ŀ��
		{
			break;//����
		}
		else if (aimap[x2][y2] == SPACE) //���ӵ���һλ����2�յ�
		{
			aimap[x2][y2] = BOX;
			aimap[x1][y1] = PERSON;
		}
		else if (aimap[x2][y2] == TARGET)//���ӵ���һ��Ŀ����3��Ŀ�ĵ�
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
* @brief��ӡ��ͼ ÿһ�����嶼ռ�������ַ�
* @param ��ͼ���� �ؿ���
* @retval ������Ŀ�ĵصĸ���
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
				printf("  ");    //1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
				break;
			case 1:
				SelectColor(0x0E);//�ҵ��뷨�������Ƕ�ռ�����ַ���Ȼ����൱�ڶ��ǿ��ַ�
				printf("ǽ");//ǽ
				break;
			case 2:
				printf("  ");//�յ�
				break;
			case 3:
				SelectColor(0x0B);//Ŀ�ĵ�
				printf("��");
				break;
			case 4:
				SelectColor(0x0B);//����
				printf("��");
				break;
			case 5://��������Ŀ�ĵ�ʱ��ʾ
				finpushnumber++;
				SelectColor(0x09);//����
				printf("��");
				break;
			case 6:                /*С��*/
				SelectColor(0x0A);
				printf("��");
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
	return finpushnumber;//�����Ѿ�����Ŀ�����ӵظ���

}
//ѡ��ǰ��������ɫ
void SelectColor(int color)
{
	HANDLE stdouthandle = GetStdHandle((STD_OUTPUT_HANDLE));//��ȡ��׼����ľ��
	SetConsoleTextAttribute(stdouthandle, color);
}
