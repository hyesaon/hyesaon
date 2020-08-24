#pragma once
#include "Student.h"

class Std_manager 
{
	Student* std[30];

	static Std_manager* m_This;
public:
	Std_manager();
	static Std_manager* GetInstance()
	{
		if (m_This == NULL)
			m_This = new Std_manager;

		return m_This;
	}
	void display();
	void setStudent();
	void showStudent();
	void findNumber();
	void findname();
	void findClass();
	~Std_manager()
	{
		for (int i = 0; i < 30; i++)
		{
			delete std[i];
		}
	}

};

