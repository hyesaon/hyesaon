#include "Inventory.h"

void Inventory::Set_Parent(Inventory* parent)
{
	m_parent = parent;
}
Inventory* Inventory::Get_parent()
{
	return m_parent;
}

const string Inventory::Out_Inventory_name()
{
	return m_name;
}

void Bag::Add(Inventory* Inventory)
{
	Inventory->Set_Parent(this);
	Inventory_List.push_back(Inventory);
}

void Bag::Remove(Inventory* m_Inventory)
{
	vector<Inventory*>::iterator remove = find(Inventory_List.begin(), Inventory_List.end(), m_Inventory);

	if (remove != Inventory_List.end())
	{
		Inventory_List.erase(remove);
	}
}

int Bag::Out_Inventory_size()
{
	return Inventory_List.size();
}

Inventory* Bag::Find_Inventory(string name)
{
	vector<Inventory*>::iterator find = Inventory_List.begin();

	for (find; find != Inventory_List.end(); find++)
	{
		if ((*find)->Out_Inventory_name() == name)
			return *find;
	}
	return NULL;
}

bool Bag::ShowInfo(int shownum , int x, int y, string name)
{
	for (int i = shownum, line = y; i < Inventory_List.size() && i < shownum + 4; i++)
	{
		if (Inventory_List[i]->ShowInfo(shownum, x, line, Inventory_List[i]->Out_Inventory_name()) == true)
		{
			line += 3;
		}
	}
	return true;
}