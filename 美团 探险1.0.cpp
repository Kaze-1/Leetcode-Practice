#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

/*ģ�ⷨ*/

int main()
{
	ll k, n,i; cin >> k >> n;
	vector < tuple<ll, ll> >portion(n);//���� ����ֵ
	for (i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		get<0>(portion[i]) = x;
	}
	for (i = 0; i < n; i++)
	{
		ll y;
		cin >> y;
		get<1>(portion[i]) = y;
	}
	sort(portion.begin(), portion.end());//����x����
	ll stat = k;
	ll coordi = 0, porCo=0;//��ǰλ��  portionָ��
	while (stat >= 0)
	{
		if (porCo < n)
		{
			ll diff = get<0>(portion[porCo]) - coordi;
			if (diff <= stat)
			{
				stat += get<1>(portion[porCo]) - diff;
				coordi = get<0>(portion[porCo]);
				porCo++;
			}
			else
			{
				coordi += stat;
				stat -= stat;
			}
		}
		else 
		{
			coordi += stat;
			stat -= stat;
		}
		if (stat == 0 && (porCo == n || (porCo < n && get<0>(portion[porCo]) != coordi)))
			break;
	}
	cout << coordi;
}

/*
5 2
6 3
1 2


*/