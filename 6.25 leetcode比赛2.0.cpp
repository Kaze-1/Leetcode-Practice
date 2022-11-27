#include<bits/stdc++.h>
using namespace std;


//DFS统计连通分量(不连通的分支数)


//用全局变量解题最省心最好理解！
int N;//多少个连通分支
vector<int>con;//每个连通分支多少个节点

void dfs(int n,int x,vector<bool>visited, vector<vector<int>>& edges)
{
	if (visited[x] == 0)
	{
		visited[x] = 1;
		int i;
		for(i=x;i<n;i++)
			if()
	}	
	
}

//找出不同的连通分支 分支与分支之间组合计算
void getConnected(int n, vector<vector<int>>& edges)
{
	vector<bool>visited(n);
	int i;
	for (i = 0; i < n; i++)
		dfs(n,i, visited, edges);

}

long long countPairs(int n, vector<vector<int>>& edges) {
	//vector<vector<int>> con = getConnected(n, edges);
	//int m = con.size();//多少个分支
	vector<vector<int>>M(n, vector<int>(n));//n*n矩阵

	getConnected(n, edges);
	int m = N;
	int i, j;
	long long res = 0;
	for (i = 0; i < m - 1; i++)
		for (j = i + 1; j < m; j++)
			res += con[i] * con[j];
	return res;
}


int main()
{
	countPairs()
}