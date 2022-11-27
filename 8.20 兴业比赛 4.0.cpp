#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

//std::ios::sync_with_stdio(false); //写在main函数里！


int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	
	string s;
	cin >> s;
	vector<int>sum(4);
	int n = s.size(),i=0,j=0;

	
	while (s[i] != 'x'&&i<n)
		++i;
	while (s[i] == 'x' && i < n)
	{
		++sum[0];
		++i;
	}
	while (s[i] != 'i' && i < n)
		++i;
	while (s[i] == 'i' && i < n)
	{
		++sum[1];
		++i;
	}
	while (s[i] != 'n' && i < n)
		++i;
	while (s[i] == 'n' && i < n)
	{
		++sum[2];
		++i;
	}
	while (s[i] != 'g' && i < n)
		++i;
	while (s[i] == 'g' && i < n)
	{
		++sum[3];
		++i;
	}
	cout << *min_element(sum.begin(),sum.end());
}