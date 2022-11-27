#include<bits/stdc++.h>
using namespace std;

//misunderstood the requirements
int unequalTriplets1(vector<int>& nums) {
	set<int>numSet;
	for (auto i : nums)
	{
		numSet.insert(i);
	}
	int n = numSet.size();
	if (n < 3)return 0;
	else return n * (n - 1) * (n - 2) / 6;
}


//±©Á¦·¨£¡
int unequalTriplets(vector<int>& nums) {
	int n = nums.size();
	//set<vector<int>>res;
	int sum = 0;
	int i, j, k;
	for (i = 0; i < n - 2; ++i)
		for (j = i + 1; j < n - 1; ++j)
			for (k = j + 1; k < n; ++k)
				//res.insert({ i,j,k });
			{
				if (nums[i] != nums[j] && nums[i] != nums[k] && nums[k] != nums[j])
					++sum;
			}
	//return  res.size();
	return sum;
}


int main()
{
	vector<int>test = { 4, 4, 2, 4, 3 };
}