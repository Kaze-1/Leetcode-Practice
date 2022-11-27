#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

/*二维 01 dp
可以在任意地方添加1
*/

int stringDp(string s)
{
	int n = s.size();
	string t = s;
	vector<vector<int>>dp(n, vector<int>(n, 0));
	int span, i, j;
	for (span = 2; span <= n; span++)
		for (i = 0; i <= n - span; i++)
		{
			j = i + span - 1;
			
			if (t[j] == '1' && t[i + 1] != '1')
			{
				dp[i][j] = dp[i + 1][j] + 1;
				t.insert(i+1,'1')
			}
			else if (t[i] == '1'&& t[j- 1] != '1')dp[i][j] = dp[i][j - 1] + 1;
			//else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;

			if (t[i] == t[j])
				dp[i][j] = min(dp[i][j], dp[i + 1][j - j]);
		}
	return dp[0][n - 1];
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		cout << stringDp(s)<<endl;
	}
}
/*
4 10101 00001 01001101 1110

1 00001
*/