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
	void GmaeSet(); //랭크,스토리,단어목록 불러오기
	void Menu(); //타이틀
	bool Game_Pause();
	void Game_Over();
	void Play_intro();
	bool GamePlay_Typing(string &typing);
	void Play(); //게임플레이
	void Save_Rank(string name, int stage, int score);
	//게임종료시 이름 입력 후 랭크 저장, 내림차순 정렬용 함수 10개까지만 저장하고 나머지 버림
	void Show_Ranking(); //랭킹 보여주는 페이지
	~PlayManeger();
};

