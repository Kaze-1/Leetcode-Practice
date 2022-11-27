/*
����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s�����������һ�Լ��ɡ�

���룺nums = [2,7,11,15], target = 9
�����[2,7] ���� [7,2]

���룺nums = [10,26,30,31,47,60], target = 40
�����[10,30] ���� [30,10]
*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> getSum(vector<int>nums, int target)
{
	unordered_map<int, int>hashMap;
	int n = nums.size(),i;
	for (i = 0; i < n; i++)
	{
		hashMap[nums[i]] = i;
	}
	for (i = 0; i < n; i++)
	{
		if (hashMap.count(target - nums[i]) > 0)
			return { nums[i], nums[hashMap[target - nums[i]]] };
	}
	return {};
}


vector<int> getSumOnce(vector<int>nums, int target)
{
	unordered_map<int, int>hashMap;
	int n = nums.size(), i;
	for (i = 0; i < n; i++)
	{
		if (hashMap.count(target - nums[i]) > 0)
			return { nums[i], nums[hashMap[target - nums[i]]] };
		hashMap[nums[i]] = i;
	}
	return {};
}

int main()
{
	int target = 40;
	vector<int>nums = { 10,26,30,31,47,60 };
	vector<int>res = getSumOnce(nums, target);
	for (auto e : res)
	{
		cout << e<<" ";
	}
}