#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXVEX 10001


vector<bool>visited(MAXVEX);
vector<int>nums(MAXVEX); //ÿ���ڵ�Ӱ���AS��Ŀ
//�������Ҫ���Ǻ�Դ�ڵ�Ĺ�ϵ(ֻ��һ����ֻ��������������...)
void dfs(vector<vector<int>> edge,int start)
{
	if (!visited[start])
	{
		visited[start] = 1;
		
	}
}

int main()
{
	int n, m,i,j;
	cin >> n >> m;
	vector<vector<int>>edge;
	for (i = 0; i < m; i++)
	{
		int pre, tem;
		cin >> pre >> tem;
		edge.emplace_back(vector<int>({ pre, tem }));
	}
	dfs(edge, 2);
}