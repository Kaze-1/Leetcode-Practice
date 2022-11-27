#include<bits/stdc++.h>
using namespace std;

#define MAX 0x7FFFFFFF

//感觉没有构造出最优子结构！

int getMinTime(vector<int> pos, vector<int> require)
{
	int n = pos.size(),i;
	vector<bool>flags(n);//是否满足了需求
	int total = 0;
	auto last = find(flags.begin(),flags.end(),0);
	while (last!=flags.end())
	{
		int min = MAX,min_i=-1;
		for (i = 0; i < n; i++)
			if (flags[i] && require[i] < min&& require[i]+total>=0)
			{
				min = require[i];
				min_i = i;
			}
		if (i == n && min_i == -1)break;
		flags[min_i] = 1;
		total += min;
		last = find(flags.begin(), flags.end(), 0);
	}
	return total;
}
int main()
{
	int n,i;
	cin >> n;//店铺数量
	vector<int>pos(n);
	vector<int>require(n);
	for (i = 0; i < n; i++)
		cin >> pos[i];
	for (i = 0; i < n; i++)
		cin >> require[i];
	cout << getMinTime(pos, require);
}