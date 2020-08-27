#pragma once
#include"People.h"

#define SCISSOR 49
#define ROCK 50
#define PAPER 51


class Manager : public MapDraw
{
private:
	int m_iWindowX;
	int m_iWindowY;
	People* Monster;
	People Player;
	int m_imonster_num;
	Weapon** m_WeaponBox;
	Weapon* Load_Weapon;
	int m_iWeaponNum;
protected:
	void GameSet();
	void SaveLoad(string saveorload);
	void Save(int Slot);
	void Load(int Slot);
	void Dongeon_index();
	void Weapon_shop();
	void Shop_page(string name);
	void Dongeon(int Monnum);
public:
	Manager();
	void GamePlay();
	void ShowMenu();
	~Manager();
};

