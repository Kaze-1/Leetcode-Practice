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
	
	vector<int>seq(k);
	for (i = 0; i < k; i++)
		seq[i] = oriNums[i];
	sort(seq.rbegin(), seq.rend());

	int res = seq[k - 1];
	for (j = k; j <= n; j++)
	{
		cout << res << " ";
		if (j == n)break;
		if (res < oriNums[j])//res¸üÐ¡
		{
			
		}
			res = oriNums[hash[res] - 1];

		//nums.push_back(oriNums[j]);
		//sort(nums.rbegin(), nums.rend());
	}
		

}

/*
7 4
1 4 7 2 5 6 3
*/