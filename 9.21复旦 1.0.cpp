#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF


/*基于DFS求解
* 
*/
//初始化visit[]数组
const int N = INT_MAX;  // >1*10^9

ll res = 0;
int direc = 0;//0 1 2 3 —— 右 下 左 上
string joy = "";

void dfs(vector<vector<bool>> visited, vector<vector<int>> Map,int x,int y,int k,int n,int m)
{
	if (!visited[x][y])
	{
		visited[x][y] = true;//完成访问
		/*访问x的操作*/
		string lastJoy = joy;
		int lastK = k;
		joy += to_string(Map[x][y]);
		if (stoi(joy) % 7 == 0)++res;
		for (direc = 0;direc<=3;direc=(direc+1)% 4)//对x的每一个邻接点进行DFS
		{
			if (direc != 0 && k > 0)--k;
			else break;
			if (direc == 0&&y+1<m)
				dfs(visited, Map,x, y + 1, k,n,m);
			else if (direc == 1 && x + 1 < n)
				dfs(visited, Map,x+1, y, k-1, n, m);
			else if (direc == 2 && x-1 > 0)
				dfs(visited, Map,x-1, y, k-1, n, m);
			else if (direc == 3 && y - 1 >0)
				dfs(visited, Map,x, y - 1, k-1, n, m);
			//dfs(point);
		}
		/*完成dfs(x)以后的操作, 回溯*/
		joy = lastJoy;
		k = lastK;
	}
}


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int i, j;
	vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
	vector<vector<int>> Map(n+1, vector<int>(m+1, 0));
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			cin >> Map[i][j];
	dfs(visited,Map,1, 1,k,m,n);
	cout << res;
}



/*
2 3 2
79 8 12
31 10 5
*/
