#pragma once
# include <string>
//对需要用到的数据进行定义

using namespace std;
extern int output_search[20][7];

struct Student
{
	string Name = "empty";
	string Sex = "empty";
	string Age = "empty";
	string PhoneNumber = "empty";
	string Major = "empty";
	string Academy = "empty";
	string univercity = "empty";
	int key = 0;

	bool is_used = false;
	bool is_changed = false;
};
//初始化函数
void init(Student man) {
	man.key = 0; //列表顺序
	man.Name = "empty";
	man.Sex = "empty";
	man.Age = "empty";
	man.PhoneNumber = "empty";
	man.Major = "empty";
	man.Academy = "empty";
	man.univercity = "empty";
	man.is_used = false;//是否被使用
	man.is_changed = false;//是否被修改
}
void init(int math[20]) { //output 数组初始化
	for (int i = 0; i < 20; i++)
	{
		math[i] = 0;
	}
}
void search(Student man[20], string target, string select, int times) {
	; //times为叠加筛选的数量
	if (select == "Name")
	{ //姓名查询
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].Name == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "Sex") //性别查询
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].Sex == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "Age")
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].Age == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "PhoneNumber")
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].PhoneNumber == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "Major")
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].Major == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "Academy")
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].Academy == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
	else if (select == "Univercity")
	{
		for (int i = 0; i < 20; i++) //遍历找目标值
		{
			if (man[i].univercity == target) //找到了
			{
				output_search[i][times] = 1; //储存标记
			}
		}
	}
}