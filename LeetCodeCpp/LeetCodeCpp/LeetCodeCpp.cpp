// 算法CPP.cpp : 定义控制台应用程序的入口点。
// 时间限制：1秒 空间限制：32768K


//#include "ListNodeClass.h"
#include<iostream>
#include<ctime>
#include<vector>
#include "Sort.h"
#include "ListForTest.h"
using namespace std;

//在C++中计算运行的时间是调用clock函数，使用clock函数获得程序开始和结束所需的时间，相减就得到程序所花的时间。
//clock()是C/C++中的计时函数，而与其相关的数据类型是clock_t。在MSDN中，查得对clock函数定义如下：
//clock_t clock(void);


void TestMain();

//增加计时功能、和内存使用功能
int main()
{

	clock_t start, finish;
	start = clock();
	cout << "HW .... " << endl;

	TestMain();

	finish = clock(); //这是毫秒，除1000得到秒
	cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;

	//不自动退出命令控制台
	system("pause");
	return 0;
}


void TestMain()
{
	vector<int> nums = vector<int>{ 0,0,1,1,1,2,2,3,3,4 };
	ListForTest* mListForTest = new ListForTest;
	int result = mListForTest->removeDuplicates(nums);
	cout << result << endl;

	//Sort* mSort = new  Sort;
	//mSort->Test();


	//ListNodeClass* mListNodeClass;
	//mListNodeClass = new ListNodeClass;
	//delete mListNodeClass;
	//mListNodeClass = NULL;

}











