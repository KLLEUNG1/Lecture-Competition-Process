#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>  //包含算法头文件
using namespace std;

//设计演讲比赛管理类
class SpeechManage
{
public:
	SpeechManage();   //构造函数

	~SpeechManage();   //析构函数

	void show_menu();   //展示菜单

	void exitSystem();	 //退出系统

	void creatSpeaker();	//创建12名选手
	
	void initSpeech();	//初始化容器和属性

	void startSpeech();   //开始比赛。比赛整个流程控制函数

	void speechDraw();	 //抽签

	//成员属性
	vector<int>v1;	//保存第一轮比赛选手编号的容器
	vector<int>v2;	//第一轮晋级选手编号容器
	vector<int>vwinner;	//胜出的前三名选手编号容器
	map<int, Speaker>speaker;	//存放编号以及对应具体选手容器
	int round;	//存放比赛轮数
};
