#include "SpeechManage.h"

//构造函数
SpeechManage::SpeechManage()
{
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->creatSpeaker();
}

//析构函数
SpeechManage::~SpeechManage()
{

}

//菜单功能
void SpeechManage::show_menu()
{
	cout << "*************************************************" << endl;
	cout << "**************** 欢迎参加演讲比赛 ***************" << endl;
	cout << "***************** 1.开始演讲比赛 ****************" << endl;
	cout << "***************** 2.查看往届成绩 ****************" << endl;
	cout << "***************** 3.清空比赛记录 ****************" << endl;
	cout << "***************** 0.退出比赛程序 ****************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManage::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManage::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vwinner.clear();
	this->m_speaker.clear();

	//初始化比赛轮数
	this->m_round = 1;
}

//创建12名选手
void SpeechManage::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		//创建选手编号，并且放入容器v1
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手，放入容器map中
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛。比赛整个流程控制函数
void SpeechManage::startSpeech()
{
	//第一轮开始比赛

	//1、抽签
	speechDraw();

	//2、比赛
	speechContest();

	//3、显示晋级结果
	showScore();

	//第二轮开始比赛
	m_round++;

	//1、抽签
	speechDraw();

	//2、比赛
	speechContest();

	//3、显示最终结果
	showScore();

	//4、保存分数到文件中
}

//抽签
void SpeechManage::speechDraw()
{
	cout << "第" << this->m_round << "轮比赛选手正在抽签" << endl;
	cout <<"------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_round == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());   //洗牌算法
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
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

//比赛
void SpeechManage::speechContest()
{
	cout << "----------第" << this->m_round << "轮比赛正式开始----------" << endl;
	
	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0;	//记录人员个数，6人一组

	vector<int>v_Src;	//比赛选手容器
	if (this->m_round == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;	//600~1000的随机数
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());	//排序，降序
		d.pop_front();	//去除最高分
		d.pop_back();	//去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);	//总分
		double avg = sum / (double)d.size();	//平均分

		//打印平均分
		//cout << "编号：" << *it  << "姓名：" << this->m_speaker[*it].m_name << "获取平均分：" << avg << endl;

		//将平均分放入map容器
		this->m_speaker[*it].m_score[this->m_round - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));	//key是得分，value是具体选手编号
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end();it++)
			{
				cout << "编号：" << it->second
					<< " 姓名：" << this->m_speaker[it->second].m_name
					<< " 成绩：" << this->m_speaker[it->second].m_score[this->m_round - 1] << endl;
			}

			//取走前三名
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

			groupScore.clear();	//小组容器清空
			cout << endl;
		}
	}

	cout << "------------第" << this->m_round << "轮比赛完毕！------------" << endl;
	system("pause");
	//cout << endl;
}

//显示得分
void SpeechManage::showScore()
{
	cout << "--------------第" << this->m_round << "轮晋级选手信息如下：--------------" << endl;

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
		cout << "选手编号：" << *it
			<< " 姓名：" << this->m_speaker[*it].m_name
			<< " 得分：" << this->m_speaker[*it].m_score[this->m_round - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();
}