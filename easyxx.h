#pragma once
#include"Initdata.h"
#include<graphics.h>
class easyx
{
public:
	int step = 0;
	int xx = 0;//���յ����ӵ�
	int yy = 0;
	int Time = 0;//��ʱ
	void DrawLine();//����
	void DrawPoint();//����
	void IdentifyPoint(int x, int y);//ȷ��������ӵ�
	void DrawPiece(int type, int x, int y);//������
	void button(int x, int y, int w, int h, const char* text);//��Ӱ�ť
	void CalculateTime(clock_t B, clock_t E);//��ʱ
};
