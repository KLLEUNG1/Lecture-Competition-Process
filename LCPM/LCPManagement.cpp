#include <iostream>
#include "SpeechManage.h"
#include <string>
using namespace std;

int main()
{
	//�������������
	SpeechManage sm;

	/*����12��ѡ�ִ���
	for (map<int, Speaker>::iterator it = sm.speaker.begin();
		it != sm.speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< "  ������" << it->second.s_name
			<< "  ������" << it->second.score[0] << endl;
	}*/

	int choice = 0;   //���ڴ洢�û�����

	while (true)
	{
		sm.show_menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;   //�����û���ѡ��

		switch (choice)
		{
		case 1:   //1.��ʼ����
			sm.startSpeech();
			break;  
		case 2:   //2.�鿴���������¼
			break;
		case 3:   //3.��ձ�����¼
			break;
		case 0:   //0.�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");  //����
			break;
		}
	}

	system("pause");
	return 0;
}