#include <bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF
typedef long long ll;
int main() {
	int n,i,j;
	ll k, x;
	cin >> n >> k >> x;
	vector<int> res;//或许用不到
	vector<bool> flag(x+1);//用1-x
	ll sum = 0;
	for (j = 0; j < n; j++)//res
	{
		for (i = 1; i <= x; i++)//flag
		{
			if (i <= x - sum && flag[i] == false)//选数
			{
				flag[i] = 1;
				sum += i;
				res.push_back(i);
				break;//下一个res[j]
			}
			if (i == x - sum && flag[i] == true && res.size() < n)
			{
				cout << -1; return 1;
			}
		}
	}
	if (res.size() < n)
		cout<< -1;
	else
	{
		for (j = 0; j < n; j++)//res
			cout << res[j] << " ";
	}
		
		
}