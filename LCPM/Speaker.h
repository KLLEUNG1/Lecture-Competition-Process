#pragma once  //防止头文件重包含
#include <iostream>
using namespace std;

//设计选手类
class Speaker
{
public:
	string m_name;   //选手姓名
	double m_score[2];   //选手分数，一个选手最多有两轮得分
};