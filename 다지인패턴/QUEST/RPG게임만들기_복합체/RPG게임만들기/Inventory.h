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

	void Set_Parent(Inventory* parent);
	Inventory* Get_parent();
};

class Bag : public Inventory
{
private:
	vector<Inventory*> Inventory_List;
public:
	Bag(string name) : Inventory(name) {};

	void Add(Inventory* Inventory) override;
	void Remove(Inventory* Inventory) override;

	~Bag() { Inventory_List.clear(); };
};