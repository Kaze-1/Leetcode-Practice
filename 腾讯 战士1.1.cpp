#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;


//下标为1~n 共N=n+1个元素
int getMin(vector<int>soldiers)
{
	int N = soldiers.size(), i;
	int n = N - 1;
	vector<int>right(N);
	vector<int>left(N);
	if(soldiers[1]==0)left[1] = 1;
	else left[1] = 0;
	for (i = 2; i <= n; i++)
		if (soldiers[i] == 0)
			left[i] += left[i-1]+ i;



	if (soldiers[n] == 1)right[n-1] = n;
	else left[1] = 0;
	for (i = n; i >= 1; i--)
		if (soldiers[i] == 1)
			right[i] += right[i]+i+1;

	/*
	for (i = 0; i < n; i++)
	{
		if (i == 0)
			leftZeros[i] = 1;
		else if (i > 0 && leftZeros[i - 1] == 0)
			leftZeros[i] = leftZeros[i - 1] + 1;
	}*/


}

int main()
{
	int n, i;
	cin >> n;
	vector<int>soldiers(n+1);
	for (i = 1; i <=n; i++) //第0个弃掉
		cin >> soldiers[i];
	cout << getMin(soldiers);
}