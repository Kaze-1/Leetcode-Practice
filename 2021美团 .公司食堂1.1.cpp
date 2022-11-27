/*
https://www.nowcoder.com/question/next?pid=28665343&qid=1371128&tid=56166572
按模拟题的思路写！
换哈希表作为数据结构
*/
#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;


/*
哈希表的更新机制没设计好
尝试O(1)更新但是不成功
O(N)则没有降低时间开销
*/
void updateHash(unordered_map<int, int>& hash,vector<int>tables)
{
	int k;	int n = tables.size();
	//k = hash[1];
	k = 0;//min(hash[1],hash[0]);
	while (k != -1&&k != n && tables[k] != 1)k++;
	if (k != n)hash[1] = k;
	else hash[1] = -1;

	//k = min(hash[2], hash[0]);
	k = 0;
	while (k != -1 &&k != n && tables[k] != 2)k++;
	if (k != n)hash[2] = k;
	else hash[2] = -1;

	k = hash[0];
	while (k != -1 && k != n && tables[k] != 0)k++;
	if (k != n)hash[0] = k;
	else hash[0] = -1;

}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int i, j;
		int N; cin >> N;//number of tables
		string table; cin >> table;
		int M; cin >> M;//number of people
		string genders; cin >> genders;
		vector<int>tables(N);
		for (i = 0; i < N; i++)
		{
			tables[i] = table[i] - '0';
		}
		vector<int>ans(M,-1);
		unordered_map<int, int>hash;
		hash[0] = hash[1] = hash[2] = -1;
		for (i = 0; i < N; i++)
			if (tables[i] == 0) { hash[0] = i; break; }
		for (i = 0; i < N; i++)
			if (tables[i] == 1) { hash[1] = i; break;}
		for (i = 0; i < N; i++)
			if (tables[i] == 2) { hash[2] = i; break;}
		for (i = 0; i < M; i++)
		{
			if (genders[i] == 'M')
			{
				int k = hash[1];
				if(k==-1)k = hash[0];
				tables[k]++;
				updateHash(hash, tables);
				ans[i] = k+1;
				//break;
			}
			else
			{
				int k = hash[0];
				if (k == -1)k = hash[1];
				tables[k]++;
				updateHash(hash, tables);
				ans[i] = k + 1;
				//break;
			}
		}
		for (i = 0; i < M; i++)
			cout << ans[i] << '\n';
	}
}


/*
1 5 01102 6 MFMMFF



*/