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

	vector<int>nums(k);
	for (i = 0; i < k; i++)
		nums[i] = oriNums[i];
	sort(nums.rbegin(), nums.rend());
	for (j = k; j <= n; j++)
	{
		cout<<nums[k - 1]<<" ";
		if (j == n)break;
		nums.push_back(oriNums[j]);
		sort(nums.rbegin(), nums.rend());
	}
	
	//for (i = 0; i < n; i++)
		//cin >> oriNums[i];
}

/*
7 4
1 4 7 2 5 6 3
*/