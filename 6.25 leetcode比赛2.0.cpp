#include<bits/stdc++.h>
using namespace std;


//DFSͳ����ͨ����(����ͨ�ķ�֧��)


//��ȫ�ֱ���������ʡ�������⣡
int N;//���ٸ���ͨ��֧
vector<int>con;//ÿ����ͨ��֧���ٸ��ڵ�

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

//�ҳ���ͬ����ͨ��֧ ��֧���֧֮����ϼ���
void getConnected(int n, vector<vector<int>>& edges)
{
	vector<bool>visited(n);
	int i;
	for (i = 0; i < n; i++)
		dfs(n,i, visited, edges);

}

long long countPairs(int n, vector<vector<int>>& edges) {
	//vector<vector<int>> con = getConnected(n, edges);
	//int m = con.size();//���ٸ���֧
	vector<vector<int>>M(n, vector<int>(n));//n*n����

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