#include "People.h"



People::People()
{
	MainBox = new Bag("Main Box");
	m_MyWeapon = NULL;
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

void People::Reset_Inventory()
{
	if (MainBox->Out_Inventory_size() > 0)
	{
		MainBox = NULL;
		MainBox = new Bag("Main Box");
	}
}

void People::Load_Inventory(Weapon* Weapon)
{
	MainBox->Add(m_MyWeapon);
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
		m_MyWeapon->Save(Save);
		MainBox->Save(Save);
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
	char select = NULL;
	while (1)
	{
		system("cls");
		YELLOW
			BoxDraw(0, 0, WIDTH, HEIGHT);
		sprintf(info, "======%s(%dLv)======", m_chrName, m_iLevel);
		DrawMidText(info, x, y);
		sprintf(info, "공격력 = %d	생명력 = %d/%d", m_iattack, m_iLife, m_iMaxLife);
		TextDraw(info, x / 2, y + 1);
		sprintf(info, "경험치 = %d/%d	GetEXP = %d", m_iNowEXP, m_iMaxEXP, m_iGiveEXP);
		TextDraw(info, x / 2, y + 2);
		sprintf(info, "Gold = %d", m_iGold);
		TextDraw(info, x / 2, y + 3);
		if (m_MyWeapon != NULL && MainBox->Out_Inventory_size() != 0)
		{
			DrawMidText("인벤토리 보기 : i", x, y + 4);
			DrawMidText(m_MyWeapon->ShowMyWeapon(), x, y + 6);
			select = getch();
			if (select == 73)
				select = I;
			if (select == I)
			{
				View_My_Inventory();
			}
			else
				return;
		}
		else
		{
			getch();
			return;
		}
	}
	ORIGINAL
}

void People::Buy_Weapon(int price)
{
	m_iGold -= price;
}

void People::TakeWeapon(Inventory* weapon, string type)
{
	if (weapon == NULL)
		return;

	if (m_MyWeapon != NULL)
		m_MyWeapon = NULL;

	if (m_MyWeapon == NULL)
	{
		if (type == "Sword")
		{
			m_MyWeapon = new Sword((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
		if (type == "Gun")
		{
			m_MyWeapon = new Gun((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
		if (type == "Bow")
		{
			m_MyWeapon = new Bow((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
		if (type == "Dagger")
		{
			m_MyWeapon = new Dagger((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
		if (type == "Hammer")
		{
			m_MyWeapon = new Hammer((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
		if (type == "Wand")
		{
			m_MyWeapon = new Wand((Weapon*)weapon);
			MainBox->Add(m_MyWeapon);
		}
	}
}

void People::View_My_Inventory()
{
	int select;
	int weaponeNum;
	int take_on_weapon = 0;
	int show_num = 0;
	int page = 0;
	bool showflag = true;
	weaponeNum = MainBox->Out_Inventory_size();
	while (showflag == true)
	{
		system("cls");
		YELLOW
		BoxDraw(0, 0, WIDTH, HEIGHT);
		DrawMidText("목록", WIDTH, HEIGHT / 2 - 11);
		MainBox->ShowInfo(show_num, WIDTH - 2, HEIGHT / 2 - 7, MainBox->Out_Inventory_name());
		ORIGINAL
		DrawMidText("이전 페이지", WIDTH, HEIGHT / 2 + 6);
		DrawMidText("다음 페이지", WIDTH, HEIGHT / 2 + 9);
		DrawMidText("나가기", WIDTH, HEIGHT / 2 + 12);
		select = MenuSelectCursor(7, 3, WIDTH / 2 - 10, HEIGHT / 2 - 6);

		switch (select)
		{
		case 1:
			if (page == 0)
				take_on_weapon = select - 1;
			else if (page > 0)
				take_on_weapon = select - 1 + (4 * page);
			if (take_on_weapon >= weaponeNum)
				break;
			Take_On_Weapone(MainBox->OutItem(take_on_weapon));
			break;
		case 2:
			if (page == 0)
				take_on_weapon = select - 1;
			else if (page > 0)
				take_on_weapon = select - 1 + (4 * page);
			if (take_on_weapon >= weaponeNum)
				break;
			Take_On_Weapone(MainBox->OutItem(take_on_weapon));
			break;
		case 3:
			if (page == 0)
				take_on_weapon = select - 1;
			else if (page > 0)
				take_on_weapon = select - 1 + (4 * page);
			if (take_on_weapon >= weaponeNum)
				break;
			Take_On_Weapone(MainBox->OutItem(take_on_weapon));
			break;
		case 4:
			if (page == 0)
				take_on_weapon = select - 1;
			else if (page > 0)
				take_on_weapon = select - 1 + (4 * page);
			if (take_on_weapon >= weaponeNum)
				break;
			Take_On_Weapone(MainBox->OutItem(take_on_weapon));
			break;
		case 5:
			if (show_num < 4)
				break;
			ErasePoint(WIDTH / 2 - 10, HEIGHT / 2 + 6);
			page--;
			show_num -= 4;
			break;
		case 6:
			if (show_num <= weaponeNum && show_num >= 4)
				break;
			ErasePoint(WIDTH / 2 - 10, HEIGHT / 2 + 9);
			page++;
			show_num += 4;
			break;
		case 7:
			showflag = false;
			break;
		}
	}
}

void People::Take_On_Weapone(Inventory* Weapones)
{
	m_MyWeapon = ((Weapon*)Weapones);
}

void People::Level_UP(int EXP, int Gold ,int x,int y)
{
	int randnum;
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
		randnum = (rand() % 1);
		if (randnum == 0)
			m_iMaxLife += 10;
		else
			m_iattack += 5;
	}
	m_iLife = m_iMaxLife;
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
