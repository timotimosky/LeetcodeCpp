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
				//ֻ��ɾ��Ԫ��ǰ���iterator��������Ч, ֮��ı�����Ϊ����Ԥ֪.
				//����vector, erase�᷵����һ��iterator, ������ǿ���ʹ�����µķ���:
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

	//�ı�һ�����ϵ�ֵ: 1.ɾ�� 2.���� 3.�����Ϊ��������һ���õ����Ը���

	//˫ָ�뷨 :������ɾ��Ԫ�أ����ø���Ԫ��
	int removeDuplicates2(vector<int>& nums) {

		if (nums.size() == 0)
			return 0;

		int slowPtr = 0;  //��ָ�� 
		//int fastPtr = 1;  //��ָ��
		//int k = 1;//��Ҫ���滻������

		//���ŵ�˼������ ��ָ��+��ָ��
		for (int fastPtr =1; fastPtr < nums.size(); fastPtr++)//��һ��Ԫ���Զ�Ĭ�ϱ��� ��fastPtr��1����
		{
			if (nums[slowPtr] != nums[fastPtr])
			{
				slowPtr++;
				nums[slowPtr] = nums[fastPtr];
			}
		}

		int finalLenth = slowPtr + 1;
		//��ʵ��������©���������������ȣ�����ĳ��Ȼ������ظ�Ԫ�أ��� ����Ĭ��slowPtr+1���Ԫ���Ƿ���
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
		int slowPtr = 0;  //��ָ��
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
