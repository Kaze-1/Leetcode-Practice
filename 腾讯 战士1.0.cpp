#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;


int getMin(vector<int>soldiers)
{
	int n = soldiers.size(),i;
	vector<int>rightOnes(n);
	vector<int>leftZeros(n);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
			leftZeros[i] = 1;
		else if (i > 0 && leftZeros[i - 1] == 0)
			leftZeros[i] = leftZeros[i - 1] + 1;
	}
		
		
}

int main()
{
	int n,i;
	cin >> n;
	vector<int>soldiers(n);
	for (i = 0; i < n; i++)
		cin >> soldiers[i];
	cout << getMin(soldiers);
}