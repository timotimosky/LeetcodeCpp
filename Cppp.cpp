// �㷨CPP.cpp : �������̨Ӧ�ó������ڵ㡣
// ʱ�����ƣ�1�� �ռ����ƣ�32768K

#include "stdafx.h"
//#include "ListNodeClass.h"
#include<iostream>
#include<ctime>
#include<vector>
#include "Sort.h"
#include "ListForTest.h"
using namespace std;

//��C++�м������е�ʱ���ǵ���clock������ʹ��clock������ó���ʼ�ͽ��������ʱ�䣬����͵õ�����������ʱ�䡣
//clock()��C/C++�еļ�ʱ��������������ص�����������clock_t����MSDN�У���ö�clock�����������£�
//clock_t clock(void);


void TestMain();

//���Ӽ�ʱ���ܡ����ڴ�ʹ�ù���
int main()
{

	clock_t start, finish;
	start = clock();
	cout << "HW .... " << endl;

	TestMain();

	finish = clock(); //���Ǻ��룬��1000�õ���
	cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;

	//���Զ��˳��������̨
	system("pause");
	return 0;
}


void TestMain()
{
	vector<int> nums =  vector<int>{ 0,0,1,1,1,2,2,3,3,4 };
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











