/*
* ��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ������������
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxSquare(vector<vector<int>>M)
{
	int m = M.size();
	int n = M[0].size();
	int i, j;
	vector<vector<int>>dp=M;//�洢������������εı߳�
	//��������Max
	for(i=1;i<m;i++)
		for (j = 1; j < n; j++)
		{
			if (M[i][j])
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;				
				
				/*
				int left =M[i - 1][j] ? dp[i - 1][j] : 1;
				int up = M[i - 1][j - 1] ? dp[i - 1][j - 1] : 1;
				int right = M[i][j - 1] ? dp[i][j - 1] : 1;
				if(i>0&&j>0&&M[i][j]&& dp[i - 1][j] && dp[i - 1][j-1]&& dp[i][j - 1])
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])+1;
				else if()*/
			}
		}
	vector<int>Max;
	for (auto e : dp)
	{
		Max.emplace_back(*max_element(e.begin(), e.end()));
	}
	return *max_element(Max.begin(), Max.end());
}

int main()
{
	vector<vector<int>>M = { {1,1,1},{1,1,0},{0,0,1} };
	cout << getMaxSquare(M);
	return 0;
}