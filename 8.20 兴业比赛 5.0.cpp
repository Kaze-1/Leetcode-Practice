
/*
�ڽӱ�
dfs����

*/
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

//std::ios::sync_with_stdio(false); //д��main�����

//��ʼ��visit[]����
const int N = 4 * 10000 + 1;
vector<bool>visited(N);
vector<int>colors(N);
vector<vector<int>>graph(N);//0��֮���ã��ڵ���1~n
unordered_map<int, int>HashColored; //���-��ɫ
unordered_map<int, int>Hash; //Hash:��ɫ-��ͨ���С
int Max;

void dfs(int n,int x)
{
	if (!visited[x])
	{
		visited[x] = true;//��ɷ���
		/*�˴�ִ��һЩ����x�Ĳ���*/
		int color = 0;
		if (HashColored.find(x) != HashColored.end())
			color = HashColored[x];
		if (color!=0&&Hash.find(color) == Hash.end())
			Hash[color] = 1;
		//else if(color!=0)++Hash[color];
		for(auto e:graph[x])//��x��ÿһ���ڽӵ����DFS
		{	
			if (HashColored[x]== HashColored[e])
				dfs(n,e);
		}
		/*�˴�ִ��һЩ���dfs(x)�Ժ�Ĳ���*/
		if (color!=0)
			++Hash[color];
		if (Hash[color] > Max)Max = Hash[color]; //���������ͨ��Ľڵ���Ŀ
	}
}

/*
��ĿҪ����� ÿ�β�����Ĵ𰸣� ����ֻdfsһ�Σ���


*/
int main()
{
	std::ios::sync_with_stdio(false); //д��main�����
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
	//unordered_map<int, int>HashColored; //���-��ɫ
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