/*
* https://www.nowcoder.com/test/question/9c4a4e879b4f49939dfaebea8948f976?pid=28665343&tid=56166572
* ≈≈–Úº¥ø…
*/
#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

bool check(int x,int y, int num)
{
	return num <= y && num >= x;
}

int main()
{
	int n, x, y,i;
	cin >> n >> x >> y;
	vector<int>scores(n);
	for (i = 0; i < n; i++)
		cin >> scores[i];
	//if (x > y)swap(x, y);
	sort(scores.begin(), scores.end());
	for(i=0;i<n;i++)
		if (check(x, y, i + 1) && check(x, y, n - (i + 1)))
		{
			cout << scores[i];
			return 0;
		}
	cout << -1;
}

