#pragma once
#include <vector>
#include<iostream>
using namespace std;

class DP
{
public:
		//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
		//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
		//注意：给定 n 是一个正整数。
		/*输入： 3
		输出： 3
		解释： 有三种方法可以爬到楼顶。
		1.  1 阶 + 1 阶 + 1 阶
		2.  1 阶 + 2 阶
		3.  2 阶 + 1 阶*/


	//动态规划：最优子结构 :分解为多个子问题的组合
		/*第 i 阶可以由以下两种方法得到：
		在第(i−1) 阶后向上爬一阶。
		在第(i−2) 阶后向上爬 2 阶。
		所以到达第 i 阶的方法总数就是到第(i−1) 阶和第(i−2) 阶的方法数之和。*/

	//int Remain;
	int climbStairs(int n){
		if (n == 1)
			return 1;

		vector<int> dp = vector<int>(n+1);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}

//	给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//	如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//	注意你不能在买入股票前卖出股票。
//	示例 1:
//
//输入: [7, 1, 5, 3, 6, 4]
//	输出 : 5
//	解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6 - 1 = 5 。
//	注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格。
//	示例 2 :
//
//	输入 : [7, 6, 4, 3, 1]
//	输出 : 0
//	解释 : 在这种情况下, 没有交易完成, 所以最大利润为 0。

	//动态规划，从结果往前看 最大利润= DP[j] - DP[i];
	//j >i
	//

	//1.暴力法
	int maxProfit(vector<int>& prices) {

		int num = prices.size();
		if (num < 2)
			return 0;

		int nowMax = 0;
		int nowI;

		for (int i = 0; i < num-1; i++)
		{
			nowI = prices[i];
			for (int j = i+1; j < num; j++)
			{
				int p = prices[j] - nowI;
				if (p > nowMax)
					nowMax = p;
				//cout << "nowMax==" << nowMax << "---" << prices[i] << "-" << prices[j]<<endl;
			}
		}
		return nowMax;
	}

	//2.动态规划：动态记录峰底和峰值
	int maxProfit2(vector<int>& prices) {

		int num = prices.size();
		if (num < 2)
			return 0;

		int nowMax = 0;
		int nowI;
		int min = INT64_MAX;
		for (int i = 0; i < num - 1; i++)
		{
			nowI = prices[i];
			//寻找峰底
			if (min > nowI)
			{
				min = nowI;
			}

		}
		return nowMax;
	}
};

