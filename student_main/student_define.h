#pragma once
# include <string>
//����Ҫ�õ������ݽ��ж���

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
//��ʼ������
void init(Student man) {
	man.key = 0; //�б�˳��
	man.Name = "empty";
	man.Sex = "empty";
	man.Age = "empty";
	man.PhoneNumber = "empty";
	man.Major = "empty";
	man.Academy = "empty";
	man.univercity = "empty";
	man.is_used = false;//�Ƿ�ʹ��
	man.is_changed = false;//�Ƿ��޸�
}