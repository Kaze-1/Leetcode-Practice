#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
	int N;//��Ʒ����
	int M;//��������
	cin >> N >> M;
	vector<int>w(N+1);//��Ʒ����
	vector<int>v(N+1);//��Ʒ��ֵ
	for (int i = 1; i <= N; i++)
		cin >> w[i];
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	vector<vector<int>>dp(N+1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (j < w[i])dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
	/*
	vector<int>maxElements;f
	for (vector<int> e : dp)
		maxElements.emplace_back(*max_element(e.begin(), e.back()));
	cout << *max_element(maxElements.begin(), maxElements.back());

	*/
	int MAX = dp[N][1];
	for (int i = 1; i <= M; i++)
			if (dp[N][i] > MAX)
				MAX = dp[N][i];
	cout << MAX;
				
}


/*
5
10
2 2 6 5 4
6 3 5 4 6

��ȷ�����15
*/