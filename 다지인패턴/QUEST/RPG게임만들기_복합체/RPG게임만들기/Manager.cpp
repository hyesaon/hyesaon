#include "Manager.h"



Manager::Manager()
{
	Load_Weapon = NULL;
	m_iWindowX = WIDTH;
	m_iWindowY = HEIGHT;
	m_imonster_num = 0;

	char Window_Draw[100];
	sprintf(Window_Draw, "mode con: cols=%d lines=%d", m_iWindowX * 2 + 1, m_iWindowY + 1);
	system(Window_Draw);
}

void Manager::GameSet()
{
	ifstream Load;	
	string WeaponName;

	Load.open("DefaultMonster.txt");
	if (Load.is_open())
	{
		Load >> m_imonster_num;
		Monster = new People[m_imonster_num];

		for (int i = 0; i < m_imonster_num && !Load.eof(); i++)
		{
			Monster[i].SetPeople(&Load,THISIS_MONSTER);
		}
		Load.close();
	}
	Load.open("DefaultPlayer.txt");
	if (Load.is_open())
	{
		Player.SetPeople(&Load, THISIS_PLAYER);
	}
	Load.close();
	
	string Name;
	int attack;
	int prise;


	Load.open("WeaponList.txt");
	if (Load.is_open())
	{
		Load >> m_iWeaponNum;
		m_WeaponBox = new Weapon*[m_iWeaponNum];
		for (int i = 0; i< m_iWeaponNum && !Load.eof(); i++)
		{
			Load >> WeaponName;
			Load >> Name;
			Load >> attack;
			Load >> prise;

			if (WeaponName == "Dagger")
			{
				m_WeaponBox[i] = new Dagger(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
			if (WeaponName == "Bow")
			{
				m_WeaponBox[i] = new Bow(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
			if (WeaponName == "Gun")
			{
				m_WeaponBox[i] = new Gun(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
			if (WeaponName == "Sword")
			{
				m_WeaponBox[i] = new Sword(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
			if (WeaponName == "Wand")
			{
				m_WeaponBox[i] = new Wand(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
			if (WeaponName == "Hammer")
			{
				m_WeaponBox[i] = new Hammer(Name, attack, prise);
				m_WeaponBox[i] = m_WeaponBox[i];
			}
		}
	}
	Load.close();
}

void Manager::Save(int Slot)
{
	ofstream Save;

	char filename[100];

	sprintf(filename, "SaveMonster%d.txt", Slot);
	Save.open(filename);
	if (Save.is_open())
	{
		Save << m_imonster_num << endl;
		for (int i = 0; i < m_imonster_num && !Save.eof(); i++)
		{
			Monster[i].SavePeople(&Save);
		}
		Save.close();

		sprintf(filename, "SavePlayer%d.txt", Slot);
		Save.open(filename);
		if (Save.is_open())
		{
			Player.SavePeople(&Save);
		}
		Save.close();
	}

	system("cls");
	YELLOW
		BoxDraw(0, 0, m_iWindowX, m_iWindowY);
	ORIGINAL
		DrawMidText("저장 완료 !!", m_iWindowX, m_iWindowY / 2);
	getch();
}

void Manager::Load(int Slot)
{
	ifstream Load;
	string WeaponName;
	string weapon_type;
	string name;
	int attack;
	int prise;

	char filename[100];
	sprintf(filename, "SaveMonster%d.txt", Slot);
	Load.open(filename);
	if (Load.is_open())
	{
		Load >> m_imonster_num;
		Monster = new People[m_imonster_num];

		for (int i = 0; i < m_imonster_num && !Load.eof(); i++)
		{
			Monster[i].LoadPeople(&Load, THISIS_MONSTER);
		}
		Load.close();

		sprintf(filename, "SavePlayer%d.txt", Slot);
		Load.open(filename);
		if (Load.is_open())
		{
			Player.LoadPeople(&Load, THISIS_PLAYER);
			if (!Load.eof())
			{
				Load >> weapon_type;
				Load >> name;
				Load >> attack;
				Load >> prise;
				if (weapon_type == "검")
				{
					Load_Weapon = new Sword(name, attack, prise);
				}
				if (weapon_type == "활")
				{
					Load_Weapon = new Bow(name, attack, prise);
				}
				if (weapon_type == "총")
				{
					Load_Weapon = new Gun(name, attack, prise);
				}
				if (weapon_type == "해머")
				{
					Load_Weapon = new Hammer(name, attack, prise);
				}
				if (weapon_type == "완드")
				{
					Load_Weapon = new Wand(name, attack, prise);
				}
				if (weapon_type == "대거")
				{
					Load_Weapon = new Dagger(name, attack, prise);
				}
				Player.TakeWeapon(Load_Weapon, weapon_type);
			}
			Load.close();
		}

		Load.open("WeaponList.txt");
		if (Load.is_open())
		{
			Load >> m_iWeaponNum;
			m_WeaponBox = new Weapon*[m_iWeaponNum];
			for (int i = 0; i< m_iWeaponNum && !Load.eof(); i++)
			{
				Load >> WeaponName;
				Load >> name;
				Load >> attack;
				Load >> prise;

				if (WeaponName == "Dagger")
				{
					m_WeaponBox[i] = new Dagger(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
				if (WeaponName == "Bow")
				{
					m_WeaponBox[i] = new Bow(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
				if (WeaponName == "Gun")
				{
					m_WeaponBox[i] = new Gun(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
				if (WeaponName == "Sword")
				{
					m_WeaponBox[i] = new Sword(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
				if (WeaponName == "Wand")
				{
					m_WeaponBox[i] = new Wand(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
				if (WeaponName == "Hammer")
				{
					m_WeaponBox[i] = new Hammer(name, attack, prise);
					m_WeaponBox[i] = m_WeaponBox[i];
				}
			}
		}
		Load.close();

		system("cls");
		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL
			DrawMidText("불러오기 완료 !!", m_iWindowX, m_iWindowY / 2);
		getch();

	}
	else
	{
		system("cls");
		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL


		DrawMidText("해당파일이 없습니다", m_iWindowX, m_iWindowY / 2);
		getch();
		return;
	}
}

void Manager::SaveLoad(string saveorload)
{
	int select = 0;
	int slot_num;
	char filename[100];
	int line;
	bool flag = true;

	while (flag == true)
	{
		line = m_iWindowY / 2 - 10;

		system("cls");

		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL
			GREEN
			for (slot_num = 1; slot_num <= 10; slot_num++, line += 2)
			{
				gotoxy(m_iWindowX - 12, line);
				cout << slot_num << "번슬롯 : ";

				sprintf(filename, "SavePlayer%d.txt", slot_num);
				if ((fopen(filename, "r")) == NULL)
				{
					sprintf(filename, "SaveMonster%d.txt", slot_num);
					if ((fopen(filename, "r")) == NULL)
					{
						cout << "(파일여부 : X)";
					}
				}
				else
				{
					sprintf(filename, "SaveMonster%d.txt", slot_num);
					if ((fopen(filename, "r")) != NULL)
					{
						cout << "(파일여부 : O)";
					}
				}

			}
		DrawMidText("돌아가기", m_iWindowX - 7, line);
		ORIGINAL

			select = MenuSelectCursor(11, 2, m_iWindowX / 2 - 8, m_iWindowY / 2 - 10);
		slot_num = select;

		switch (select)
		{
		case 11:
			flag = false;
			break;
		default:
			if (saveorload == "save")
			{
				Save(slot_num);
			}
			if (saveorload == "load")
			{
				Load(slot_num);
				GamePlay();
				flag = false;
			}
			break;
		}
	}
	
}

void Manager::ShowMenu()
{
	int select = 0;
	bool Menu_flag=true;
	string PlayerName;

	while (Menu_flag == true)
	{
		system("cls");

		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL

		DrawMidText("☆★ RPG GAME ☆★", m_iWindowX, m_iWindowY / 2 - 6);
		DrawMidText("New Game", m_iWindowX, m_iWindowY / 2 - 3);
		DrawMidText("Load Game", m_iWindowX, m_iWindowY / 2);
		DrawMidText("게임 종료", m_iWindowX, m_iWindowY / 2 + 3);

		select = MenuSelectCursor(3, 3, m_iWindowX / 2 - 4, m_iWindowY / 2 - 3);

		switch (select)
		{
		case 1:
			GameSet();

			system("cls");
			YELLOW
				BoxDraw(0, 0, m_iWindowX, m_iWindowY);
			DrawMidText("Player Name : ", m_iWindowX, m_iWindowY / 2);
			cin >> PlayerName;
			Player.SetPlayerName(PlayerName);
			ORIGINAL
			GamePlay();
			break;
		case 2:
			SaveLoad("load");
			break;
		case 3:
			Menu_flag = false;
			return;
		default:
			break;
		}
	}
	
}

void Manager::GamePlay()
{
	bool Gmae_Menu_flag = true;
	int select;

	while (Gmae_Menu_flag = true)
	{
		system("cls");

		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL
		DrawMidText("☆★ Menu ☆★", m_iWindowX, m_iWindowY / 2 - 6);
		DrawMidText("Dongeon", m_iWindowX, m_iWindowY / 2 - 4);
		DrawMidText("Player Info", m_iWindowX, m_iWindowY / 2 - 2);
		DrawMidText("Monster Info", m_iWindowX, m_iWindowY / 2 );
		DrawMidText("Weapon Shop", m_iWindowX, m_iWindowY / 2 +2);
		DrawMidText("Save", m_iWindowX, m_iWindowY / 2 + 4);
		DrawMidText("돌아가기", m_iWindowX, m_iWindowY / 2 + 6);

		select = MenuSelectCursor(6, 2, m_iWindowX / 2 - 6, m_iWindowY / 2 - 4);
		switch (select)
		{
		case 1:
			Dongeon_index();
			break;
		case 2:
			system("cls");
			YELLOW
				BoxDraw(0, 0, m_iWindowX, m_iWindowY);
			Player.Showinfo(m_iWindowX, m_iWindowY / 2 - 2);
			ORIGINAL
			getch();
			break;
		case 3:
			system("cls");
			YELLOW
				BoxDraw(0, 0, m_iWindowX, m_iWindowY);
			ORIGINAL
			for (int i = 0, line = m_iWindowY / 2 - 12; i < m_imonster_num; i++,line +=4)
			{
				Monster[i].Showinfo(m_iWindowX, line);
			}
			getch();
			break;
		case 4:
			Weapon_shop();
			break;
		case 5:
			SaveLoad("save");
			break;
		case 6:
			for (int i = 0; i < m_iWeaponNum; i++)
			{
				delete m_WeaponBox[i];
			}
			delete[] m_WeaponBox;
			delete[] Monster;
			if (Load_Weapon != NULL)
			{
				delete Load_Weapon;
				Load_Weapon = NULL;
			}
			Player.Delete_My_Weapon();
			Gmae_Menu_flag = false;
			return;
		}

	}
}

void Manager::Dongeon_index()
{
	int select;
	int line = m_iWindowY / 2 - 4;

	system("cls");
	YELLOW
		BoxDraw(0, 0, m_iWindowX, m_iWindowY);
	ORIGINAL
	DrawMidText("===== 던전 입구 =====", m_iWindowX, m_iWindowY / 2 - 8);
	for (int i = 0; i < m_imonster_num; i++,line +=2)
	{
		gotoxy(m_iWindowX - 7, line);
		cout << i+1 << "층 : [" << Monster[i].OutName() << "]";
	}
	DrawMidText("돌아가기", m_iWindowX, line);
	select = MenuSelectCursor(m_imonster_num + 1, 2, m_iWindowX / 2 - 5, m_iWindowY / 2 - 4);

	system("cls");
	if (select < m_imonster_num)
		Dongeon(select - 1);
	else
		return;
}

void Manager::Dongeon(int Monnum)
{
	int control;
	int randum_attack;
	bool Battle_flag = true;
	YELLOW
		BoxDraw(0, 0, m_iWindowX, m_iWindowY);
	ORIGINAL
	while (Battle_flag == true)
	{
		YELLOW
		Player.Showinfo(m_iWindowX, m_iWindowY / 2 - 12);
		DrawMidText("가위 : 1   바위 : 2   보 : 3", m_iWindowX, m_iWindowY / 2 - 6);
		RED
			DrawMidText("─────── v s ───────", m_iWindowX, m_iWindowY / 2);
		ORIGINAL
			Monster[Monnum].Showinfo(m_iWindowX, m_iWindowY - 8);

		control = getch();
		if (control == 32)
			control = getch();
		randum_attack = (rand() % 3) + 1;

		EraseText("~~스킬설명 지우기~~", m_iWindowX / 2 - 12, m_iWindowY / 2 - 1);
		EraseText("행동불능", m_iWindowX / 2 - 4 , m_iWindowY / 2 + 4);
		YELLOW
			switch (control)
			{
			case SCISSOR:
				control = 1;
				DrawMidText("가위", m_iWindowX, m_iWindowY / 2 - 4);
				break;
			case ROCK:
				control = 2;
				DrawMidText("바위", m_iWindowX, m_iWindowY / 2 - 4);
				break;
			case PAPER:
				control = 3;
				DrawMidText("보", m_iWindowX, m_iWindowY / 2 - 4);
				break;
			}
		ORIGINAL
			switch (randum_attack)
			{
			case 1:
				DrawMidText("가위", m_iWindowX, m_iWindowY / 2 + 4);
				break;
			case 2:
				DrawMidText("바위", m_iWindowX, m_iWindowY / 2 + 4);
				break;
			case 3:
				DrawMidText("보", m_iWindowX, m_iWindowY / 2 + 4);
				break;
			}
			if (Player.MY_Weapontype("해머") && Player.Weapon_Attack2(m_iWindowX, m_iWindowY / 2 - 1) == true)
			{
				DrawMidText("행동불능", m_iWindowX, m_iWindowY / 2 + 4);
				control = 4;
			}
		RED
			if (Player.MY_Weapontype("총") && Player.Weapon_Attack2(m_iWindowX, m_iWindowY / 2 - 1) == true)
			{
				Battle_flag == false;
			}
			else
			{
				if (control == 1 && randum_attack == 3)
				{
					DrawMidText("WIN", m_iWindowX, m_iWindowY / 2 - 3);
					DrawMidText("LOSE", m_iWindowX, m_iWindowY / 2 + 3);
					Battle_flag = Monster[Monnum].Life(Player.Go_Attack()
						+ Player.Weapon_Attack(m_iWindowX, m_iWindowY / 2 - 1));
				}
				else if (control == 3 && randum_attack == 1)
				{
					DrawMidText("LOSE", m_iWindowX, m_iWindowY / 2 - 3);
					DrawMidText("WIN", m_iWindowX, m_iWindowY / 2 + 3);
					Battle_flag = Player.Life(Monster[Monnum].Go_Attack());
				}
				else if (control > randum_attack)
				{
					DrawMidText("WIN", m_iWindowX, m_iWindowY / 2 - 3);
					DrawMidText("LOSE", m_iWindowX, m_iWindowY / 2 + 3);
					Battle_flag = Monster[Monnum].Life(Player.Go_Attack()
						+ Player.Weapon_Attack(m_iWindowX, m_iWindowY / 2 - 1));
				}
				else if (control < randum_attack)
				{
					DrawMidText("LOSE", m_iWindowX, m_iWindowY / 2 - 3);
					DrawMidText("WIN", m_iWindowX, m_iWindowY / 2 + 3);
					Battle_flag = Player.Life(Monster[Monnum].Go_Attack());
				}
				else if (control == randum_attack)
				{
					DrawMidText("DRAW", m_iWindowX, m_iWindowY / 2 - 3);
					DrawMidText("DRAW", m_iWindowX, m_iWindowY / 2 + 3);
				}

				if (Player.MY_Weapontype("완드"))
				{
					if (Player.Weapon_Attack2(m_iWindowX, m_iWindowY / 2 - 1) == true)
						Player.Heal();
				}
			}
		ORIGINAL

		if (Battle_flag == false)
		{
			system("cls");
			YELLOW
				BoxDraw(0, 0, m_iWindowX, m_iWindowY);
			ORIGINAL
			RED
			if (Player.Life(0) == false)
			{
				gotoxy(m_iWindowX - 5, m_iWindowY / 2);
				cout << Monster[Monnum].OutName()<<"  승리!!";
				Monster[Monnum].Level_UP(Player.Give_EXP(), 0, m_iWindowX, m_iWindowY);
			}
			else if (Monster[Monnum].Life(0) == false)
			{
				gotoxy(m_iWindowX - 5, m_iWindowY / 2);
				cout << Player.OutName() << "  승리!!";
				Player.Level_UP(Monster[Monnum].Give_EXP(), Monster[Monnum].OutGold(), m_iWindowX, m_iWindowY);
			}
			getch();
			ORIGINAL
		}
	}
}

void Manager::Weapon_shop()
{
	int select;
	int line = m_iWindowY / 2 - 6;
	bool shop_flag = true;

	while (shop_flag == true)
	{
		system("cls");
		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL
			DrawMidText("♤♠ S H O P ♠♤", m_iWindowX, m_iWindowY / 2 - 8);
		DrawMidText("Dagger", m_iWindowX, line);
		DrawMidText("Sword", m_iWindowX, line + 2);
		DrawMidText("Bow", m_iWindowX, line + 4);
		DrawMidText("Hammer", m_iWindowX, line + 6);
		DrawMidText("Wand", m_iWindowX, line + 8);
		DrawMidText("Gun", m_iWindowX, line + 10);
		DrawMidText("돌아가기", m_iWindowX, line + 12);
		select = MenuSelectCursor(7, 2, m_iWindowX / 2 - 4, m_iWindowY / 2 - 6);

		switch (select)
		{
		case 1:
			Shop_page("대거");
			break;
		case 2:
			Shop_page("검");
			break;
		case 3:
			Shop_page("활");
			break;
		case 4:
			Shop_page("해머");
			break;
		case 5:
			Shop_page("완드");
			break;
		case 6:
			Shop_page("총");
			break;
		default:
			shop_flag = false;
			break;
		}
	}

}

void Manager::Shop_page(string name)
{
	int i = 0;
	int select;
	int weaponeNum = 0;
	int buy_weapon = 0;
	int show_num = 0;
	int page = 0;
	string shopname = name;
	bool flag = true;
	for (int i = 0; i < m_iWeaponNum; i++)
	{
		if (m_WeaponBox[i]->CheckWeapone(name))
		{
			weaponeNum++;
		}
	}
	Weapon** ShopList = new Weapon*[weaponeNum];
	for (int i = 0, j= 0; i < m_iWeaponNum; i++)
	{
		if (m_WeaponBox[i]->CheckWeapone(name))
		{
			ShopList[j] = m_WeaponBox[i];
			j++;
		}
	}
	while (flag == true)
	{
		system("cls");
		YELLOW
			BoxDraw(0, 0, m_iWindowX, m_iWindowY);
		ORIGINAL

			TextDraw("보유 GOLD : ", m_iWindowX / 2 + 8, m_iWindowY / 2 - 13);
		cout << Player.OutGold();
		TextDraw(name, m_iWindowX / 2 + 12, m_iWindowY / 2 - 11);
		cout << " 목록";
		YELLOW
			for (int i = show_num, line = m_iWindowY / 2 - 7; i < weaponeNum && i < show_num + 4; i++)
			{
				if (ShopList[i]->ShowInfo(m_iWindowX - 2, line, name) == true)
				{
					line += 3;
				}
			}
		ORIGINAL
			DrawMidText("이전 페이지", m_iWindowX, m_iWindowY / 2 + 6);
		DrawMidText("다음 페이지", m_iWindowX, m_iWindowY / 2 + 9);
		DrawMidText("나가기", m_iWindowX, m_iWindowY / 2 + 12);
		select = MenuSelectCursor(7, 3, m_iWindowX / 2 - 10, m_iWindowY / 2 - 6);
		switch (select)
		{
		case 1:
			if (page == 0)
				buy_weapon = select - 1;
			else if(page > 0)
				buy_weapon = select - 1 + (4 * page);
			if (Player.OutGold() > 0)
			{
				Player.Buy_Weapon(ShopList[buy_weapon]->OutPrise());
				Player.TakeWeapon(ShopList[buy_weapon], name);
			}
			break;
		case 2:
			if (page == 0)
				buy_weapon = select - 1;
			else if (page > 0)
				buy_weapon = select - 1 + (4 * page);
			if (Player.OutGold() > 0)
			{
				Player.Buy_Weapon(ShopList[buy_weapon]->OutPrise());
				Player.TakeWeapon(ShopList[buy_weapon], name);
			}
			break;
		case 3:
			if (page == 0)
				buy_weapon = select - 1;
			else if (page > 0)
				buy_weapon = select - 1 + (4 * page);
			if (Player.OutGold() > 0)
			{
				Player.Buy_Weapon(ShopList[buy_weapon]->OutPrise());
				Player.TakeWeapon(ShopList[buy_weapon], name);
			}
			break;
		case 4:
			if (page == 0)
				buy_weapon = select - 1;
			else if (page > 0)
				buy_weapon = select - 1 + (4 * page);
			if (Player.OutGold() > 0)
			{
				Player.Buy_Weapon(ShopList[buy_weapon]->OutPrise());
				Player.TakeWeapon(ShopList[buy_weapon], name);
			}
			break;
		case 5:
			if (show_num < 4)
				break;
			ErasePoint(m_iWindowX / 2 - 10, m_iWindowY / 2 + 6);
			page--;
			show_num -= 4;
			break;
		case 6:
			if (show_num <= weaponeNum && show_num >= 4)
				break;
			ErasePoint(m_iWindowX / 2 - 10, m_iWindowY / 2 + 9);
			page++;
			show_num += 4;
			break;
		case 7:
			delete[] ShopList;
			flag = false;
			break;
		}
	}
}

Manager::~Manager()
{
}
