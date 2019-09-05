#pragma once
#include<iostream>
#include<string>
using namespace std;

//赋值运算符的重载
class String_OperaterReload
{
private:
	char* name;
	int id;
public:
	String_OperaterReload() {}
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
	String_OperaterReload& operator =(const String_OperaterReload& str)//赋值运算符
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