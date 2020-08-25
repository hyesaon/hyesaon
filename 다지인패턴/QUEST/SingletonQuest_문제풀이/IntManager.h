#pragma once
#include"Int.h"
#include "makesingelton.h"
#include "makesingelton.cpp" //템플릿은 헤더와cpp분할 표기를 지원하지 않는다. 그래서 여기에 인클루드 해야함.
#include<vector>
using namespace std;

class IntManager : public makesingelton<IntManager> //상속해서 간단하게 싱글톤 패턴을 만들 수 있도록!
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

