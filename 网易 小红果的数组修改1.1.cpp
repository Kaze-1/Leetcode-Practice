/*
小红果的数组修改1.1
*/

#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

long p;
int n, x;
vector<long> A;
long res = 0;//最终解
long sum = 0;//数组所有元素之和



int main()
{
	cin >> n >> p >> x;
	int i, j;
	for (i = 0; i < n; i++)
	{
		int tem; cin >> tem;
		sum += tem;
		A.push_back(tem);
	}
	//vector<int>flag(n, 0);
	for (i = 0; i < n; i++)
	//找出sum-A[i]+1到sum-A[i]+p之间多少个x的倍数
	{
		int a = sum - A[i] + 1;
		int b = sum - A[i] + p;
		int left = a / x; if (a > 0 && a % x)left++;	
		int right = b / x; if (b > 0 && b % x)right--;
		int nums = (right - left) + 1;
		if (A[i]>p)
			res += nums;
		else res += nums-1;
		//cout<< nums <<" ";
	}
	/*
	* for (j = 1; j <= p; j++)
		{
			if (j != A[i] && (sum - A[i] + j) % x == 0)
				res++;
		}
	* */
		
	cout << res;
}



/*
4 3 2
2 5 3 4

4

3 4 2
1 2 3 

4
*/