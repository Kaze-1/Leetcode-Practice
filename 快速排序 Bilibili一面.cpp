#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&nums, int l, int h)
{
	int pivot = nums[l];
	while (l < h)
	{
		while (l < h && nums[h] >= pivot)
			h--;
		nums[l] = nums[h];
		while (l < h && nums[l] <= pivot)
			l++;
		nums[h] = nums[l];
	}
	nums[l] = pivot;
	return l;
}

void rapidSort(vector<int>&nums, int l, int h)
{
	if (l < h)
	{
		int pivot = partition(nums, l, h);
		rapidSort(nums, l, pivot - 1);
		rapidSort(nums, pivot + 1, h);
	}
}

int main()
{
	vector<int>nums = { 9,3,4,2,2,1 };
	int n = nums.size();
	rapidSort(nums,0,n-1);
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
}