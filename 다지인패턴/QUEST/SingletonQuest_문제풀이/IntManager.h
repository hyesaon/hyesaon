#pragma once
#include"Int.h"
#include "makesingelton.h"
#include "makesingelton.cpp" //���ø��� �����cpp���� ǥ�⸦ �������� �ʴ´�. �׷��� ���⿡ ��Ŭ��� �ؾ���.
#include<vector>
using namespace std;

class IntManager : public makesingelton<IntManager> //����ؼ� �����ϰ� �̱��� ������ ���� �� �ֵ���!
{
	vector<Int*>  m_vecIntList;

public:
	int GetSize()
	{
		return m_vecIntList.size();
	}
	void Insert();
	void ShowList();

	IntManager();
	~IntManager();

};

