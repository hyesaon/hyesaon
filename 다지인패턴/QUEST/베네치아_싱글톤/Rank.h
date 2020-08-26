#pragma once
#include "Interface.h"
class Rank
{
private:
	Interface m_Draw;
	string m_strName;
	int m_iStage;
	int m_iScore;
public:
	Rank();
	Rank(string Name,int stage,int score);
	void RankShow(int x,int y);
	void Save(ofstream &Save);
	void Load(ifstream &Load);
	bool operator <(Rank tmp);
	~Rank();
};

