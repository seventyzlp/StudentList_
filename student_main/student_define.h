#pragma once
# include <string>
//����Ҫ�õ������ݽ��ж���

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
void init(int math[20]) { //output �����ʼ��
	for (int i = 0; i < 20; i++)
	{
		math[i] = 0;
	}
}
void search(Student man[20], string target, string select, int times) {
	; //timesΪ����ɸѡ������
	if (select == "Name")
	{ //������ѯ
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].Name == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "Sex") //�Ա��ѯ
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].Sex == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "Age")
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].Age == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "PhoneNumber")
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].PhoneNumber == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "Major")
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].Major == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "Academy")
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].Academy == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
	else if (select == "Univercity")
	{
		for (int i = 0; i < 20; i++) //������Ŀ��ֵ
		{
			if (man[i].univercity == target) //�ҵ���
			{
				output_search[i][times] = 1; //������
			}
		}
	}
}