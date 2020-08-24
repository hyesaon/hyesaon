#pragma once
#include<iostream>
template<typename classname>
class makesingelton
{
private:
	static classname* m_This;
public:
	makesingelton() {}
	//classname* makesingelton<classname>::m_This = NULL; //구문 오류는 나지 않지만 컴파일 오류가 난다.
	static classname* GetInstance()
	{
		if (m_This == NULL)
			m_This = new classname;

		return m_This;
	}
	~makesingelton() {}
};

