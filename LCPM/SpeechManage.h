#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>  //�����㷨ͷ�ļ�
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

	//��Ա����
	vector<int>v1;	//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int>v2;	//��һ�ֽ���ѡ�ֱ������
	vector<int>vwinner;	//ʤ����ǰ����ѡ�ֱ������
	map<int, Speaker>speaker;	//��ű���Լ���Ӧ����ѡ������
	int round;	//��ű�������
};
