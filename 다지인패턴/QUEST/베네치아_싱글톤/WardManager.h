#pragma once
#include"GameWard.h"
#include "MakeSingelton.h"
#include "MakeSingelton.cpp"
#define STORY_TIME 500
#define GAMEWARD_SHOW_TIME 2000

class WardManager : public MakeSingelton<WardManager>
{
private:	
	Interface m_Draw;
	int m_iMake_time;
	int m_iDrop_time;
	int m_iDrop_Speed;
	GameWard* m_WardList;
	int m_iWardListNum;
	Ward* m_Story;
	int m_iStoryNum;
	GameWard* m_strGamePlay_WardList;
	int m_iGameWardNum;
	//아이템용 시간변수들
	int m_iALLStop_time;
	int m_iALLSpeedSet_time;
	int ALL_Blind_time;
	bool m_bStop_state;
	bool m_bBlind_state;
public:
	WardManager();
	void SetGameStart(int Stage);
	bool TextBox_REdraw(string typing);
	void SetWard(); //게임 시작시 불러오기
	void SetGameWard(int stage); //게임전용 단어들 하나씩 보여주기
	bool ShowStory();//한줄씩 스토리 호출
	bool Answer(string ward_typing, int &score); //친 단어가 들어오면 배열 next m_GmaePlay_WardList 돌려서 맞는것 찾으면 true반환
	void MakeWard(int stage); //게임전용 단어배열 생성
	int GameWardList_Drop(int stage, string typing); //MakeWard(); 와 Drop();호출 
	void Delete_GamePlay_WardList(); //위 함수 호출하는 오버로딩
	int Item_Call(int(GameWard::*item)(GameWard*, int)); //아이템 호출

	~WardManager();
};

