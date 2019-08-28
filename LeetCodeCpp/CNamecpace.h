#pragma once



//匿名命名空间

namespace{
	char c;
	int i;
	double d;
}
//编译器在内部会为这个命名空间生成一个唯一的名字，而且还会为这个匿名的命名空间生成一条using指令。所以上面的代码在效果上等同于：
//namespace __UNIQUE_NAME_ {
//	char c;
//	int i;
//	double d;
//}
//using namespace __UNIQUE_NAME_;

//在匿名命名空间中声明的名称也将被编译器转换，与编译器为这个匿名命名空间生成的唯一内部名称(即这里的__UNIQUE_NAME_)绑定在一起。
//1.这些名称具有internal链接属性，这和声明为static的全局名称的链接属性是相同的，即名称的作用域被限制在当前文件中，
//无法通过在另外的文件中使用extern声明来进行链接。
//如果不提倡使用全局static声明一个名称拥有internal链接属性，则匿名命名空间可以作为一种更好的达到相同效果的方法。
//注意 : 命名空间都是具有external 连接属性的, 只是匿名的命名空间产生的__UNIQUE_NAME__在别的文件中无法得到, 这个唯一的名字是不可见的.
//
//C++ 新的标准中提倡使用匿名命名空间, 而不推荐使用static, 因为:
//1.static用在不同的地方, 涵义不同, 容易造成混淆
//2.static不能修饰class







//命名空间是ANSI C++引入的可以由用户命名的作用域(内存区域)。
//程序设计者可以根据需要指定一些有名字的空间域，
//把一些全局实体分别放在各个命名空间中，从而与其他全局实体分隔开来，用来处理程序中常见的同名冲突。

//在C语言中定义了3个层次的作用域，即文件(编译单元)、函数和复合语句。
//C++又引入了类作用域，类是出现在文件内的,指定标识符的各种可见范围。
//在声明一个命名空间时，花括号内不仅可以包括变量，而且还可以包括以下类型：
//·变量(可以带有初始化)；
//·常量；
//·数(可以是定义或声明)；
//·结构体；
//·类；
//·模板；
//·命名空间(在一个命名空间中又定义一个命名空间，即嵌套的命名空间)。

//例如:

namespace nsl
{
	const int RATE = 0.08; //常量
	double pay;      //变量
	double tax(int a)       //函数
	{
		return a * RATE;
	}
	namespace ns2       //嵌套的命名空间
	{
		int age;
	}
}

//使用命名空间别名

namespace TV = nsl; //别名TV与原名Television等价


//如果想输出命名空间nsl中成员的数据，可以采用下面的方法：

#include <iostream>
using namespace std;  //命名空间的第1种使用方法
using nsl::ns2::age;  //命名空间的第2种使用方法 单独声明一个命名空间成员 在这以后，就可以直接访问age了

//但是要注意：在同一作用域中用using声明的不同命名空间的成员中不能有同名的成员。例如：
//using nsl::Student； //声明其后出现的Student是命名空间nsl中的Student
//using ns2::Student； //声明其后出现的Student是命名空间ns2小的Student

class CNamecpace
{
	void init()
	{
		cout << nsl::RATE << endl;
		cout << nsl::pay << endl;
		cout << nsl::tax(1) << endl;

		//命名空间的第3种使用方法
		cout << nsl::ns2::age << endl; //需要指定外层的和内层的命名中间名


	}
};

