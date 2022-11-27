/*
手绘大风车
*/

#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

//将m向右旋转90度
vector<vector<int>> rotate(vector<vector<int>>m)
{
	int h = m.size();
	int w = m[0].size();
	vector<vector<int>>M(h,vector<int>(w,0));
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			M[i][j] = m[w - 1 - j][i];
	return M;
}
int main()
{
	int n; cin >> n;
	int N=2*n-1;
	vector<vector<int>>res(N, vector<int>(N, 0));
	int i, j;
	//填左上角
	for (i = 0; i < n; i++)
		res[n - 1][i] = 1;
	for (i = 0; i < n; i++)
		res[i][0] = 1;
	for (i = 0; i < n; i++)
		res[i][i] = 1;
	//
	vector<vector<int>>tem(n, vector<int>(n, 0));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			tem[i][j] = res[i][j];
	tem = rotate(tem);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i][j+n-1] = tem[i][j];
	tem = rotate(tem);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i][j + n - 1] = tem[i][j];
	tem = rotate(tem);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i+n-1][j] = tem[i][j];
	tem = rotate(tem);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i + n - 1][j + n - 1] = tem[i][j];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << res[i][j];
		cout <<endl;
	}
		
}


