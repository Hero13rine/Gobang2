#pragma once
#include"Initdata.h"
#include<graphics.h>
class easyx
{
public:
	int step = 0;
	int xx = 0;//最终的落子点
	int yy = 0;
	int Time = 0;//计时
	void DrawLine();//划线
	void DrawPoint();//画点
	void IdentifyPoint(int x, int y);//确定鼠标落子点
	void DrawPiece(int type, int x, int y);//画棋子
	void button(int x, int y, int w, int h, const char* text);//添加按钮
	void CalculateTime(clock_t B, clock_t E);//计时
};
