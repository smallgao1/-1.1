#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

void test01()
{
	 //   0 = ��ɫ            
		//1 = ��ɫ                  
		//2 = ��ɫ                   
		//3 = ����ɫ				
		//4 = ��ɫ					
		//5 = ��ɫ									
		//6 = ��ɫ											
		//7 = ��ɫ									
		//8 = ��ɫ
		//9 = ����ɫ
		//A = ����ɫ
		//B = ��ǳ��ɫ
		//C = ����ɫ
		//D = ����ɫ
		//E = ����ɫ
		//F = ����ɫ
	//system("color 0E ");
}

void test02()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j == 2 &&i == 1)
			{
				goto again;
			}
		}
	again:
		if (j == 2 && i == 1)
		break;
	}
}
#if 0
int main()
{
	//test01();
	test02();
	return 0;
}
#endif