#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include "Inventory.h"

class Weapon : public Inventory
{
private:
	char m_chrName[50];
	int m_iPrise;
	char m_chrtype[10];

protected:
	MapDraw m_Draw;
	int m_iAttact;
	int m_iSkill;
	virtual void SetType(string Type);
public:
	void Add(Inventory* Inventory) {};
	void Remove(Inventory* Inventory) {};
	Weapon(string Name, int attack, int prise); //���� �⺻����
	Weapon(Weapon* tmp); //���� ����� ������
	virtual bool CheckWeapone(string name);
	virtual bool ShowInfo(int x, int y, string name); //���⼥ ����Ʈ
	virtual string ShowMyWeapon(); //���Ž� �÷��̾� �������� ������ ���⼳��
	virtual int SkillAttack(int x,int y) = 0; //Ư���� ��� int
	virtual bool SkillAttack2(int x, int y) = 0; //Ư���� ��� bool
	virtual void SaveWeapon(ofstream* Save);
	virtual string OutType()
	{
		return m_chrtype;
	}
	virtual int OutPrise()
	{
		return m_iPrise;
	}
	virtual int Damage() //����������
	{
		return m_iAttact;
	}

	virtual ~Weapon();
};

class Bow : public Weapon
{
public:
	Bow(string Name, int attack, int prise) :Weapon(Name, attack, prise) 
	{ SetType("Ȱ"); }
	Bow(Weapon* tmp) : Weapon(tmp) {}
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Bow();
};

class Dagger : public Weapon
{
private:
	int m_iturn;
public:
	Dagger(string Name, int attack, int prise) : Weapon(Name, attack, prise)
	{
		m_iturn = 0;
		SetType("���");
	}
	Dagger(Weapon* tmp) : Weapon(tmp) { m_iturn = 0; };
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Dagger();
};

class Gun : public Weapon
{
public:
	Gun(string Name, int attack, int prise) : Weapon(Name, attack, prise)
	{
		SetType("��");
	}
	Gun(Weapon* tmp) : Weapon(tmp) {};
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Gun();
};

class Hammer : public Weapon
{

public:
	Hammer(string Name, int attack, int prise) : Weapon(Name, attack, prise)
	{
		SetType("�ظ�");
	}
	Hammer(Weapon* tmp) : Weapon(tmp) {};
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Hammer();
};

class Sword : public Weapon
{
public:
	Sword(string Name, int attack, int prise) : Weapon(Name, attack, prise)
	{
		SetType("��");
	}
	Sword(Weapon* tmp) : Weapon(tmp) {};
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Sword();
};

class Wand : public Weapon
{
public:
	Wand(string Name, int attack, int prise) : Weapon(Name, attack, prise)
	{
		SetType("�ϵ�");
	}
	Wand(Weapon* tmp) : Weapon(tmp) {};
	int SkillAttack(int x, int y);
	bool SkillAttack2(int x, int y);
	~Wand();
};