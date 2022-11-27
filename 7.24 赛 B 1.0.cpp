#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;
typedef long long ll;
const int MAX = 50;


vector<vector<int>>Mat(MAX, vector<int>(MAX));		//P:1	N:0
vector<vector<int>>flags(MAX, vector<int>(MAX));	//访问过：1  未访问0，无法访问-1

int explore(int x, int y,int n) 
{
	int i, j,maxCol=0,maxRow=0;
	deque<int>tem;
	deque<vector<int>>visit;
	for (i = 1; i < n && flags[x][i] == 0; i++)
	{
		tem.emplace_back(i);
		visit.emplace_back(vector<int>{ x, i });
	}
	maxCol = max(maxCol, i - 1);
	while(tem.size()>0)
	{
		int t = tem.front();
		tem.pop_front();
		for (i = 1; i < n && flags[i][t] == 0; i++)
		{
			maxRow = max(maxRow, i);
			visit.emplace_back(vector<int>{ i, t });
		}
	}

	tem.clear();
	for (i = 1; i < n && flags[i][y] == 0; i++)
	{
		tem.emplace_back(i);
		visit.emplace_back(vector<int>{ i, y });
	}
	maxRow = max(maxRow, i - 1);
	while (tem.size() > 0)
	{
		int t = tem.front();
		tem.pop_front();
		for (i = 1; i < n && flags[t][i] == 0; i++)
		{
			maxCol = max(maxCol, i);
			visit.emplace_back(vector<int>{ t, i });
		}
	}
	while (visit.size() > 0)
	{
		vector<int>T = visit.back();
		flags[T[0]][T[1]] = 1;
		visit.pop_back();
	}
	return min(maxCol, maxRow);
}

//还是得dfs！
int dfs(int x, int y, int n)
{
	deque<vector<int>>visit;
	int direc=0;//取值0,1,2,3  上下左右
	int i, j;
	for (i = x - 1; i >= 0; i--)
	{
		visit.emplace_back(vector<int>{ i, y });
	}
	direc = (direc + 1)%4;
	for (i = y + 1; i < n; i++)
		visit.emplace_back(vector<int>{ x, i });
	direc = (direc + 1) % 4;
	for (i = x + 1; i < n; i++)
		visit.emplace_back(vector<int>{ i, y });
	direc = (direc + 1) % 4;
	for (i = y - 1; i >=0; i--)
		visit.emplace_back(vector<int>{ x,i });
	
}

int main()
{
	int i,j,n; cin >> n;
	//function<void(int,int)>dfs = [](i,j)
	//{/*function body*/};    //别忘了分号
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			char tem; cin >> tem;
			if (tem == 'P')Mat[i][j] = 1;
			if(tem=='N')flags[i][j] = -1;
		}
	vector<int>res;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			//对于点(i,j)
			if (flags[i][j] == 0)
			{
				//dfs(i, j);
				res.emplace_back(explore(i, j, n));
			}
		}
	cout << accumulate(res.begin(), res.end(), 0);
}


/*

6

PNNPN
PNPPP
NPPPP
PNNNP
PNNNP

*/