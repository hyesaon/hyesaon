#include "People.h"



People::People()
{
	m_MyWeapon = NULL;
}

void People::Buy_Weapon(int price)
{
	m_iGold -= price;
}

void People::SetPeople(ifstream* Load, THISIS who)
{
	m_eWho = who;
	if (m_eWho == THISIS_MONSTER)
	{
		*Load >> m_chrName;
	}
	*Load >> m_iattack;
	*Load >> m_iMaxLife;
	*Load >> m_iMaxEXP;
	*Load >> m_iGiveEXP;
	*Load >> m_iLevel;
	*Load >> m_iGold;
	*Load >> m_iNowEXP;
	*Load >> m_iLife;
}

void People::SetPlayerName(string Name)
{
	strcpy(m_chrName, Name.c_str());
}

void People::SavePeople(ofstream* Save)
{
	*Save << m_chrName << " " << m_iLevel << " " << m_iattack << " " << m_iLife << " " << m_iMaxLife << " "
		 << " " << m_iGold << " " << m_iNowEXP << " " << m_iMaxEXP << " " << m_iGiveEXP;
	if (m_MyWeapon != NULL)
	{
		m_MyWeapon->SaveWeapon(Save);
		delete m_MyWeapon;
		m_MyWeapon = NULL;
	}
}

void People::LoadPeople(ifstream* Load, THISIS who)
{
	m_eWho = who;
	*Load >> m_chrName;
	*Load >> m_iLevel;
	*Load >> m_iattack;
	*Load >> m_iLife;
	*Load >> m_iMaxLife;
	*Load >> m_iGold;
	*Load >> m_iNowEXP;
	*Load >> m_iMaxEXP;
	*Load >> m_iGiveEXP;
}

void People::Showinfo(int x, int y)
{
	char info[100];

	sprintf(info, "======%s(%dLv)======", m_chrName, m_iLevel);
	DrawMidText(info, x, y);
	sprintf(info, "공격력 = %d	생명력 = %d/%d", m_iattack, m_iLife ,m_iMaxLife);
	TextDraw(info, x /2, y + 1);
	sprintf(info, "경험치 = %d/%d	GetEXP = %d", m_iNowEXP, m_iMaxEXP, m_iGiveEXP);
	TextDraw(info, x /2, y + 2);
	sprintf(info, "Gold = %d", m_iGold);
	TextDraw(info, x /2, y + 3);

	if (m_MyWeapon != NULL)
	{
		DrawMidText(m_MyWeapon->ShowMyWeapon() , x / 2 - 9 , y + 4);
	}
}

void People::TakeWeapon(Weapon* weapon, string type)
{
	if (m_MyWeapon != NULL)
		delete m_MyWeapon;

	m_MyWeapon = NULL;
	if (m_MyWeapon == NULL)
	{
		if (type == "검")
		{
			m_MyWeapon = new Sword(weapon);
		}
		if (type == "총")
		{
			m_MyWeapon = new Gun(weapon);
		}
		if (type == "활")
		{
			m_MyWeapon = new Bow(weapon);
		}
		if (type == "대거")
		{
			m_MyWeapon = new Dagger(weapon);
		}
		if (type == "해머")
		{
			m_MyWeapon = new Hammer(weapon);
		}
		if (type == "완드")
		{
			m_MyWeapon = new Wand(weapon);
		}
	}
}

void People::Level_UP(int EXP, int Gold ,int x,int y)
{
	m_iNowEXP += EXP;
	m_iGold += Gold;
	if (m_iNowEXP >= m_iMaxEXP)
	{
		RED
		gotoxy(x - 2, y / 2 + 4);
		cout << m_chrName;
		DrawMidText(" 레벨업!! ", x , y / 2 + 5);
		ORIGINAL
		m_iLevel++;
		m_iNowEXP -= m_iMaxEXP;
		m_iMaxEXP *= 2;
	}
}

bool People::Life(int attack)
{
	m_iLife -= attack;
	if (m_iLife <= 0)
	{
		m_iLife = 0;
		return false;
	}
	return true;
}

int People::Give_EXP()
{
	m_iLife = m_iMaxLife;
	return m_iGiveEXP;
}

int People::Weapon_Attack(int x, int y)
{
	if (m_MyWeapon != NULL)
	{
		return m_MyWeapon->SkillAttack(x, y);
	}
	else
		return 0;
}

bool People::Weapon_Attack2(int x, int y)
{
	if (m_MyWeapon != NULL)
	{
		return m_MyWeapon->SkillAttack2(x, y);
	}
	else
		return false;
}
bool People::MY_Weapontype(string name)
{
	if (m_MyWeapon != NULL && m_MyWeapon->CheckWeapone(name))
	{
		return true;
	}
	else
		return false;

}

void People::Heal()
{
	m_iLife += 5;
	if (m_iLife > m_iMaxLife)
	{
		m_iLife = m_iMaxLife;
	}
}

void People::Delete_My_Weapon()
{
	delete m_MyWeapon;
	m_MyWeapon = NULL;
}

People::~People()
{
	delete m_MyWeapon;
}
