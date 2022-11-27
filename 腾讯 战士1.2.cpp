#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;


//下标为1~n 共N=n+1个元素

int getMin2(vector<int>soldiers)
{
	int N = soldiers.size();
	int n = N - 1;
	int i, j;
	set<int>Mins;
	vector<int>w(N);
	vector<int>v(N);

	for (j = 1; j <= n; j++)
		if (soldiers[j] == 0)w[j] += (w[j - 1] + j);

	for (j = n-1; j >=0; j--)
		if (soldiers[j+1] == 1)v[j] += (v[j + 1] + j+1);

	for (j = 1; j <= n-1; j++)
		Mins.insert(abs(w[j] - v[j]));
	return *min_element(Mins.begin(), Mins.end());
}



int main()
{
	int n, i;
	cin >> n;
	vector<int>soldiers(n + 1);
	string s; cin >> s;
	for (i = 1; i <= n; i++) //第0个弃掉
	{
		soldiers[i]=int(s[i-1]-'0');
	}
	cout << getMin2(soldiers);
}