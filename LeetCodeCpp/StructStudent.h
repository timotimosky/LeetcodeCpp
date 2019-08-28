#pragma once

//声明结构体类型的位置一般在文件的开头，在所有函数（包括main函数）之前，
//以便本文件中所有的函数都能利用它来定义变量。当然也可以在函数中声明结构体类型。
//在C语言中，结构体的成员只能是数据（如上面例子中所表示的那样）。
//C++对此加以扩充，结构体的成员既可以包括数据（即数据成员），又可以包括函数（即函数成员），以适应面向对象的程序设计。


//1 单纯声明一个结构体类型Student ：声明不分配内存
struct Student
{
	//每一个成员也称为结构体中的一个域(field)。成员表列又称为域表。
	int num;  //包括一个整型变量num
	char name[20];  //包括一个字符数组name，可以容纳20个字符
	char sex;  //包括一个字符变量sex
	int age;   //包括一个整型变量age
	float score;   //包括一个单精度型变量
	char addr[30];  //包括一个字符数组addr，可以容纳30个字符
};  //最后有一个分号


//2 在声明类型的同时定义变量 ：适合当结构体只用于本文件
struct NStudent  //声明结构体类型Student
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
}student5, student6;  //定义两个结构体类型Student的变量student1，student2

//3) 直接定义结构体类型变量：
struct 
{
	int num;
	char name[20];
}student7, student8;  

//4. 在声明类型的同时定义变量 并且初始化变量
struct IStudent
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
}student9 = { 10001, "Zhang Xin", 'M', 19, 90.5, "Shanghai" };

class StructStudent
{

	//定义了结构体变量后，系统会为之分配内存单元。例如student1和student2在内存中各占63个字节(4+20+1+4+4+30=63)。
	//C
	struct Student  Student3;
	//C++
	Student Student1，Student2;

	//初始化
	void Init()
	{
		Student student2 = { 10002, "Wang Li", 20, 98,33, "Beijing" };
	}
};

