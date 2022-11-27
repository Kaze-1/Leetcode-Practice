#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

int main()
{
	int n, k, i, j;
	cin >> n >> k;
	vector<int>oriNums(n);
	for (i = 0; i < n; i++)
		cin >> oriNums[i];
	vector<int>nums = oriNums;
	sort(nums.rbegin(), nums.rend());
	//reverse(nums.begin(), nums.end());
	
	unordered_map<int, int>hash;
	for (i = 0; i < n; i++)
		hash[nums[i]] = i;

	vector<bool>flags(n);
	for (i = 0; i < k; i++)
		flags[hash[nums[i]]] = 1;
	int last =0 ,t=0;
	for (; flags[last] && last < n; last++)
	{
		if (t == k) { cout << oriNums[last] << " "; t = 0; }
		t++;
		//oriNums
	}

	
}

/*
7 4
1 4 7 2 5 6 3
*/