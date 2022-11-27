#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

/*
* 构造不出最优子过程，遍历太耗时间
所以用模拟法解决
就近分配最近的值，累加操作次数
*/

/*
 问题：虽然测试例子acc，但是提示没有用例通过！！！！
 思路错误？
*/
int main()
{
	int n,i; cin >> n;
	vector<int>nums(n+1);
	for (i = 1; i <= n; i++)
		cin >> nums[i];
	vector<int>flags(1+n, -1);// >=0为有效
	for (i = 1; i <= n; i++)
		if (nums[i] >= 1 && nums[i] <= n)flags[nums[i]] = 0;
	int k = 1; while (flags[k] == 0)k++;
	int j = n; while (flags[j] == 0)j--;
	for (i = 1; i <= n; i++)
	{
		if (nums[i] < 1)
		{
			flags[i] = k - nums[i];
			k++;
		}
		else if (nums[i] > n)
		{
			flags[i] = nums[i] - j;
			j--;
		}
	}
	cout<<accumulate(flags.begin()+1, flags.end(), 0);
		

}

/*
5

-1 2 3 10 100
*/