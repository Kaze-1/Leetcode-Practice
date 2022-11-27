#include<bits/stdc++.h>
using namespace std;


//由于大小限制，改用g[x], g[y]两个数组存储所有的点即可





long long countPairs(int n, vector<vector<int>>& edges) {
	//转换数据结构
	vector<vector<int>>g(n);
	for (auto& e : edges)
	{
		int x = e[0], y = e[1];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<bool>visit(n);

	//int block = 0;
	long long  prev = 0; //之前遇到的分支的点总和
	int count = 0;//每个分支内有多少点
	function<void(int)>dfs = [&](int x) //? 函数内嵌套函数 (这样可以少开visit空间)
	{

		if (visit[x] == 0)
		{
			visit[x] = 1;
			count++;
			for (int p : g[x])//对于x的每一个邻接点执行dfs
				dfs(p);
			//block++;

		}
	};
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			count = 0;
			dfs(i);//进入dfs，算出这个分支区的count
			res += count * prev;//res+=新的分支点数*之前记录的所有点数
			prev += count;
		}
	}
	
	return res;
}

/*
function<int(int, int)>add = [](int x, int y)
{
	return x + y;
};
*/

int main()
{
	int n = 7;
	vector<vector<int>>edges = { {0, 2},{0, 5},{2, 4},{1, 6},{5, 4} };
	cout << countPairs(n, edges)<<endl;
	//cout<<add(1, 2);
}