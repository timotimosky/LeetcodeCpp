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

	//参数
		//一般地，赋值运算符重载函数的参数是函数所在类的const类型的引用，加const是因为：
		//1我们不希望在这个函数中对用来进行赋值的“原版”做任何修改。
		//2加上const，对于const的和非const的实参，函数就能接受；如果不加，就只能接受非const的实参。
		//用引用是因为：
		//这样可以避免在函数调用时对实参的一次拷贝，提高了效率。
		//上面的规定都不是强制的，可以不加const，也可以没有引用，甚至参数可以不是函数所在的对象。

	//返回值
	//一般地，返回值是被赋值者的引用，即* this（如上面例1），原因是
	//	①这样在函数返回时避免一次拷贝，提高了效率。
	//	②更重要的，这样可以实现连续赋值，即类似a = b = c这样。如果不是返回引用而是返回值类型，那么，执行a = b时，
	//调用赋值运算符重载函数，在函数返回时，由于返回的是值类型，所以要对return后边的“东西”进行一次拷贝，
	//得到一个未命名的副本（有些资料上称之为“匿名对象”），然后将这个副本返回，而这个副本是右值，
	//所以，执行a = b后，得到的是一个右值，再执行 = c就会出错。
	//	注意：
	//	这也不是强制的，我们可以将函数返回值声明为void，然后什么也不返回，只不过这样就不能够连续赋值了。


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