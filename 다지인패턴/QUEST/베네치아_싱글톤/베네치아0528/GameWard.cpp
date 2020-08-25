#include "GameWard.h"
#include"WardManager.h"



GameWard::GameWard()
{
	m_iSpeed = 2000;
	m_idrop_time = clock();
	m_bItem_State = false;
	m_strBlindWard = "бсбс";
}

void GameWard::Erase()
{
	Draw.EraseText(m_strward, m_WardPos.x, m_WardPos.y);
}

void GameWard::XY_Set() 
{
	m_WardPos.x = (rand() % (WIDTH * 2));

	if (4 >= m_WardPos.x - (m_strward.length() / 2))
		m_WardPos.x += (m_strward.length() / 2);
	if ((WIDTH * 2) - 4 <= m_WardPos.x + (m_strward.length() / 2))
		m_WardPos.x -= (m_strward.size() / 2);
	m_WardPos.y = 2;
}
void GameWard::Set_Item()
{
	int randnum = (rand() % 100) + 1;
	if (randnum < 20)
	{
		Set_Blind_Time();
		m_bItem_State = true;
		randnum = (rand() % 5) + 1;
		m_eMyItem = (ITEM)randnum;
	}
}

void GameWard::Set_Blind_Time()
{
	m_iblind_time = clock();
}

void GameWard::Clear_Item()
{
	m_bItem_State = false;
}

void GameWard::Blind_Drop()
{
	if (m_bWard_State == true)
	{
		if (!(clock() - m_iblind_time > 1500))
		{
			PUPPLE
			Draw.EraseText(m_strward, m_WardPos.x, m_WardPos.y);
			Draw.MidText(m_strBlindWard, m_WardPos.x, m_WardPos.y);
			TEAL
		}
		else
		{
			PUPPLE
			Draw.MidText(m_strward, m_WardPos.x, m_WardPos.y);
			TEAL
		}
	}
}

int GameWard::All_Ward_Blind(GameWard* wardlist, int Wradnum)
{
	for (int i = 0; i < Wradnum; i++)
	{
		if (wardlist[i].Out_Ward_State() == true)
		{
			wardlist[i].Set_Blind_Time();
		}
	}
	return 0;
}

int GameWard::All_Ward_Clear(GameWard* wardlist, int Wradnum)
{
	int score = 0;
	for (int i = 0; i < Wradnum; i++)
	{
		if (wardlist[i].Out_Ward_State() == true)
		{
			wardlist[i].Erase();
			wardlist[i].XY_Set();
			wardlist[i].Ward_State_Set();
			wardlist[i].Clear_Item();
			score++;
		}
	}
	return score;
}


GameWard::~GameWard()
{
}
