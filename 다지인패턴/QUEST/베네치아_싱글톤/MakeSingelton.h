#pragma once
#include"Mecro.h"
template<typename classname>
class MakeSingelton
{
private:
	static classname* m_Hthis;
public:
	MakeSingelton() {}
	static classname* GetInstance()
	{
		if (m_Hthis == NULL)
			m_Hthis = new classname;
		return m_Hthis;
	}
	~MakeSingelton() {}
};

