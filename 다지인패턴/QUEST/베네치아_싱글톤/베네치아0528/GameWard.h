#pragma once
#include "Ward.h"

enum ITEM
{
	ITEM_BLIND = 1,
	ITEM_CLEAR,
	ITEM_SPEED_UP,
	ITEM_SPEED_DOWN,
	ITEM_STOP
};

class GameWard : public Ward
{
protected:
	int m_idrop_time;
	int m_iSpeed;
	bool m_bItem_State;
	int m_iblind_time;
	string m_strBlindWard;
	ITEM m_eMyItem;
public:
	GameWard();
	void XY_Set(); //x좌표 랜덤생성
	void Erase(); //정답일시 해당 단어 지우기
	inline bool Out_ItemState()
	{
		return m_bItem_State;
	}
	inline ITEM Out_Item_Enum()
	{
		return m_eMyItem;
	}
	void Set_Item();
	void Set_Blind_Time();
	void Clear_Item();
	void Blind_Drop(); //이 단어가 아이템이라면 떨어질때 기본으로 1.5초 안보이기
	int All_Ward_Blind(GameWard* wardlist, int Wradnum);
	int All_Ward_Clear(GameWard* wardlist, int Wradnum);
	~GameWard();
};


