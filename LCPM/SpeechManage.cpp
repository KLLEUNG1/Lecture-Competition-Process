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
	this->m_speaker.clear();

	//��ʼ����������
	this->m_round = 1;
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
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷ�������v1
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�֣���������map��
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ�����������������̿��ƺ���
void SpeechManage::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1����ǩ
	speechDraw();

	//2������
	speechContest();

	//3����ʾ�������
	showScore();

	//�ڶ��ֿ�ʼ����
	m_round++;

	//1����ǩ
	speechDraw();

	//2������
	speechContest();

	//3����ʾ���ս��
	showScore();

	//4������������ļ���
}

//��ǩ
void SpeechManage::speechDraw()
{
	cout << "��" << this->m_round << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout <<"------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_round == 1)
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

//����
void SpeechManage::speechContest()
{
	cout << "----------��" << this->m_round << "�ֱ�����ʽ��ʼ----------" << endl;
	
	//׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0;	//��¼��Ա������6��һ��

	vector<int>v_Src;	//����ѡ������
	if (this->m_round == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;	//600~1000�������
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());	//���򣬽���
		d.pop_front();	//ȥ����߷�
		d.pop_back();	//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);	//�ܷ�
		double avg = sum / (double)d.size();	//ƽ����

		//��ӡƽ����
		//cout << "��ţ�" << *it  << "������" << this->m_speaker[*it].m_name << "��ȡƽ���֣�" << avg << endl;

		//��ƽ���ַ���map����
		this->m_speaker[*it].m_score[this->m_round - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));	//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end();it++)
			{
				cout << "��ţ�" << it->second
					<< " ������" << this->m_speaker[it->second].m_name
					<< " �ɼ���" << this->m_speaker[it->second].m_score[this->m_round - 1] << endl;
			}

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_round == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vwinner.push_back((*it).second);
				}
			}

			groupScore.clear();	//С���������
			cout << endl;
		}
	}

	cout << "------------��" << this->m_round << "�ֱ�����ϣ�------------" << endl;
	system("pause");
	//cout << endl;
}

//��ʾ�÷�
void SpeechManage::showScore()
{
	cout << "--------------��" << this->m_round << "�ֽ���ѡ����Ϣ���£�--------------" << endl;

	vector<int>v;
	if (this->m_round == 1)
	{
		v = v2;
	}
	else
	{
		v = vwinner;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it
			<< " ������" << this->m_speaker[*it].m_name
			<< " �÷֣�" << this->m_speaker[*it].m_score[this->m_round - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();
}