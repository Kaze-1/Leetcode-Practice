#include <bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF
typedef long long ll;

ll fun(ll n)
{
	vector<ll>count(2);
	while (n % 2 == 0)
	{
		count[0]++;
		n /= 2;
	}
	while (n % 5 == 0)
	{
		count[1]++;
		n /= 5;
	}
	/*if (count[0] == 0)return count[1];
	else if(count[1] == 0)return count[0];
	else return min(count[0], count[1]);*/

	return min(count[0], count[1]);
}

int main()
{
	int N; cin >> N;
	int i, j,k;
	vector<ll>a(N);
	for (i = 0; i < N; i++)
		cin >> a[i];
	ll res = 0;

	//需要降时间复杂度
	for(i=0;i<N;i++)
		for (j = i; j < N; j++)
		{
			ll mult = 1;
			for (k = i; k <= j; k++)
				mult *= a[k];
			res += fun(k);
		}
	cout << res;
}