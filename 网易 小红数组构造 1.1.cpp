#include <bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF
typedef long long ll;
int main() {
	int n, i=INF, j;
	ll k, x;
	cin >> n >> k >> x;
	vector<int> res;//�����ò���
	vector<bool> flag(x + 1);//��1-x
	ll sum = 0;
	for (j = 0; j < n;)//res
	{
		if (j == -1)
		{cout << -1; return 0;}
		if (x == sum)
			break;
		//�Ӵ��(x-sum)����ʼѡ,ѡ����ȥ�ͻ��ˣ���·����ʱ�������-1
		for (i = x-sum; i >= 1; i--)//flag
		{
			if (flag[i] == false)//ѡ��
			{
				flag[i] = 1;
				sum += i;
				res.push_back(i);
				j++;
				break;//��һ��res[j]
			}
			else if (x == 1 && flag[i] == true)//ѡ���ˣ���Ҫ����
			{
				//����
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