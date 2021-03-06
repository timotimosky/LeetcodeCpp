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


	//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	//	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
	//	示例 1 :
	//给定数组 nums = [1, 1, 2],
	//	函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
	//	你不需要考虑数组中超出新长度后面的元素。
	//	示例 2 :
	//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
	//	函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
	//	你不需要考虑数组中超出新长度后面的元素。



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
			if (nums[slowPtr] != nums[fastPtr]) //找到不重复的元素后，慢指针才移动一次，这样，保证慢指针到最后，没有重复元素
			{
				slowPtr++;
				nums[slowPtr] = nums[fastPtr];
			}
		}

		int finalLenth = slowPtr + 1;
		//这个解答不重新整理长度，后面的长度还是有重复元素，但 可以默认slowPtr+1后的元素是废弃
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
