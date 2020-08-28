#pragma once
#include"Mecro.h"
#include<vector>

class Inventory
{
private:
	Inventory* m_parent;
	const string m_name;
public:
	Inventory(string name) : m_name(name) { m_parent = NULL; };

	virtual void Add(Inventory* Inventory) = 0;
	virtual void Remove(Inventory* Inventory) = 0;
	virtual Inventory* Find_Inventory(string name) = 0;
	virtual bool ShowInfo(int shownum ,int x, int y, string name) = 0;
	virtual int Out_Inventory_size() { return 0; };
	virtual int OutPrise(int num) { return 0; };
	virtual void Save(ofstream* Save) {};

	virtual Inventory* OutItem(int num)
	{
		return NULL;
	}

	void Set_Parent(Inventory* parent);
	Inventory* Get_parent();
	const string Out_Inventory_name();
};

class Bag : public Inventory
{
private:
	vector<Inventory*> Inventory_List;
public:
	Bag(string name) : Inventory(name) {};

	void Add(Inventory* Inventory) override;
	void Remove(Inventory* Inventory) override;
	Inventory* Find_Inventory(string name) override;
	bool ShowInfo(int shownum ,int x, int y, string name) override;
	void Save(ofstream* Save);
	virtual int Out_Inventory_size();
	virtual int OutPrise(int num)
	{
		return Inventory_List[num]->OutPrise(num);
	}
	virtual Inventory* OutItem(int num)
	{
		return Inventory_List[num];
	}
	~Bag() { Inventory_List.clear(); };
};