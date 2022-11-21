#pragma once
# include <string>
//对需要用到的数据进行定义

using namespace std;
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