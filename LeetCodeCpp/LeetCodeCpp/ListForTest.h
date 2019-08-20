#pragma once
#include <vector>
#include<iostream>
using namespace std;

class ListForTest {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() == 0)
			return 0;

		auto iter = nums.begin();
		int nowValue = *iter;
		iter++;
		while (iter != nums.end())
		{
			if (nowValue == *iter)
			{
				//只有删除元素前面的iterator还保持有效, 之后的遍历行为不可预知.
				//对于vector, erase会返回下一个iterator, 因此我们可以使用如下的方法:
				cout << nowValue  << endl;
				iter = nums.erase(iter);
			}
			else
			{
				nowValue = *iter;
				++iter;
			}
		}
		return nums.size();
	}

	//改变一个集合的值: 1.删除 2.覆盖 3.标记它为废弃，下一次用到可以覆盖

	//双指针法 :不采用删除元素，采用覆盖元素
	int removeDuplicates2(vector<int>& nums) {

		if (nums.size() == 0)
			return 0;

		int slowPtr = 0;  //慢指针 
		//int fastPtr = 1;  //快指针
		//int k = 1;//需要被替换的索引

		//快排的思想来做 慢指针+快指针
		for (int fastPtr =1; fastPtr < nums.size(); fastPtr++)//第一个元素自动默认保留 ，fastPtr从1计算
		{
			if (nums[slowPtr] != nums[fastPtr])
			{
				slowPtr++;
				nums[slowPtr] = nums[fastPtr];
			}
		}

		int finalLenth = slowPtr + 1;
		//其实这个解答有漏洞，不重新整理长度，后面的长度还是有重复元素，但 可以默认slowPtr+1后的元素是废弃
		//nums.resize(slowPtr+1);
		for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++)
		{
			cout << nums[fastPtr] << endl;
		}
		cout << "count---"<< finalLenth << endl;

		return finalLenth;
	}


	int removeElement3(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		int slowPtr = 0;  //慢指针
		for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++)
		{
 			if (val != nums[fastPtr])
			{
				nums[slowPtr] = nums[fastPtr];
				slowPtr++;
			}
		}
		return slowPtr ;
	}
};
