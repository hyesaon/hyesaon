#pragma once
#include"Mecro.h"
#include"Weapon.h"
#include"MapDraw.h"
#include"Bow.h"
#include"Dagger.h"
#include"Gun.h"
#include"Hammer.h"
#include"Sword.h"
#include"Wand.h"

enum THISIS
{
	THISIS_PLAYER = 1,
	THISIS_MONSTER
};

class People : public MapDraw
{
private:
	THISIS m_eWho;
	char m_chrName[50];
	int m_iLevel;
	int m_iMaxLife;
	int m_iLife;
	int m_iattack;
	int m_iGold;
	int m_iNowEXP;
	int m_iMaxEXP;
	int m_iGiveEXP;
	Weapon* m_MyWeapon;
public:
	People();
	//공격력 변화,인벤토리,생명력변화,경험치 변화,골드 변화,레벨업 함수 필요
	void Showinfo(int x, int y);
	inline string OutName()
	{
		return m_chrName;
	}
	inline int OutGold()
	{
		return m_iGold;
	}
	void Buy_Weapon(int price);
	void SetPeople(ifstream* Load, THISIS who);
	void TakeWeapon(Weapon* weapon, string type);
	void SetPlayerName(string Name);
	void SavePeople(ofstream* Save);
	void LoadPeople(ifstream* Load, THISIS who);
	inline int Go_Attack()
	{
		return m_iattack;
	}
	void Level_UP(int EXP,int Gold, int x, int y);
	bool Life(int attack);
	int Give_EXP();
	int Weapon_Attack(int x, int y);
	bool Weapon_Attack2(int x, int y);
	bool MY_Weapontype(string name);
	void Delete_My_Weapon();
	void Heal();
	~People();
};

