#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

//DFS即可 联通题
/*
void dfs(vector<vector<int>>Matrix, vector<vector<int>>& FlagVisit, int& res)
{
	if()
}*/

int main()
{
	int M, N,i,j;
	cin >> M >> N;
	vector<vector<int>> Matrix(M, vector<int>(N));//M*N 规模
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> Matrix[i][j];
	vector<vector<int>> FlagVisit(Matrix);//2表示0——>访问
	//int res = 0;
	//用BFS解决
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			if(Matrix[i][j]==0&& Matrix[i][j])
		}
			

	vector<tuple<int, int>>points;
	while (points.size() > 0)
	{
		
	}
}