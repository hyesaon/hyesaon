#pragma once
#include "Interface.h"

class Ward
{
protected:
	string m_strward;
	Pos m_WardPos;
	Interface Draw;
	bool m_bWard_State; //ȭ�鿡 ǥ�� �� �ܾ�� �ƴ� �ܾ ����
public:
	Ward();
	void SetStr(string myward);
	void Ward_State_Set(); //�÷��̽� ���带 �ϳ����� ����� ����Ʈ������ bool����
	inline bool Out_Ward_State()
	{
		return m_bWard_State;
	}
	bool Drop();//������
	void Scoll();//�ö�
	void Y_Set(); //Y��ǥ ������
	inline Pos Out_WardPos()
	{
		return m_WardPos;
	}
	inline string OutWard()
	{
		return m_strward;
	}
	~Ward();
};