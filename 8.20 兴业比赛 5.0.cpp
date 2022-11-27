
/*
邻接表
dfs即可

*/
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

//std::ios::sync_with_stdio(false); //写在main函数里！

//初始化visit[]数组
const int N = 4 * 10000 + 1;
vector<bool>visited(N);
vector<int>colors(N);
vector<vector<int>>graph(N);//0弃之不用，节点标号1~n
unordered_map<int, int>HashColored; //编号-颜色
unordered_map<int, int>Hash; //Hash:颜色-连通块大小
int Max;

void dfs(int n,int x)
{
	if (!visited[x])
	{
		visited[x] = true;//完成访问
		/*此处执行一些访问x的操作*/
		int color = 0;
		if (HashColored.find(x) != HashColored.end())
			color = HashColored[x];
		if (color!=0&&Hash.find(color) == Hash.end())
			Hash[color] = 1;
		//else if(color!=0)++Hash[color];
		for(auto e:graph[x])//对x的每一个邻接点进行DFS
		{	
			if (HashColored[x]== HashColored[e])
				dfs(n,e);
		}
		/*此处执行一些完成dfs(x)以后的操作*/
		if (color!=0)
			++Hash[color];
		if (Hash[color] > Max)Max = Hash[color]; //更新最大连通块的节点数目
	}
}

/*
题目要求输出 每次操作后的答案， 不是只dfs一次！！


*/
int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	int n, m, q,i,j;
	cin >> n >> m >> q;
	
	for (i = 0; i < m; ++i)
	{
		int tem1, tem2;
		cin >> tem1 >> tem2;
		if (tem1 != tem2)
		{
			graph[tem1].emplace_back(tem2);
			graph[tem2].emplace_back(tem1);
		}
	}
	//unordered_map<int, int>HashColored; //编号-颜色
	for (i = 0; i < q; ++i)
	{
		int tem;
		cin >> tem;
		cin >> HashColored[tem];
	}
	dfs(n,1);
	cout << Max;
}

/*
5 5 5
1 2
2 3
3 4
3 5
1 5
1 1
2 3
4 1
3 1
5 1

1
1
1
2
4
*/