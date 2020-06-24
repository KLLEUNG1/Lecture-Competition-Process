#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>  //�����㷨ͷ�ļ�
#include <deque>	//deque����
#include <functional>	//greater���ڽ���������
#include <numeric>	//����accumulate
#include <string>

using namespace std;

//����ݽ�����������
class SpeechManage
{
public:
	SpeechManage();   //���캯��

	~SpeechManage();   //��������

	void show_menu();   //չʾ�˵�

	void exitSystem();	 //�˳�ϵͳ

	void creatSpeaker();	//����12��ѡ��
	
	void initSpeech();	//��ʼ������������

	void startSpeech();   //��ʼ�����������������̿��ƺ���

	void speechDraw();	 //��ǩ

	void speechContest();	//����

	void showScore();	//��ʾ�÷�

	//��Ա����
	vector<int>v1;	//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int>v2;	//��һ�ֽ���ѡ�ֱ������
	vector<int>vwinner;	//ʤ����ǰ����ѡ�ֱ������
	map<int, Speaker>m_speaker;	//��ű���Լ���Ӧ����ѡ������
	int m_round;	//��ű�������
};
