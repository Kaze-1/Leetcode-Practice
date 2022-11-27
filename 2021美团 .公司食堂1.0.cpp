/*
https://www.nowcoder.com/question/next?pid=28665343&qid=1371128&tid=56166572
按模拟题的思路写！

*/
#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int i, j;
		int N;cin >>N;//number of tables
		string table; cin >> table;
		int M; cin >> M;//number of people
		string genders; cin >> genders;
		vector<int>tables(N);
		for (i = 0; i < N; i++)
		{
			tables[i] = table[i] - '0';
		}
		vector<int>ans(M);
		int k = 0;
		while (tables[k] == 2)k++;
		for (i = 0; i < M; i++)
			if (genders[i] == 'M')
			{
				while (tables[k] == 2)k++;
				for (j = k; j < N; j++)
					if (tables[j] == 1)
					{
						tables[j]++;
						ans[i] = j + 1;
						break;
					}
				if (j == N)
				{
					while (tables[k] == 2)k++;
					for (j = k; j < N; j++)
						if (tables[j] == 0)
						{
							tables[j]++;
							ans[i] = j + 1;
							break;
						}
				}
			}
			else
			{
				while (tables[k] == 2)k++;
				for (j = 0; j < N; j++)
					if (tables[j] == 0)
					{
						tables[j]++;
						ans[i] = j + 1;
						break;
					}
				if (j == N)
				{
					while (tables[k] == 2)k++;
					for (j = 0; j < N; j++)
						if (tables[j] == 1)
						{
							tables[j]++;
							ans[i] = j + 1;
							break;
						}
				}
			}
		for (i = 0; i < M; i++)
			cout << ans[i] << endl;
	}
	
	
}