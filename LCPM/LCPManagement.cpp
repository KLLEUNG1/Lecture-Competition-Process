#include <iostream>
#include "SpeechManage.h"
#include <string>
#include <ctime> //包含随机入种
using namespace std;

int main()
{
	

	//随机数种子
	srand((unsigned int)time(NULL));

	//创建管理类对象
	SpeechManage sm;

	sm.background();

	/*测试12名选手创建
	for (map<int, Speaker>::iterator it = sm.speaker.begin();
		it != sm.speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< "  姓名：" << it->second.s_name
			<< "  分数：" << it->second.score[0] << endl;
	}*/

	int choice = 0;   //用于存储用户输入

	while (true)
	{
		sm.show_menu();

		cout << " 请输入您得选择："<<endl ;
		cout << " ";
		cin >> choice;   //接受用户得选项

		switch (choice)
		{
		case 1:   //1.开始比赛
			sm.startSpeech();
			break;  
		case 2:   //2.查看往届比赛记录
			sm.showRecord();
			break;
		case 3:   //3.清空比赛记录
			sm.clearRecord();
			break;
		case 0:   //0.退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");  //清屏
			break;
		}
	}

	system("pause");
	return 0;
}