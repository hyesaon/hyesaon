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
	정의 해주고,

	매니저에서
		인벤토리* 메인 하나 만든다음,
		인벤토리* 각 무기가방 만들고
		로드할때 인벤토리 * 뉴 무기(로드 매계변수);
		각 무기가방에 Add 무기들
		무기가방을 메인에 Add
		> 무기상점에서 무기들 불러올 때 무기 가방만 불러오면됨
			검가방->Inventory_List[순서] > 접근
*/