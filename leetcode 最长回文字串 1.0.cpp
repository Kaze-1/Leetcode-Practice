#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

string longestPalindrome(string s) {
	int n = s.length(),i,j;
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (i = 0; i < n; i++)//单个字符默认是回文
		dp[i][i] = 1;
	//if (n % 2 == 0 && s[n / 2-1] == s[n / 2])dp[n / 2-1][n / 2] = 1;
	//多个连续相同字符也是回文
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])dp[i][j] = 1;
			else break;
		}
	//适合换更好的迭代方式
	/*
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (i+1<n&&j-1>=0&&i+1<=j-1&&s[i]==s[j])dp[i][j] = dp[i + 1][j - 1];
			//else if (i + 1 < n && j - 1 > 0 && i + 1 <= j - 1 && s[i] != s[j])dp[i][j] = 0;
		*/
	for(j=1;j<n;j++)
		for(i=0;i<j;i++)
			if (i + 1 < n && j - 1 >= 0 && i + 1 <= j - 1 && s[i] == s[j])dp[i][j] = dp[i + 1][j - 1];
	int k1=-1, k2=-1, Max=-1;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (dp[i][j]&& j-i + 1 > Max) {
					Max = j - i + 1;
					k2 = j, k1 = i;
			}
	return s.substr(k1, Max);
}

int main()
{
	string s = "abcba";
	string s1 = "aaacbsaaa";
	string s2 = "aaaaaaa";

	cout << longestPalindrome(s2);

}