#pragma once
#include<iostream>
template<typename classname>
class makesingelton
{
private:
	static classname* m_This;
public:
	makesingelton() {}
	//classname* makesingelton<classname>::m_This = NULL; //���� ������ ���� ������ ������ ������ ����.
	static classname* GetInstance()
	{
		if (m_This == NULL)
			m_This = new classname;

		return m_This;
	}
	~makesingelton() {}
};

