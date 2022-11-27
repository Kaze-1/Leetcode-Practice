#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;



//bool check(int A, int B, int C, )

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	ll w = 0;
	ll t = 0;
	while (1)
	{
		if (w == 0 || w == 4 || w == 5)a -= 8;
		else if (w == 1 || w == 6 )b -= 5;
		else c -= 7;
		if (a < 0 || b < 0 || c < 0)break;
		t++;
		w = (w + 1) % 7;
	}
	cout << t;
}