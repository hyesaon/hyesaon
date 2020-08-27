#include "Weapon.h"



Weapon::Weapon(string Name, int attack, int prise) : Inventory(Name)
{
	strcpy(m_chrName, Name.c_str());
	m_iAttact = attack;
	m_iPrise = prise;

	if (m_iAttact < 20)
	{
		m_iSkill = (rand() % 15) + 1;
	}
	else if (m_iAttact >= 20 && m_iAttact < 50)
	{
		m_iSkill = (rand() % 35) + 1;
	}
	else
	{
		m_iSkill = (rand() % 65) + 1;
	}
}

Weapon::Weapon(Weapon* tmp) : Inventory(tmp->Out_Inventory_name())
{
	SetType(tmp->m_chrtype);
	strcpy(m_chrName, tmp->Out_Inventory_name().c_str());
	m_iAttact = tmp->m_iAttact;
	m_iPrise = tmp->m_iPrise;
	m_iSkill = tmp->m_iSkill;
}

void Weapon::SetType(string Type)
{
	strcpy(m_chrtype, Type.c_str());
}

bool Weapon::CheckWeapone(string name)
{
	if (name == m_chrtype)
	{
		return true;
	}
	return false;
}

bool Weapon::ShowInfo(int shownum, int x, int y, string name)
{
	char info[100];
	if (name == m_chrName)
	{
		sprintf(info, "가격 : %d 무기타입 : %s", m_iPrise, m_chrtype);
		m_Draw.DrawMidText(info, x, y);
		sprintf(info, "무기이름 : %s 공격력 : %d", m_chrName, m_iAttact);
		m_Draw.DrawMidText(info, x / 2, y + 1);
		return true;
	}
	return false;
}

void Weapon::SaveWeapon(ofstream* Save)
{
	*Save << endl << m_chrtype << " " << m_chrName << " " << m_iAttact << " " << m_iPrise;
}


string Weapon::ShowMyWeapon()
{
	char info[100];
	sprintf(info, "무기 타입 : %s 무기이름 : %s 공격력 : %d", m_chrtype, m_chrName, m_iAttact);
	return info;
}


Weapon::~Weapon()
{
}

bool Bow::SkillAttack2(int x, int y)
{
	return  false;
}

int Bow::SkillAttack(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		BLOOD
			m_Draw.DrawMidText("연속 공격!!", x, y);
		ORIGINAL
			return m_iAttact;
	}
	return 0;
}

Bow::~Bow()
{
}

bool Dagger::SkillAttack2(int x, int y)
{
	return  false;
}

int Dagger::SkillAttack(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		PUPPLE
			m_Draw.DrawMidText("적 상태이상 : 독(3턴간)", x, y);
		ORIGINAL
			if (m_iturn > 0)
				m_iturn = 0;

		m_iturn++;
		return 5;
	}
	if (m_iturn > 0 && m_iturn <= 3)
	{
		m_iturn++;
		return 5;
	}
	else
	{
		m_iturn = 0;
		return 0;
	}
}

Dagger::~Dagger()
{
}


int Gun::SkillAttack(int x, int y)
{
	return 0;
}

bool Gun::SkillAttack2(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		PLUM
			m_Draw.DrawMidText("!!! 관통(적 즉사) !!!", x, y);
		ORIGINAL
			return true;
	}
	return false;
}

Gun::~Gun()
{
}

int Hammer::SkillAttack(int x, int y)
{
	return 0;
}

bool Hammer::SkillAttack2(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		GOLD
			m_Draw.DrawMidText("** 적 스턴(1턴) **", x, y);
		ORIGINAL
			return true;
	}
	return false;
}

Hammer::~Hammer()
{
}

bool Sword::SkillAttack2(int x, int y)
{
	return  false;
}

int Sword::SkillAttack(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		BLOOD
			m_Draw.DrawMidText("급소 공격!! 데미지 2배", x, y);
		ORIGINAL
			return m_iAttact * 2;
	}
	return 0;

}

Sword::~Sword()
{
}

int Wand::SkillAttack(int x, int y)
{
	return 0;
}

bool Wand::SkillAttack2(int x, int y)
{
	int randnum = (rand() % 100) + 1;

	if (randnum < m_iSkill)
	{
		BLUE_GREEN
			m_Draw.DrawMidText("~~ 생명력 회복 ~~", x, y);
		ORIGINAL
			return true;
	}
	return false;
}


Wand::~Wand()
{
}