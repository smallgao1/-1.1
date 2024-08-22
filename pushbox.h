#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

//��ȡ��������ֵ
//���������ôΪ1
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


//��ʼ��ӭ���������
int WelcomePage();
//��һ��
void GetLevel1();
/*�ڶ���*/
void  GetLevel2();
void  GetLevel3();
/*���Ĺ�*/
void  GetLevel4();
//��ӡ��ͼ
int PrintMap(int aimap[][16], int level);

int PlayGame(int aimap[][16], int aimap2[][16], int boxcount, int level);


//ѡ��ǰ��������ɫ
void SelectColor(int color);
/*
* @brief ���ӵ��ƶ�
* @param ԭʼ���飬�����飬�˵����� perx,pery, ����
*/
void MoveBox(int aimap[][16], int aimap2[][16], int px, int py, DIR dir);