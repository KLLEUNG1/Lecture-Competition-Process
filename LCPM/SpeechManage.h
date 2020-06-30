#pragma once
#include <iostream>
#include <vector> 
#include <map>
#include "Speaker.h"
#include <algorithm>  //�����㷨ͷ�ļ� ϴ��
#include <deque>	//deque����
#include <functional>	//greater���ڽ���������
#include <numeric>	//����accumulate
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

//����ݽ�����������
class SpeechManage
{
public:
	SpeechManage();   //���캯��

	~SpeechManage();   //��������

	void background();	//������ɫ

	void show_menu();   //չʾ�˵�

	void exitSystem();	 //�˳�ϵͳ

	void creatSpeaker();	//����12��ѡ��
	
	void initSpeech();	//��ʼ������������

	void startSpeech();   //��ʼ�����������������̿��ƺ���

	void speechDraw();	 //��ǩ

	void speechContest();	//����

	void showScore();	//��ʾ�÷�

	void saveRecord();	//�����¼

	void loadRecord();	//��ȡ��¼

	void showRecord();	//��ʾ�����¼

	bool fileIsEmpty;	//�ж��ļ��Ƿ�Ϊ��

	void clearRecord();	//����ļ�

	map<int, vector<string>>m_Record;	//��������¼������

	//��Ա����
	vector<int>v1;	//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int>v2;	//�ڶ��ֽ���ѡ�ֱ������
	vector<int>vwinner;	//ʤ����ǰ����ѡ�ֱ������
	map<int, Speaker>m_speaker;	//��ű���Լ���Ӧ����ѡ������
	int m_round;	//��ű�������
};
