#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

void test01()
{
	 //   0 = 黑色            
		//1 = 蓝色                  
		//2 = 绿色                   
		//3 = 湖蓝色				
		//4 = 红色					
		//5 = 紫色									
		//6 = 黄色											
		//7 = 白色									
		//8 = 灰色
		//9 = 淡蓝色
		//A = 淡绿色
		//B = 淡浅绿色
		//C = 淡红色
		//D = 淡紫色
		//E = 淡黄色
		//F = 亮白色
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