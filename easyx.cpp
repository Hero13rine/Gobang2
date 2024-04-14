#include"easyxx.h"
#include"Initdata.h"

void easyx::DrawLine()
{
	setlinecolor(BLACK);
	settextcolor(BLACK);
	//��������
	char b = 'A';
	int n = 15;
	char num[10];
	sprintf(num, "%d", n);
	for (int x = 30; x < 480; x += 30)
	{
		outtextxy(x - 4, 455, b++);//A->O
		line(x, 30, x, 450);
	}
	//���ƺ���
	for (int y = 30; y < 480; y += 30)
	{
		sprintf(num, "%d", n--);
		if (n > 8)
		{
			outtextxy(7, y - 8, num);//10->15
		}
		else
		{
			outtextxy(10, y - 8, num);//1->9
		}
		line(30, y, 450, y);
	}
}

void easyx::DrawPoint()
{
	//������������ĺڵ�
	setfillcolor(BLACK);
	fillcircle(120, 120, 2);
	fillcircle(120, 360, 2);
	fillcircle(360, 120, 2);
	fillcircle(360, 360, 2);
	fillcircle(240, 240, 2);
}

void easyx::IdentifyPoint(int x, int y)
{

	for (int i = x - 30; i <= x + 30; i++)
	{
		for (int j = y - 30; j <= y + 30; j++)
		{
			if (i % 30 == 0 && j % 30 == 0 && sqrt(pow(i - x, 2) + pow(j - y, 2)) <= 13)
			{
				xx = i;
				yy = j;
				return;
			}
		}
	}
}

void easyx::DrawPiece(int type, int x, int y)
{
	/*xx = x;
	yy = y;*/
	char Step[10];
	sprintf(Step, "%d", ++step);//int������ת���ַ�������
	if (type == white)
	{
		setfillcolor(WHITE);
	}
	else
	{
		setfillcolor(BLACK);
	}
	for (int i = x - 30; i <= x + 30; i++)
	{
		for (int j = y - 30; j <= y + 30; j++)
		{
			if (i % 30 == 0 && j % 30 == 0 && sqrt(pow(i - x, 2) + pow(j - y, 2)) <= 13)
			{
				xx = i;
				yy = j;
				goto here;
			}
		}
	}
here:
	fillcircle(xx, yy, 13);//����
	if (type == white)
	{
		settextcolor(BLACK);
	}
	else
	{
		settextcolor(WHITE);
	}
	setbkmode(TRANSPARENT);
	if (step < 10)
	{
		outtextxy(xx - 3, yy - 7, Step);//������
	}
	else if (step < 100)
	{
		outtextxy(xx - 7, yy - 7, Step);//������
	}
	else
	{
		outtextxy(xx - 10, yy - 7, Step);//������
	}
}

void easyx::button(int x, int y, int w, int h, const char* text)//���ð�ť
{
	setbkmode(TRANSPARENT);
	setfillcolor(GREEN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void easyx::CalculateTime(clock_t B, clock_t E)
{
	Time += float(E - B) / CLOCKS_PER_SEC * 1000;
	int min = Time / 60000;//��
	int sec = Time % 60000 / 1000;//��
	int mis = Time % 1000;//����
	//���ü�ʱװ��
	setbkmode(TRANSPARENT);
	setfillcolor(GREEN);
	fillrectangle(150, 480, 330, 530);
	char MIN[10];
	char SEC[10];
	char MIS[10];
	sprintf(MIN, "%d", min);
	sprintf(SEC, "%d", sec);
	sprintf(MIS, "%d", mis);
	settextcolor(BLACK);
	outtextxy(160, 500, "AI��ʱ��");
	outtextxy(217, 500, MIN);
	outtextxy(230, 500, ":");
	outtextxy(250, 500, SEC);
	outtextxy(270, 500, ":");
	outtextxy(280, 500, MIS);
}