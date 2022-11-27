#include<bits/stdc++.h>

using namespace std;


int removeDuplicates(vector<int>& nums)
{
	int n = nums.size();

	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	int K = nums.size();
	for (int i = 0; i < n - nums.size(); i++)
		nums.push_back(0);
	return K;
}



int main()
{
	vector<int> nums = { 3,4,5,5,1,8,9 };
	cout<<removeDuplicates(nums);
}