#include "Rank.h"



Rank::Rank()
{
}

Rank::Rank(string Name, int stage, int score)
{
	m_strName = Name;
	m_iStage = stage;
	m_iScore = score;
}

void Rank::RankShow(int x, int y)
{
	m_Draw.Text(m_strName + "\t\t\t" + to_string(m_iScore) + "\t\t\t" + to_string(m_iStage), x/2 + 4, y);
}

void Rank::Save(ofstream &Save)
{
	Save << m_strName << " " << m_iStage << " " << m_iScore << endl;
}

void Rank::Load(ifstream &Load)
{
	Load >> m_strName;
	Load >> m_iStage;
	Load >> m_iScore;
}

bool Rank::operator <(Rank tmp)
{
	if (this->m_iStage < tmp.m_iStage)
	{
		return true;
	}
	else if (this->m_iScore < tmp.m_iScore)
	{
		if (this->m_iStage > tmp.m_iStage)
			return false;

		return true;
	}
	else
	{
		return false;
	}
}


Rank::~Rank()
{
}
