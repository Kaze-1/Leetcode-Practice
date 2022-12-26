/*
属于MaxAlignedSet的问题，与CMU的第三道题题型类似
*/

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

// [失败]自创解法：hashmap(int->hashset)的解法，贪心算法
// 数学上就不对！一个元素可以同时隶属于多个集合，根本没法建立int -> set的映射！
vector<int> largestDivisibleSubset1(vector<int>& nums) {
	unordered_map<int, unordered_set<int>> allSet;
	allSet[nums[0]] = { nums[0] };
	int res=0,i,n=nums.size(),j;
	unordered_set<int>finalSet;
	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < i; ++j)
			if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
				&& allSet[nums[j]].find(nums[i]) == allSet[nums[j]].end())
			{
				allSet[nums[j]].insert(nums[i]);
				if (allSet[nums[j]].size() > res) 
				{
					res = allSet[nums[j]].size();
					finalSet = allSet[nums[j]];
				}
				continue;
			}
		allSet[i] = { nums[i] };
	}
	vector<int>finalVector;
	finalVector.assign(finalSet.begin(), finalSet.end());
	return finalVector;
}

//动态规划 参考官方解法
// 必须有序才可以，如果无序，就牵扯到一个元素涵盖到多个集合的问题
// 此时dp[i]很难更新
vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());		
	int n = nums.size(),i,j;
	vector<int>dp(n,1);  //包含nums[i]为最大整数的最大子集的大小
	for (i = 0; i < n; ++i)
		for(j=0;j<i;++j)
			if (nums[i] % nums[j] == 0)
				dp[i] = max(dp[i], dp[j] + 1);
	
	auto maxIterator = max_element(dp.rbegin(), dp.rend());
	int maxSize = *maxIterator;
	vector<int>res;
	int maxVal = nums[dp.rend()-1-maxIterator];	

	for(i=n-1;i>=0&& maxSize>0;--i)
		if (dp[i] == maxSize&& maxVal %nums[i] ==0)
		{
			res.emplace_back(nums[i]);
			--maxSize;
		}
	return res;
}


int main()
{
	vector<int>vec = { 1, 2, 3 ,6, 9 , 14, 19, 21 };
	vector<int>res = largestDivisibleSubset(vec);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i]<<" ";
	//auto it = find(vec.rbegin(), vec.rend(), 14);
	//cout << vec.rend() -1 - it; 
}