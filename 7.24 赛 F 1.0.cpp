#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;
typedef long long ll;

int main()
{
	int n,res; cin >> n;
	string A; cin >> A;
	string B; cin >> B;
	string A1 = A;
	for (int i = 0; i < n; i++)
	{
		if (A1 == B) { cout << i; break; }
		char tem = A1[0];
		A1 = A1.substr(1) + tem;
	}
}

/*
10
SIAJOIWUGB
IBUSJGWAOI
*/