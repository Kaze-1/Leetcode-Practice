#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;
typedef long long ll;
const int MAX = 100001;

/*
* ��deque�ṹ��ά�����Ե�����̵�Ķ��У������п��Ե������һ���̵���ӣ�ͬʱ�����ù����̵꣬�Դ�����
* ��ʼʱֻ��ӵ�һ��
* �Ľ������ֻ��max������𰸴���
*/

int main()
{
	int n, i, j; cin >> n;
	vector<int>a(MAX);
	for (i = 1; i <= n; i++)
		cin >> a[i];
	deque<int>q;
	set<int>s;
	q.emplace_back(1);
	s.insert(1);
	int resMax = 1;
	while (q.size() > 0)
	{
		int tem = q.front();
		if (tem > resMax)resMax = tem;
		int iMax = tem + a[tem];//,val=a[iMax]+iMax;
		for (i = tem + a[tem]; i >=tem+1; i--)
		{
			if (iMax < a[i] + i)
			{
				iMax = a[i] + i;
			}
		}
		//ֻ������Ž�
		if (s.find(iMax) == s.end())
			{
				q.emplace_back(iMax);
				s.insert(iMax);
			}
		q.pop_front();
		s.erase(tem);
	}
	cout << resMax;
}

/*
5
1 1 1 1 1
*/