#pragma once
#include <vector>
//#include <string>
#include<iostream>
#include <map>
#include <string>
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

		map<char, int> testMap = map<char, int>();

		char testChar;

		for (int i = 0;i < a.length();i++)
		{
			testChar = a[i];

			if (testMap.count(testChar) != 0)
			{
				testMap[testChar] = testMap[testChar] + 1;
				//cout << "A增加-----" << testChar <<"---"<< testMap[testChar] << endl;
			}
			else
			{
				pair<char, int> value(testChar, 1);
				testMap.insert(value);//插入新元素
				//cout << "A插入-----" << testChar << "---" << testMap[testChar] << endl;
			}	
			testChar = b[i];
			if (testMap.count(testChar) != 0)
			{
				testMap[testChar] = testMap[testChar] - 1;
				//cout << "B减少-----" << testCharB << "---" << testMap[testCharB] << endl;
			}
			else
			{
				pair<char, int> value(testChar, -1);
				testMap.insert(value);//插入新元素
				//cout << "B插入-----" << testCharB << "---" << testMap[testCharB] << endl;
			}
		}

		for (int i = 0; i < testMap.size(); i++)
		{
			testChar = testMap[i];
			if (testChar != 0)
			{
				return false;
			}
		}

		return true;
	}

	/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

		你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

		示例 :

	给定 nums = [2, 7, 11, 15], target = 9

		因为 nums[0] + nums[1] = 2 + 7 = 9
		所以返回[0, 1]*/

//1.贪心算法

	//[230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384, 778, 887, 755, 740, 337, 
	//86, 92, 325, 422, 815, 650, 920, 125, 277, 336, 221, 847, 168, 23, 677, 61, 400, 136,
	//874, 363, 394, 199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422, 927, 783, 
	//930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933, 737, 531, 180, 414, 751, 28, 546, 60,
	//371, 493, 370, 527, 387, 43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538, 427, 
	//583, 368, 375, 173, 809, 896, 370, 789]
	//542
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
	
			std::map<int, int>  mMap = map<int, int>();
			//字典
			int first;
			int remain;
			for (int i = 0; i < nums.size(); i++)
			{
				first = nums[i];

				if (mMap.count(first)!=0)
				{
					return vector<int>{ mMap[first], i};
				}

				remain = target - first;

				if (mMap.count(remain) == 0)
				{
					mMap[remain] = i;
				}
				else
				{
					mMap.insert(pair<int, int>{remain, i});
				}
			}


			////双循环
			//int first;
			//for (int i=0; i<nums.size();i++)
			//{
			//	first =nums[i];
			//	for (int j = i+1; j < nums.size(); j++)
			//	{
			//		if (first + nums[j] == target)
			//			return vector<int>{i,j };
			//	}
			//}

			return vector<int>{ 0, 0 };

		}


};

