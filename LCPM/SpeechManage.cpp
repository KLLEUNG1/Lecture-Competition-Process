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
	this->speaker.clear();

	//初始化比赛轮数
	this->round = 1;
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
		sp.s_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		//创建选手编号，并且放入容器v1
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手，放入容器map中
		this->speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛。比赛整个流程控制函数
void SpeechManage::startSpeech()
{
	//第一轮开始比赛

	//1、抽签
	this->speechDraw();

	//2、比赛

	//3、显示晋级结果

	//第二轮开始比赛

	//1、抽签

	//2、比赛

	//3、显示最终结果

	//4、保存分数到文件中
}

//抽签
void SpeechManage::speechDraw()
{
	cout << "第" << this->round << "轮比赛选手正在抽签" << endl;
	cout <<"------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->round == 1)
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