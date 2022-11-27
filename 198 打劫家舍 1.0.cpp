/*

Leetcode 198 打家劫舍
dp[i] 偷到第i个房子的总最高收入  上一个是i-2或i-1，要么偷了要么没偷
dp[i]=max{dp[i-1]，dp[i-2]+a[i]} if(i>=2)

*/

#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n);
	for (int i = 0; i < n; ++i)
		if (i >= 2)dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		else if (i == 1)dp[i] = max(dp[i - 1], nums[i]);
		else dp[i] = nums[i];
	return dp[n-1];
}

int main()
{
	vector<int>houses = {2,7,9,3,1};
	cout << rob(houses);
}