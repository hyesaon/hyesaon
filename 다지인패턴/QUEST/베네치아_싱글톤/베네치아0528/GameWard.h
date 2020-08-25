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
	void XY_Set(); //x��ǥ ��������
	void Erase(); //�����Ͻ� �ش� �ܾ� �����
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
	void Blind_Drop(); //�� �ܾ �������̶�� �������� �⺻���� 1.5�� �Ⱥ��̱�
	int All_Ward_Blind(GameWard* wardlist, int Wradnum);
	int All_Ward_Clear(GameWard* wardlist, int Wradnum);
	~GameWard();
};


