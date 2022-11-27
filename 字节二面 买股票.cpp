#include<bits/stdc++.h>
using namespace std;

int purchaseStocks(vector<int>p)
{
	int n = p.size(), i, j;
	vector<vector<int>>dp(n,vector<int>(n+1)); //dp[i][j]
	for(i=1;i<n;i++)
		for (j = 0; j < n + 1; j++)
		{
			int delta = p[i] * j - p[i - 1];
			if (j == 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1] + delta);
			else dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j + 1] + delta), dp[i - 1][j - 1] - delta);
		}
	int Max = dp[n - 1][0];
	for (i = 1; i < n + 1; i++)
		if (dp[n - 1][i] > Max)Max = dp[n - 1][i];
	return Max;
}

int main()
{

}