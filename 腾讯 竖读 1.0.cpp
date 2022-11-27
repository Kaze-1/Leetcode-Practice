#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;


int main()
{
	int n; cin >> n;
	vector<string>num_s;
	int N = n;
	while (N--)
	{
		string s; cin >> s;
		num_s.push_back(s);
	}
	int i, j;
	int m = num_s[0].length();
	vector<int>nums;
	for (j = 0; j < m; j++)
	{
		//对于每个数字
		string tem="";
		for (i = 0; i < n; i++)
		{
			tem += num_s[i][j];
		}
		//cout << tem << " ";
		nums.push_back(stoi(tem));
	}
	


	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}