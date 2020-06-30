#pragma once
#include <iostream>
#include <vector> 
#include <map>
#include "Speaker.h"
#include <algorithm>  //包含算法头文件 洗牌
#include <deque>	//deque容器
#include <functional>	//greater是内建函数对象
#include <numeric>	//包含accumulate
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

//设计演讲比赛管理类
class SpeechManage
{
public:
	SpeechManage();   //构造函数

	~SpeechManage();   //析构函数

	void background();	//背景颜色

	void show_menu();   //展示菜单

	void exitSystem();	 //退出系统

	void creatSpeaker();	//创建12名选手
	
	void initSpeech();	//初始化容器和属性

	void startSpeech();   //开始比赛。比赛整个流程控制函数

	void speechDraw();	 //抽签

	void speechContest();	//比赛

	void showScore();	//显示得分

	void saveRecord();	//保存记录

	void loadRecord();	//读取记录

	void showRecord();	//显示往届记录

	bool fileIsEmpty;	//判断文件是否为空

	void clearRecord();	//清空文件

	map<int, vector<string>>m_Record;	//存放往届记录的容器

	//成员属性
	vector<int>v1;	//保存第一轮比赛选手编号的容器
	vector<int>v2;	//第二轮晋级选手编号容器
	vector<int>vwinner;	//胜出的前三名选手编号容器
	map<int, Speaker>m_speaker;	//存放编号以及对应具体选手容器
	int m_round;	//存放比赛轮数
};
