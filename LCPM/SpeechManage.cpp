#include "SpeechManage.h"

//���캯��
SpeechManage::SpeechManage()
{

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