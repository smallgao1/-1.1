#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

//获取虚拟键码的值
//如果按过那么为1
#define KEY_PRESS(VK) ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )

#define KEY_RETURN 2
#define KEY_NEXT 4

#define SPACE_OUT 0

#define WALL 1
#define SPACE 2
#define TARGET 3
#define BOX 4
#define TARGET_IN 5
#define PERSON 6

typedef enum dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NO
}DIR;

void SetPos(short x, short y);
void disdisplayInfo();
void DesignUI();


//开始欢迎界面的设置
int WelcomePage();
//第一关
void GetLevel1();
/*第二关*/
void  GetLevel2();
void  GetLevel3();
/*第四关*/
void  GetLevel4();
//打印地图
int PrintMap(int aimap[][16], int level);

int PlayGame(int aimap[][16], int aimap2[][16], int boxcount, int level);


//选择前景背景颜色
void SelectColor(int color);
/*
* @brief 箱子的移动
* @param 原始数组，新数组，人的坐标 perx,pery, 方向
*/
void MoveBox(int aimap[][16], int aimap2[][16], int px, int py, DIR dir);