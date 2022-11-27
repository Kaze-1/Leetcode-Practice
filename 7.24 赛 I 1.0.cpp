#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;
typedef long long ll;
const int MAX = 100001;


int main()
{
	int n,i,j; cin >> n;
	vector<bool>flags(MAX);		//0ÆúÓÃ
	vector<int>a(MAX);
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
	{
		flags[i] = 1;
		for (j = i + 1; j <= i + a[i]; j++)
			flags[j] = 1;
	}
	for(j= MAX-1;j>=1;j--)
		if (flags[j] == 1)
		{
			cout << j;
			break;
		}
}


/*
5
1 1 1 1 1
*/

