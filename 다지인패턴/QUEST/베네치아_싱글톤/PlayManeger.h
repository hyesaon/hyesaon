#pragma once
#include"Rank.h"
#include"WardManager.h"
#define PENALTY_TIME 4000

class PlayManeger : public MakeSingelton<PlayManeger>
{
private:
	Interface m_Drawtool;
	string m_strName;
	int m_iLife;
	int m_iScore;
	int m_iStage;
	bool m_btyping_flag;
	int m_iOldTime;
	int m_iWordNum;
	Rank m_RankList[10];
public:
	PlayManeger();
	void GmaeSet(); //��ũ,���丮,�ܾ��� �ҷ�����
	void Menu(); //Ÿ��Ʋ
	bool Game_Pause();
	void Game_Over();
	void Play_intro();
	bool GamePlay_Typing(string &typing);
	void Play(); //�����÷���
	void Save_Rank(string name, int stage, int score);
	//��������� �̸� �Է� �� ��ũ ����, �������� ���Ŀ� �Լ� 10�������� �����ϰ� ������ ����
	void Show_Ranking(); //��ŷ �����ִ� ������
	~PlayManeger();
};

