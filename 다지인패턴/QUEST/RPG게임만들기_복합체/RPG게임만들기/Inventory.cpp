#include "Inventory.h"

/*
	void Add(Inventory* Inventory) override;
	inventory->SetParent(this);	inventoryList.push_back(inventory);
	void Remove(Inventory* Inventory) override;
	vector<Inventory*>::iterator remove = find(inventoryList.begin(), inventoryList.end(), inventory);

	if (remove != inventoryList.end())
	{
		inventoryList.erase(remove);
	}
	���� ���ְ�,

	�Ŵ�������
		�κ��丮* ���� �ϳ� �������,
		�κ��丮* �� ���Ⱑ�� �����
		�ε��Ҷ� �κ��丮 * �� ����(�ε� �Ű躯��);
		�� ���Ⱑ�濡 Add �����
		���Ⱑ���� ���ο� Add
		> ����������� ����� �ҷ��� �� ���� ���游 �ҷ������
			�˰���->Inventory_List[����] > ����
*/