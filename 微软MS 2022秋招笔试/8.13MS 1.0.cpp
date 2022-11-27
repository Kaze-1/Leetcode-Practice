#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


//以排污量为优化目标 
int solution(vector<int>& A) {
	float sum = accumulate(A.begin(), A.end(), 0);
	float target = sum / 2;
	vector<int> B = A;
	int n = A.size(),i,j;
	vector<vector<float>>dp(n, vector<float>(n+1));
	for (i = 0; i < n; i++)
		dp[i][0] = sum;
	for(i=1;i<n;i++)
		for (j = 0; j < n; j++)
		{
			if(dp[i-1][j]<dp[i-1][])
		}

}

int main()
{
}

