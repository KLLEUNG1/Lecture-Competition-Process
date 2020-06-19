#include <iostream>
#include "SpeechManage.h"
using namespace std;

int main()
{
	//创建管理类对象
	SpeechManage sm;

	

	int choice = 0;   //用于存储用户输入

	while (true)
	{
		sm.show_menu();

		cout << "请输入您得选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:   //1.开始比赛
			break;  
		case 2:   //2.查看往届比赛记录
			break;
		case 3:   //3.清空比赛记录
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