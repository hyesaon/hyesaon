#include "Interface.h"



Interface::Interface()
{

}

void Interface::State_Draw(int Life, int Score, string Name)
{
	string now_life;
	gotoxy(1, HEIGHT);
	EraseText("LIFE : ��������������������" + now_life, 10, HEIGHT);
	EraseText("Score :      " , WIDTH * 2 - 7, HEIGHT);
	RED
		for (int i = 0; i < Life; i++)
			now_life += "��";
	Text("LIFE : " + now_life, 1, HEIGHT);
	Text("Score : " + to_string(Score), WIDTH*2, HEIGHT);
	TEAL
}

void Interface::Typing_Box_Draw()
{
	TEAL
	MidText("��������������������������������", WIDTH, HEIGHT / 2 + 7);
	MidText("��                            ��", WIDTH, HEIGHT / 2 + 8);
	MidText("��������������������������������", WIDTH, HEIGHT / 2 + 9);
	ORIGINAL
}

void Interface::BoxDraw(int start_x, int start_y, int width, int height)
{
	if (start_x > width)
		start_x -= width;
	for (int y = 0; y < height - 2; y++)
	{
		gotoxy(start_x, start_y + y);
		if (y == 0)
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == height - 3)
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "��";
		}
	}
}

void Interface::Text(string str, int x, int y)
{
	if (x >= WIDTH * 2)
	{
		x -= (str.size() + 1);
	}
	gotoxy(x, y);
	cout << str;
}

void Interface::MidText(string str, int x, int y)
{
	x -= str.size() / 2;
	/*if ((str.size() / 2) + x > WIDTH * 2 - 2)
		x -= (str.size() / 2) + x;
	if ((str.size() / 2) - x < 2)
		x += str.size() / 2 - x;*/
	gotoxy(x , y);
	cout << str;
	return;
}

void Interface::EraseText(string str, int x, int y)
{
	x -= str.size()/2;

	gotoxy(x, y);
	for (int i = 0; i < str.length(); i++)
	{
		cout << " ";
	}
	return;
}

void Interface::ErasePoint(int x, int y)
{
	gotoxy(x*2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void Interface::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

int Interface::SelectCursor(int Menuline, int Addy, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("��", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= Addy;
					Select--;
				}
				break;
			case DOWN:
				if (Select + 1 <= Menuline)
				{
					ErasePoint(x, y);
					y += Addy;
					Select++;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("��", x, y);
			ORIGINAL
		}
}

Interface::~Interface()
{
}
