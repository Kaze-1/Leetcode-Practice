#include<bits/stdc++.h>
using namespace std;


//���ڴ�С���ƣ�����g[x], g[y]��������洢���еĵ㼴��





long long countPairs(int n, vector<vector<int>>& edges) {
	//ת�����ݽṹ
	vector<vector<int>>g(n);
	for (auto& e : edges)
	{
		int x = e[0], y = e[1];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<bool>visit(n);

	//int block = 0;
	long long  prev = 0; //֮ǰ�����ķ�֧�ĵ��ܺ�
	int count = 0;//ÿ����֧���ж��ٵ�
	function<void(int)>dfs = [&](int x) //? ������Ƕ�׺��� (���������ٿ�visit�ռ�)
	{

		if (visit[x] == 0)
		{
			visit[x] = 1;
			count++;
			for (int p : g[x])//����x��ÿһ���ڽӵ�ִ��dfs
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
			dfs(i);//����dfs����������֧����count
			res += count * prev;//res+=�µķ�֧����*֮ǰ��¼�����е���
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