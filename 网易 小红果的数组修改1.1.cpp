/*
С����������޸�1.1
*/

#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

long p;
int n, x;
vector<long> A;
long res = 0;//���ս�
long sum = 0;//��������Ԫ��֮��



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
	//�ҳ�sum-A[i]+1��sum-A[i]+p֮����ٸ�x�ı���
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