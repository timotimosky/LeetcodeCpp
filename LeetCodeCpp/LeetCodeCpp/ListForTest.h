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

		int m = 0;  //��ָ��
		int n = 1;  //��ָ��
		int k = 1;//��Ҫ���滻������

		for (int i =0; i< nums.size(); i++)
		{
			if (nums[m]== nums[n])
			{
				k = n;
				n++;
			}
			else
			{
				nums[k] = nums[n];
				m = n;
				n++;
			}
		}

		return nums.size();
	}
};
