#include<bits/stdc++.h> 
#include<unordered_map> 
#include<deque> 
using namespace std;
#define INF  0x7fffffff
typedef long long ll;

/*
* ���첻�������ӹ��̣�����̫��ʱ��
������ģ�ⷨ���
�ͽ����������ֵ���ۼӲ�������
*/

/*
 ���⣺��Ȼ��������acc��������ʾû������ͨ����������
 ˼·����
*/
int main()
{
	int n,i; cin >> n;
	vector<int>nums(n+1);
	for (i = 1; i <= n; i++)
		cin >> nums[i];
	vector<int>flags(1+n, -1);// >=0Ϊ��Ч
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