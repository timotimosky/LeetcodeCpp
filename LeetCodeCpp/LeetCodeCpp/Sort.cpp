
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


//��������ֱ�Ӳ�������   ʱ�临�Ӷȣ�O��n^2��
void Sort::InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int oldValue = a[i];//����Ϊ�ڱ������洢������Ԫ��  
			//����һ��
			 a[i] = a[i - 1];
			 int  moveIndex = i-1;

			while (moveIndex >= 1)
			{
				moveIndex--;

				if (oldValue < a[moveIndex])
				{
					//����һ��
					a[moveIndex+1] = a[moveIndex];
				}
				else
				{
					moveIndex++; //������ɣ��ӻ�ȥ
					break;
				}
			}
			a[moveIndex] = oldValue;//���뵽��ȷλ��  
		}
		print(a, n, i);           //��ӡÿ������Ľ�� 
	}
}

//��������ϣ������Shell`s Sort��
void  Sort::ShellSort()
{
	
}

//�������򡪿�������Quick Sort��
void  Sort::QuickSort(int a[], int n)
{
	int i = 0;
	int j = n - 1;
	int key = a[0];



}

//��������ð������Bubble Sort��
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
		//��ӡÿ������Ľ�� 
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
	int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/

	while (first < last)
	{
		while (first < last && a[last] >= key)
		{
			--last;
		}

		a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/

		while (first < last && a[first] <= key)
		{
			++first;
		}

		a[last] = a[first];
		/*���ȵ�һ������Ƶ��߶�*/
	}
	a[first] = key;/*�����¼��λ*/
	Qsort(a, low, first - 1);
	Qsort(a, first + 1, high);
}

int TestQuickSort()
{
	int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };
	
	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*����ԭ�ĵ���������Ҫ��1�����ڴ�Խ��*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << "";
	}

	return 0;
}