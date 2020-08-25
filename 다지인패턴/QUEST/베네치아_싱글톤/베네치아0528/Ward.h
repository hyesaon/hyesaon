#pragma once
#include "Interface.h"

class Ward
{
protected:
	string m_strward;
	Pos m_WardPos;
	Interface Draw;
	bool m_bWard_State; //화면에 표시 될 단어와 아닐 단어를 구분
public:
	Ward();
	void SetStr(string myward);
	void Ward_State_Set(); //플레이시 워드를 하나씩만 만들어 떨어트리도록 bool세팅
	inline bool Out_Ward_State()
	{
		return m_bWard_State;
	}
	bool Drop();//떨어짐
	void Scoll();//올라감
	void Y_Set(); //Y좌표 재정의
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