#include "PlayManeger.h"



PlayManeger::PlayManeger()
{
	m_strName = "? ? ?";
	m_iLife = 10;
	m_iScore = 0;
	m_iStage = 1;
	m_btyping_flag = true;

	char Window_Draw[100];
	sprintf(Window_Draw, "mode con: cols=%d lines=%d", WIDTH * 2 + 1, HEIGHT + 4);
	system(Window_Draw);
	GmaeSet();
}

void PlayManeger::GmaeSet()
{
	ifstream Load;
	Rank TmpRank;

	Load.open("Rank.txt");
	if (Load.is_open())
	{
		for (int i = 0; i < 10 && !Load.eof(); i++)
		{
			m_RankList[i].Load(Load);
		}
	}
	Load.close();
	for (int i = 0; i < 10; i++) //정렬확인
	{
		for (int j = i + 1 ; j < 10;j++)
		{
			if (m_RankList[i] < m_RankList[j])
			{
				TmpRank = m_RankList[i];
				m_RankList[i] = m_RankList[j];
				m_RankList[j] = TmpRank;
			}
			else
				continue;
		}
	}

	WardManager::GetInstance()->SetWard();
}

void PlayManeger::Menu()
{
	int select;
	bool menu_flag = true;

	while (menu_flag == true)
	{
		m_iLife = 10;
		m_iScore = 0;
		m_iStage = 1;
		TEAL
			m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
		m_Drawtool.MidText("  ~ ~  베네치아  ~ ~", WIDTH, HEIGHT/2 - 10);
		m_Drawtool.MidText("1. GAME START", WIDTH, HEIGHT / 2 - 2);
		m_Drawtool.MidText("2. RANK", WIDTH, HEIGHT / 2);
		m_Drawtool.MidText("3. EXIT", WIDTH, HEIGHT / 2 + 2);
		m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
		ORIGINAL
			select = m_Drawtool.SelectCursor(3, 2, WIDTH / 2 - 6, HEIGHT / 2 - 2);
		switch (select)
		{
		case 1:
			Play();
			break;
		case 2:
			Show_Ranking();
			break;
		case 3:
			menu_flag == false;
			return;
		}
	}
}

void PlayManeger::Play_intro()
{
	char control;
	system("cls");
	TEAL
		m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_Drawtool.Typing_Box_Draw();
	m_Drawtool.MidText( "Skip : s" , WIDTH, HEIGHT / 2 + 8);
	m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
	if (!WardManager::GetInstance()->ShowStory())
	{
		return;
	}
	m_Drawtool.MidText("ENTER", WIDTH, HEIGHT / 2 + 8 );

	while (1)
	{
		control = getch();
		if (control == ENTER)
			return;
	}
}

bool PlayManeger::GamePlay_Typing(string &typing)
{
	char ch;

	BLACK
	if (kbhit())
	{
		m_Drawtool.gotoxy(WIDTH - 12, HEIGHT / 2 + 8);
		if (typing.length() > 20)
			typing = typing.substr(0, typing.length() - 1);

		ch = getch();
		switch (ch)
		{
		case ESC:
			return Game_Pause();
		case ENTER:
			if (WardManager::GetInstance()->Answer(typing, m_iScore) == true)
			{
				m_iScore += 100;
				m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
				m_Drawtool.Typing_Box_Draw();
			}
			else
			{
				m_btyping_flag = false;
				m_iOldTime = clock();
			}
			m_Drawtool.EraseText(typing, WIDTH, HEIGHT / 2 + 8);
			typing = "";
			break;
		case BACKSPACE:
			if (m_btyping_flag == true)
			{
				m_Drawtool.EraseText(typing, WIDTH, HEIGHT / 2 + 8);
				typing = typing.substr(0, typing.length() - 1);
				m_Drawtool.MidText(typing, WIDTH, HEIGHT / 2 + 8);
			}
			break;
		default:
			if (m_btyping_flag == true)
				typing += ch;
			break;
		}
		m_Drawtool.MidText(typing, WIDTH, HEIGHT / 2 + 8);
	}
	if (m_btyping_flag == false)
	{
		if (clock() - m_iOldTime >= PENALTY_TIME)
		{
			m_btyping_flag = true;
			m_iOldTime = clock();
		}
	}
	TEAL
	return true;
}

void PlayManeger::Play()
{
	bool game_flag = true;
	int Damage = 0;
	string typing;

	Play_intro();

	system("cls");

	TEAL
		m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_Drawtool.Typing_Box_Draw();
	m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
	WardManager::GetInstance()->SetGameStart(m_iStage);
	m_Drawtool.MidText("STAGE " + to_string(m_iStage), WIDTH, HEIGHT / 2);
	Sleep(1000);
	m_Drawtool.EraseText("STAGE " + to_string(m_iStage), WIDTH, HEIGHT / 2);

	while (game_flag == true)
	{
		WardManager::GetInstance()->SetGameWard(m_iStage);

		game_flag = GamePlay_Typing(typing);

		Damage = WardManager::GetInstance()->GameWardList_Drop(m_iStage, typing);

		if (Damage > 0)
		{
			m_Drawtool.State_Draw(m_iLife -= Damage, m_iScore, m_strName);
		}

		if (m_iLife <= 0)
		{
			Game_Over();
			game_flag = false;
		}
		if (m_iScore >= 1500 * m_iStage)
		{
			m_iScore = 0;
			m_iStage++;
			WardManager::GetInstance()->Delete_GamePlay_WardList();
			m_Drawtool.Typing_Box_Draw();
			WardManager::GetInstance()->SetGameStart(m_iStage);
			m_Drawtool.MidText("STAGE " + to_string(m_iStage), WIDTH, HEIGHT / 2);
			Sleep(1000);
			m_Drawtool.EraseText("STAGE " + to_string(m_iStage), WIDTH, HEIGHT / 2);
			m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
		}
	}
}

void PlayManeger::Game_Over()
{
	string player_name;
	int select;

	system("cls");
	TEAL
		m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_Drawtool.MidText("저장하시겠습니까?", WIDTH, HEIGHT / 2 - 4);
	m_Drawtool.MidText("예", WIDTH, HEIGHT / 2 - 2);
	m_Drawtool.MidText("아니오", WIDTH, HEIGHT / 2 - 1);
	select = m_Drawtool.SelectCursor(2, 1, WIDTH / 2 - 3, HEIGHT / 2 - 2);

	switch (select)
	{
	case 1:
		m_Drawtool.EraseText("저장하시겠습니까?", WIDTH, HEIGHT / 2 - 4);
		m_Drawtool.EraseText("예", WIDTH, HEIGHT / 2 - 2);
		m_Drawtool.EraseText("아니오", WIDTH, HEIGHT / 2 - 1);
		TEAL
			m_Drawtool.MidText("플레이어 이름", WIDTH, HEIGHT / 2 - 2);
		m_Drawtool.Text(">>", WIDTH - 2, HEIGHT / 2 - 1);
		m_Drawtool.gotoxy(WIDTH, HEIGHT / 2 - 1);
		cin >> player_name;
		Save_Rank(player_name, m_iStage, m_iScore);
		break;
	case 2:
		break;
	}
	WardManager::GetInstance()->Delete_GamePlay_WardList();
}

bool PlayManeger::Game_Pause()
{
	int select;

	system("cls");
	TEAL
		m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_Drawtool.MidText(" 게임을 종료하시겠습니까? ", WIDTH, HEIGHT / 2 - 6);
	m_Drawtool.MidText(" 저장되지 않습니다. ", WIDTH, HEIGHT / 2 - 5);
	m_Drawtool.MidText("예", WIDTH, HEIGHT / 2 - 2);
	m_Drawtool.MidText("아니오", WIDTH, HEIGHT / 2 - 1);

	select = m_Drawtool.SelectCursor(2, 1, WIDTH / 2 - 3, HEIGHT / 2 - 2);

	switch (select)
	{
	case 1:
		return false;
	case 2:
		m_Drawtool.EraseText(" 게임을 종료하시겠습니까? ", WIDTH, HEIGHT / 2 - 6);
		m_Drawtool.EraseText(" 저장되지 않습니다. ", WIDTH, HEIGHT / 2 - 5);
		m_Drawtool.EraseText("      예", WIDTH, HEIGHT / 2 - 2);
		m_Drawtool.EraseText("      아니오", WIDTH, HEIGHT / 2 - 1);
		m_Drawtool.Typing_Box_Draw();
		m_Drawtool.State_Draw(m_iLife, m_iScore, m_strName);
		return true;
	}
}

void PlayManeger::Save_Rank(string name, int stage, int score)
{
	Rank MyRank(name, stage, score), TmpRank;

	for (int i = 0; i < 10; i++)
	{
		if (m_RankList[i] < MyRank)
		{
			TmpRank = m_RankList[i];
			m_RankList[i] = MyRank;
			MyRank = TmpRank;
		}
		else
			continue;
	}

	ofstream Save;
	Save.open("Rank.txt");
	if (Save.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			m_RankList[i].Save(Save);
		}
	}
	Save.close();
}

void PlayManeger::Show_Ranking()
{
	system("cls");
	TEAL
		m_Drawtool.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_Drawtool.MidText("┌──────────────┐", WIDTH, HEIGHT / 2 - 14);
	m_Drawtool.MidText("│                            │", WIDTH, HEIGHT / 2 - 13);
	m_Drawtool.MidText("│           Ranking          │", WIDTH, HEIGHT / 2 - 12);
	m_Drawtool.MidText("│                            │", WIDTH, HEIGHT / 2 - 11);
	m_Drawtool.MidText("└──────────────┘", WIDTH, HEIGHT / 2 - 10);
	m_Drawtool.MidText("==================================================================================", WIDTH, HEIGHT / 2 - 9);
	m_Drawtool.Text("Name\t\t\tScroe\t\t\tStage", WIDTH /2 + 4, HEIGHT / 2 - 8);

	for (int i = 0, line=7; i < 10; i++,line-=2)
	{
		m_RankList[i].RankShow(WIDTH, HEIGHT / 2 - line);
	}
	getch();
}


PlayManeger::~PlayManeger()
{
}
