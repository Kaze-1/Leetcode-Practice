#include <bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF
typedef long long ll;
int main() {
	int n, i=INF, j;
	ll k, x;
	cin >> n >> k >> x;
	vector<int> res;//或许用不到
	vector<bool> flag(x + 1);//用1-x
	ll sum = 0;
	for (j = 0; j < n;)//res
	{
		if (j == -1)
		{cout << -1; return 0;}
		if (x == sum)
			break;
		//从大的(x-sum)数开始选,选不下去就回退，无路可退时结束输出-1
		for (i = x-sum; i >= 1; i--)//flag
		{
			if (flag[i] == false)//选数
			{
				flag[i] = 1;
				sum += i;
				res.push_back(i);
				j++;
				break;//下一个res[j]
			}
			else if (x == 1 && flag[i] == true)//选不了，需要回溯
			{
				//回退
				j--;
				int lastNum = res.back();
				res.pop_back();
				sum -= lastNum;
				flag[lastNum] = 0;
				break;
			}
		}
	}
	if (res.size() < n)
		cout << -1;
	else
	{
		for (j = 0; j < n; j++)//res
			cout << res[j] << " ";
	}


}



/*
2 2 2 

*/