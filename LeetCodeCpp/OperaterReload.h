#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ֵ�����������
class String_OperaterReload
{
private:
	char* name;
	int id;
public:
	String_OperaterReload() {}

	//����
		//һ��أ���ֵ��������غ����Ĳ����Ǻ����������const���͵����ã���const����Ϊ��
		//1���ǲ�ϣ������������ж��������и�ֵ�ġ�ԭ�桱���κ��޸ġ�
		//2����const������const�ĺͷ�const��ʵ�Σ��������ܽ��ܣ�������ӣ���ֻ�ܽ��ܷ�const��ʵ�Ρ�
		//����������Ϊ��
		//�������Ա����ں�������ʱ��ʵ�ε�һ�ο����������Ч�ʡ�
		//����Ĺ涨������ǿ�Ƶģ����Բ���const��Ҳ����û�����ã������������Բ��Ǻ������ڵĶ���

	//����ֵ
	//һ��أ�����ֵ�Ǳ���ֵ�ߵ����ã���* this����������1����ԭ����
	//	�������ں�������ʱ����һ�ο����������Ч�ʡ�
	//	�ڸ���Ҫ�ģ���������ʵ��������ֵ��������a = b = c������������Ƿ������ö��Ƿ���ֵ���ͣ���ô��ִ��a = bʱ��
	//���ø�ֵ��������غ������ں�������ʱ�����ڷ��ص���ֵ���ͣ�����Ҫ��return��ߵġ�����������һ�ο�����
	//�õ�һ��δ�����ĸ�������Щ�����ϳ�֮Ϊ���������󡱣���Ȼ������������أ��������������ֵ��
	//���ԣ�ִ��a = b�󣬵õ�����һ����ֵ����ִ�� = c�ͻ����
	//	ע�⣺
	//	��Ҳ����ǿ�Ƶģ����ǿ��Խ���������ֵ����Ϊvoid��Ȼ��ʲôҲ�����أ�ֻ���������Ͳ��ܹ�������ֵ�ˡ�


	String_OperaterReload(int _id, const char* _name)   //constructor
	{
		cout << "constructor" << endl;
		id = _id;
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	String_OperaterReload(const String_OperaterReload& str)
	{
		cout << "copy constructor" << endl;
		id = str.id;
		if (name != NULL)
			delete name;
		name = new char[strlen(str.name) + 1];
		strcpy_s(name, strlen(str.name) + 1, str.name);
	}
	String_OperaterReload& operator =(const String_OperaterReload& str)//��ֵ�����
	{
		cout << "operator =" << endl;
		if (this != &str)
		{
			if (name != NULL)
				delete name;
			this->id = str.id;
			int len = strlen(str.name);
			name = new char[len + 1];
			strcpy_s(name, strlen(str.name) + 1, str.name);
		}
		return *this;
	}
	~String_OperaterReload()
	{
		delete name;
	}
};