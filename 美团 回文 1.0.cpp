#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

/*¶þÎ¬ 01 dp*/ 

int stringDp(string s)
{
	int n = s.size();
	vector<vector<int>>dp(n, vector<int>(n,0));
	int span, i,j;
	for(span=2;span<=n;span++)
		for (i = 0; i <= n - span; i++)
		{
			j = i + span - 1;
			if (s[i + 1] == '1' && s[j - 1] == '1')dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			else if (s[i + 1] == '1')dp[i][j] = dp[i + 1][j] + 1;
			else if(s[j - 1] == '1')dp[i][j] = dp[i][j - 1] + 1;

			if (s[i] == s[j])
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
		cout << stringDp(s);
	}
}