#pragma once
#include<iostream>	//기본
#include<Windows.h>	//system()
#include<conio.h>	//kbhit(),getch()
#include<string>	//string
#include<time.h>	//시간관리
#include<crtdbg.h>	//메모리누수 확인
#include<fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0070 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0071 );
#define GREEN SetConsoleTextAttribute( col,0x0072 );
#define TEAL SetConsoleTextAttribute( col,0x0073 );
#define BLOOD SetConsoleTextAttribute( col,0x0074 );
#define PUPPLE SetConsoleTextAttribute( col,0x0075 );
#define GOLD SetConsoleTextAttribute( col,0x0076 );	//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0078 );
#define WHITE SetConsoleTextAttribute( col,0x0077 );
#define GRAY SetConsoleTextAttribute( col,0x0078 );
#define BLUE SetConsoleTextAttribute( col,0x0079 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x007a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x007b );
#define RED SetConsoleTextAttribute( col,0x007c );
#define PLUM SetConsoleTextAttribute( col,0x007d );
#define YELLOW SetConsoleTextAttribute( col,0x007e );

#define WIDTH 60
#define HEIGHT 30
#define S 's'
#define ENTER 13
#define BACKSPACE 8
#define SPACE 32
#define DEL 127
#define ESC 27

struct Pos
{
	int x;
	int y;
};
