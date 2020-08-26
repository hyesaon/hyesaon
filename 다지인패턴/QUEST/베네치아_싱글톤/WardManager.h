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
	//�����ۿ� �ð�������
	int m_iALLStop_time;
	int m_iALLSpeedSet_time;
	int ALL_Blind_time;
	bool m_bStop_state;
	bool m_bBlind_state;
public:
	WardManager();
	void SetGameStart(int Stage);
	bool TextBox_REdraw(string typing);
	void SetWard(); //���� ���۽� �ҷ�����
	void SetGameWard(int stage); //�������� �ܾ�� �ϳ��� �����ֱ�
	bool ShowStory();//���پ� ���丮 ȣ��
	bool Answer(string ward_typing, int &score); //ģ �ܾ ������ �迭 next m_GmaePlay_WardList ������ �´°� ã���� true��ȯ
	void MakeWard(int stage); //�������� �ܾ�迭 ����
	int GameWardList_Drop(int stage, string typing); //MakeWard(); �� Drop();ȣ�� 
	void Delete_GamePlay_WardList(); //�� �Լ� ȣ���ϴ� �����ε�
	int Item_Call(int(GameWard::*item)(GameWard*, int)); //������ ȣ��

	~WardManager();
};

