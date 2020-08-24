#pragma once
#include"Int.h"
#include<vector>
using namespace std;

class IntManager
{
	vector<Int*>  m_vecIntList;

	static IntManager* m_hThis;
public:
	static IntManager* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new IntManager;

		return m_hThis;
	}

	int GetSize()
	{
		return m_vecIntList.size();
	}
	void Insert();
	void ShowList();

	IntManager();
	~IntManager();

};

