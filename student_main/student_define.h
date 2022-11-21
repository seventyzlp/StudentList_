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
	bool is_used = false;
	bool is_changed = false;
};