#include "Ward.h"



Ward::Ward()
{
	m_WardPos.x = WIDTH * 2;
	m_WardPos.y = (HEIGHT / 2) + 5;
	m_bWard_State = true;
}

void Ward::SetStr(string myward)
{
	m_strward = myward;
}

void Ward::Ward_State_Set()
{
	if (m_bWard_State == true)
		m_bWard_State = false;
	else
		m_bWard_State = true;
}

bool Ward::Drop()
{
	BLACK
		if (m_bWard_State == true)
		{
			Draw.EraseText(m_strward, m_WardPos.x, m_WardPos.y);
			m_WardPos.y++;
			if (m_WardPos.y > HEIGHT - 5)
			{
				return false;
			}
			Draw.MidText(m_strward, m_WardPos.x, m_WardPos.y);
		}
	return true;
	TEAL

}

void Ward::Scoll()
{
	Draw.EraseText(m_strward, m_WardPos.x / 2, m_WardPos.y);
	m_WardPos.y--;
	if (m_WardPos.y < (HEIGHT / 2) - 5)
	{
		return;
	}
	Draw.MidText(m_strward, m_WardPos.x / 2, m_WardPos.y);
}

void Ward::Y_Set()
{
	m_WardPos.y = (HEIGHT / 2) + 5;
}

Ward::~Ward()
{
}
