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

void TestSort()
{
	Sort* mSort = new Sort;
	bool ifDD = mSort->TestAllotopia("1234", "2134");
	cout << "1234 2134是否相等-----"<<ifDD << endl;

	ifDD = mSort->TestAllotopia("anagram","nagaram");
	cout << "anagram,nagaram是否相等-----" << ifDD << endl;

}

void TestList()
{
	ListForTest* mListForTest = new ListForTest;

	vector<int> nums = vector<int>{ 0,0,1,1,1,2,2,3,3,4 };
	int result = mListForTest->removeDuplicates(nums);
	//cout << result << endl;

	nums = vector<int>{ 3,2,2,3 };
	result = mListForTest->removeElement3(nums,3);
	//cout << result << endl;

	//Sort* mSort = new  Sort;
	//mSort->Test();


	//ListNodeClass* mListNodeClass;
	//mListNodeClass = new ListNodeClass;
	//delete mListNodeClass;
	//mListNodeClass = NULL;

}


void TesttwoSum()
{
	Sort* mSort = new Sort;
	vector<int>* input = new vector<int>{ 2 , 7, 11, 15 };
	vector<int> ifDD = mSort->twoSum(*input, 9);
	/*cout << "1234 2134是否相等-----" << ifDD << endl;

	ifDD = mSort->TestAllotopia("anagram", "nagaram");
	cout << "anagram,nagaram是否相等-----" << ifDD << endl;*/

}

//增加计时功能、和内存使用功能
int main()
{

	clock_t start, finish;
	start = clock();
	cout << "time cost .... " << endl;

	//TestMain();
	TestSort();

	finish = clock(); //这是毫秒，除1000得到秒
	cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;

	//不自动退出命令控制台
	system("pause");
	return 0;
}









