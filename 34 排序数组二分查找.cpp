/*
34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> binarySearch(vector<int> nums,int target, int low, int high)
{
	if (high>low)
	{
		int mid = (high + low) / 2;
		if (nums[mid] == target)
		{
			int pivot = mid;
			vector<int>res;
			while (nums[pivot] == target)
				--pivot;
			res.emplace_back(pivot+1);
			pivot = mid;
			while (nums[pivot] == target)
				++pivot;
			res.emplace_back(pivot - 1);
			return res;
		}
		else if (nums[mid] > target)
			return binarySearch(nums, target, low, mid - 1);
		else 
			return binarySearch(nums, target, mid+1,high);
	}
	return {-1,-1};
}

vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0)return { -1,-1 };
	if (n == 1 && nums[0] == target)return{ 0,0 };
	return binarySearch(nums, target,0, n-1);
}

int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;
	vector<int>res = searchRange(nums, target);
	for (auto e : res)
		cout << e << " ";
}