#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a, b, c,i,j,k;
	cin >> a >> b >> c;
	vector<vector<vector<int>>>dp(a, vector<vector<int>>(b, vector<int>(c)));
	for (i = 0; i < a; i++)
		dp[i][0][0] = i;
	for (i = 0; i < b; i++)
		dp[0][i][0] = i;
	for (i = 0; i < c; i++)
		dp[0][0][i] = i;
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++)
			for (k = 0; k < c; k++)
			{
				//dp·ÖÀàÌÖÂÛ
				int A = i > 0 && j > 0 ? dp[i - 1][j - 1][k] + 1 : 0;
				int B = i > 0 && k > 0 ? dp[i - 1][j][k - 1] + 1 : 0;
				int C = j > 0 && k > 0 ? dp[i][j - 1][k - 1] + 1 : 0;
				dp[i][j][k] = min(A, min(B, C));
			}
	cout << dp[a-1][b-1][c-1];
}