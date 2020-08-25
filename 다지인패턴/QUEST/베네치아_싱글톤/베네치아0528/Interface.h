#pragma once
#include"Mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

class Interface
{
public:
	Interface();
	void State_Draw(int Life, int Score, string Name);
	void Typing_Box_Draw();
	void BoxDraw(int start_x, int start_y,int width, int height);
	int SelectCursor(int Menuline, int Addy, int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void Text(string str, int x, int y);
	void MidText(string str, int x, int y);
	void RIghtText(string str, int x, int y);
	void EraseText(string str, int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~Interface();
};