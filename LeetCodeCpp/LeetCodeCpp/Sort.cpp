
#include "Sort.h"
//#include <fstream>
#include <iostream>
using namespace std;

Sort::Sort()
{

}

 Sort::~Sort()
{

}


void Sort::Test() {
	int a[8] = { 7,1,3,4,8,2,9,6 };
	BubbleSort(a, 8);
	//InsertSort(a, 8);
	print(a, 8, 8);
}

void Sort::print(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j<8; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}


//插入排序—直接插入排序   时间复杂度：O（n^2）
void Sort::InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int oldValue = a[i];//复制为哨兵，即存储待排序元素  
			//后移一步
			 a[i] = a[i - 1];
			 int  moveIndex = i-1;

			while (moveIndex >= 1)
			{
				moveIndex--;

				if (oldValue < a[moveIndex])
				{
					//后移一步
					a[moveIndex+1] = a[moveIndex];
				}
				else
				{
					moveIndex++; //这个不成，加回去
					break;
				}
			}
			a[moveIndex] = oldValue;//插入到正确位置  
		}
		print(a, n, i);           //打印每趟排序的结果 
	}
}

//插入排序—希尔排序（Shell`s Sort）
void  Sort::ShellSort()
{
	
}

//交换排序—快速排序（Quick Sort）
void  Sort::QuickSort(int a[], int n)
{
	int i = 0;
	int j = n - 1;
	int key = a[0];



}

//交换排序—冒泡排序（Bubble Sort）
void Sort::BubbleSort(int a[], int n) {
	for (int i = 0; i< n - 1; ++i) {
		//cout << i << "==--------------i:";
		for (int j = 0; j < n - i - 1; ++j) {
			cout<<"j="<< j << "-----";
			if (a[j] > a[j + 1])
			{
				int tmp = a[j]; a[j] = a[j + 1];  a[j + 1] = tmp;
			}
			print(a, n, i);
		}         
		//打印每趟排序的结果 
	}
}



void Qsort(int a[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = a[first];/*用字表的第一个记录作为枢轴*/

	while (first < last)
	{
		while (first < last && a[last] >= key)
		{
			--last;
		}

		a[first] = a[last];/*将比第一个小的移到低端*/

		while (first < last && a[first] <= key)
		{
			++first;
		}

		a[last] = a[first];
		/*将比第一个大的移到高端*/
	}
	a[first] = key;/*枢轴记录到位*/
	Qsort(a, low, first - 1);
	Qsort(a, first + 1, high);
}

int TestQuickSort()
{
	int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };
	
	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << "";
	}

	return 0;
}