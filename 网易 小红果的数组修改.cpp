/*
С����������޸�
*/

#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

long p;
int n,x;
vector<long> A;
long res = 0;//���ս�
long sum = 0;//��������Ԫ��֮��

//��loc��ʼ����
void dfs(int loc,vector<int>&flag)
{
	if (loc >=n||count(flag.begin(), flag.end(),0)==0)
		return;
	//[loc]�ĸķ�
	int i;
	if (flag[loc] == 0)
	{
		for (i = 1; i <= p; i++)
		{
			if (i != A[loc] && (sum - A[loc] + i) % x == 0)
			{
				res++;
				flag[loc] = 1;
			}
		}
	}

	
	for (i = loc + 1; i < n; i++)
		dfs(i, flag);
}

int main()
{
	cin >> n >> p>>x;	
	for (int i = 0; i < n; i++)
	{
		int tem; cin >> tem;
		sum += tem;
		A.push_back(tem);
	}
	vector<int>flag(n, 0);
	dfs(0, flag);
	cout << res;
}

/*
4 3 2
2 5 3 4

4
*/