#include "SpeechManage.h"

//���캯��
SpeechManage::SpeechManage()
{
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->creatSpeaker();
}

//��������
SpeechManage::~SpeechManage()
{

}

//�˵�����
void SpeechManage::show_menu()
{
	cout << "*************************************************" << endl;
	cout << "**************** ��ӭ�μ��ݽ����� ***************" << endl;
	cout << "***************** 1.��ʼ�ݽ����� ****************" << endl;
	cout << "***************** 2.�鿴����ɼ� ****************" << endl;
	cout << "***************** 3.��ձ�����¼ ****************" << endl;
	cout << "***************** 0.�˳��������� ****************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManage::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManage::initSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vwinner.clear();
	this->speaker.clear();

	//��ʼ����������
	this->round = 1;
}

//����12��ѡ��
void SpeechManage::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.s_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷ�������v1
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�֣���������map��
		this->speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ�����������������̿��ƺ���
void SpeechManage::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1����ǩ
	this->speechDraw();

	//2������

	//3����ʾ�������

	//�ڶ��ֿ�ʼ����

	//1����ǩ

	//2������

	//3����ʾ���ս��

	//4������������ļ���
}

//��ǩ
void SpeechManage::speechDraw()
{
	cout << "��" << this->round << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout <<"------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->round == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());   //ϴ���㷨
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
	system("pause");
	cout << endl;
}