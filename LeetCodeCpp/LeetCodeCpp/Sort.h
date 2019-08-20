#pragma once
#include <vector>
#include <string>
#include<iostream>
#include <map>
using namespace std;
//直接插入排序
class Sort
{
public:
	Sort();
	~Sort();

	void print(int a[], int n, int i);

	void InsertSort(int a[], int n);

	void ShellSort();

	void QuickSort(int a[], int n);


	void BubbleSort(int a[], int n);

	void Test();




	//拷贝构造函数的参数为什么必须是const引用？

	//1  在调用拷贝构造函数的时候  CExample B(A);
	//上面 B(A) 中实参 A  赋给形参 C（CExample(const CExample C)） 的时候，本身就要触发拷贝构造函数 C(A) ，这个 C(A)  中的 A 又要赋给形参 C'.......
	//这是不是要无限次的进行拷贝？
	//所以，如果使用引用就可以避免这样的无限循环。

	//2 那为什么要用const引用？
	//const 更多是给程序员的一个限制， 告诉程序员这个变量是只读的。因此为了安全， 一般建议所有的只读变量加const限制以防止程序员犯错。
	//因为复制构造函数是用引用方式传递复制对象，引用方式传递的是地址，因此在构造函数内对该引用的修改会影响源对象。
	//而你在用对象a1构造a2时，自然不希望复制构造函数会改变a1的内容，因此要防止复制构造函数内部修改该引用，所以用const声明。
	Sort(const Sort& input)
	{
		
	}


	//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
	/*示例 1:
	输入: s = "anagram", t = "nagaram"
	输出 : true

	示例 2 :
	输入 : s = "rat", t = "car"
	输出 : false

	说明 :
	你可以假设字符串只包含小写字母。
	进阶 :
	如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？*/


	bool TestAllotopia(string a,string b)
	{
		if (a.length() != b.length())
			return false;

		//记录b被淘汰的索引
		vector<int> cost = vector<int>(a.length());
		
		map<char, int> testMap = map<char, int>();

		for (int i = 0;i < a.length();i++)
		{
			iterator miterator = testMap.find(a[i]);
			//if (iterator miterator = testMap.find(a[i]))
			//{

			//}

		}



		for (int i = 0;i < a.length();i++)
		{
			if (a.compare())
			{

			}

			bool ifCost = false;

			for (int j = 0;j < b.length();j++)
			{
				if (cost[j] == 1)
					continue;
				if (a[i] == b[j])
				{
					ifCost = true;
					cost[j]=1;
					break;
				}
			}
			if (!ifCost)
				return false;
		}
		return true;
	}

};

