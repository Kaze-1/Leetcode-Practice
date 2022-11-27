/*
34. �����������в���Ԫ�صĵ�һ�������һ��λ��
����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
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