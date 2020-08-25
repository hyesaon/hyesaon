#include "WardManager.h"



WardManager::WardManager()
{
	m_iDrop_Speed = 1000;
	m_bBlind_state = false;
	m_bStop_state = false;
}

void WardManager::SetWard()
{
	ifstream Load;
	string str_tmp;

	Load.open("베네치아_스토리.txt");
	if (Load.is_open())
	{
		Load >> m_iStoryNum;
		m_Story = new Ward[m_iStoryNum];
		for (int i = 0; i < m_iStoryNum && !Load.eof(); i++)
		{
			getline(Load, str_tmp);
			m_Story[i].SetStr(str_tmp);
		}
	}
	Load.close();

	Load.open("Word.txt");
	if (Load.is_open())
	{
		Load >> m_iWardListNum;
		m_WardList = new GameWard[m_iWardListNum];
		for (int i = 0; i < m_iWardListNum && !Load.eof(); i++)
		{
			Load >> str_tmp;
			m_WardList[i].SetStr(str_tmp);
		}
	}
	Load.close();
}

bool WardManager::ShowStory()
{
	char skip = NULL;
	int Oldclock = clock();

	for (int show_story = 1; show_story <= m_iStoryNum;)
	{
		if (clock() - Oldclock >= STORY_TIME)
		{
			for (int i = 0; i < show_story; i++)
			{
				if (kbhit())
				{
					skip = getch();
					if (skip == S)
					{
						m_Story[i].Y_Set();
						return false;
					}
					else
						skip = NULL;

				}
				m_Story[i].Scoll();
			}
			Oldclock = clock();
			show_story++;
		}
	}
	for (int i = 0; i < m_iStoryNum; i++)
		m_Story[i].Y_Set();
	return true;
}

void WardManager::SetGameStart(int Stage)
{
	m_iMake_time = clock();
	m_iDrop_time = clock();
}

void WardManager::MakeWard() //전체세팅
{
	for (int i = 0; i < m_iWardListNum; i++)
	{
		if(m_WardList[i].Out_Ward_State() == true)
			m_WardList[i].Ward_State_Set();
	}
}

void WardManager::SetGameWard(int stage) //하나씩만들기
{
	int randnum = (rand() % m_iWardListNum); //0~75
	if (clock() - m_iMake_time >= GAMEWARD_SHOW_TIME / stage)
	{
		for (int i = 0; i < m_iWardListNum; i++)
		{
			if (m_WardList[i].Out_Ward_State() == false)
			{
				m_WardList[i].XY_Set();
				m_WardList[i].Ward_State_Set();
				m_WardList[i].Set_Item();
				break;
			}
		}
		m_iMake_time = clock();
	}
}

int WardManager::GameWardList_Drop(int stage, string typing)
{
	int damage = 0;
	int nowclock = clock();
	if (m_bStop_state == false)
	{
		if (clock() - m_iDrop_time >= m_iDrop_Speed / stage)
		{
			for (int i = 0; i < m_iWardListNum; i++)
			{
				if (m_WardList[i].Drop() == false)
				{
					m_WardList[i].Erase();
					m_WardList[i].Clear_Item();
					m_WardList[i].XY_Set();
					damage++;
				}
				if (m_WardList[i].Out_ItemState() == true)
				{
					m_WardList[i].Blind_Drop();
				}
				if (m_bBlind_state == true)
				{
					m_WardList[i].Blind_Drop();
				}
			}
			TextBox_REdraw(typing);
			m_iDrop_time = clock();
		}
	}
	if (m_bStop_state == true && nowclock - m_iALLStop_time >= 3000)
	{
		m_bStop_state = false;
	}
	if (m_iDrop_Speed < 1000 && clock() - m_iALLSpeedSet_time >= 1500)
	{
		m_iDrop_Speed = 1000;
	}
	if (m_bBlind_state == true && clock() - ALL_Blind_time >= 1500)
	{
		m_bBlind_state = false;
	}
	return damage;
}

bool WardManager::Answer(string ward_typing, int &score)
{
	for (int i = 0; i < m_iWardListNum; i++)
	{
		if (m_WardList[i].OutWard() == ward_typing)
		{
			if (m_WardList[i].Out_ItemState() == true)
			{
				if (m_WardList[i].Out_Item_Enum() == ITEM_BLIND)
				{
					m_bBlind_state = true;
					Item_Call(&GameWard::All_Ward_Blind);
					ALL_Blind_time = clock();
				}
				if (m_WardList[i].Out_Item_Enum() == ITEM_CLEAR)
				{
					score += Item_Call(&GameWard::All_Ward_Clear) * 100;
					TEAL
						m_Draw.Typing_Box_Draw();
					BLACK
				}
				if (m_WardList[i].Out_Item_Enum() == ITEM_STOP)
				{
					m_bStop_state = true;
					m_iALLStop_time = clock();
				}
				if (m_WardList[i].Out_Item_Enum() == ITEM_SPEED_DOWN)
				{
					m_iDrop_Speed += 500;
					m_iALLSpeedSet_time = clock();
				}
				if (m_WardList[i].Out_Item_Enum() == ITEM_SPEED_UP)
				{
					m_iDrop_Speed -= 500;
					m_iALLSpeedSet_time = clock();
				}
			}
			Delete_GamePlay_WardList();
			return true;
		}
	}
	return false;
}

int WardManager::Item_Call(int(GameWard::*item)(GameWard*, int))
{
	return (*m_WardList.*item)(m_WardList, m_iWardListNum);
}


bool WardManager::TextBox_REdraw(string typing)
{
	for (int i = 0; i < m_iWardListNum; i++)
	{
		if (m_WardList[i].Out_WardPos().x > WIDTH - 18 && m_WardList[i].Out_WardPos().x < WIDTH + 18 &&
			m_WardList[i].Out_WardPos().y > HEIGHT / 2 + 6 && m_WardList[i].Out_WardPos().y < HEIGHT / 2 + 11)
		{
			TEAL
				m_Draw.Typing_Box_Draw();
			BLACK
			m_Draw.MidText(typing, WIDTH, HEIGHT / 2 + 8);
			return false;
		}
	}
	return true;
}

void WardManager::Delete_GamePlay_WardList()
{
	for (int i = 0; i < m_iWardListNum; i++)
	{
		if (m_WardList[i].Out_Ward_State() == true)
		{
			m_WardList[i].Ward_State_Set();
			m_WardList[i].XY_Set();
			m_WardList[i].Erase();
			m_WardList[i].Clear_Item();
		}
	}
}

WardManager::~WardManager()
{
	delete[] m_WardList;
	delete[] m_Story;
}
