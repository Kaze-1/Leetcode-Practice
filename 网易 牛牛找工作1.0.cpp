/*
https://blog.csdn.net/qq_41901915/article/details/105856914

�ٷ�������⣬ �Լ�C++�汾
�ù�ϣ������򽵵�ʱ�临�Ӷ�
���ݽṹ
���ģ�D[i] array (>=0),i=m+n, �ȴ��빤���Ѷ��ٴ�������ֵ
hs_Pay  hashmap(D[i]->P[i])

��D[i]����(sort), D[i]->P[i]�����ֵ����max(P[0],P[1],..,P[i])
��˽�hs_Pay���³�Ŀ������ maxPay

����hs_Pay���ÿ���˵��������Ĺ�����maxPay��

*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;



int main()
{
	int N, M; cin >> N >> M;
	vector<int>	D(N + M);
	unordered_map<int, int>hsPay;
	int i;
	for (i = 0; i < N; i++)//���루�����Ѷȣ����룩
	{
		cin >> D[i];
		cin>>hsPay[D[i]];
	}
	vector<int>Capab;		//���״�� ��д��Capab(M)  ��������push_back��Ҫ�ĳ�ֱ�Ӹ�ֵ
	for (i = N; i < N + M; i++)//�����鹤������
	{
		cin >> D[i];
		Capab.push_back(D[i]);
		if (hsPay.find(D[i]) == hsPay.end())
			hsPay[D[i]] = 0;	//û�м�¼������ֵ�ݶ�����Ϊ0�������������(̰��)
	}
	sort(D.begin(), D.end()); //�㷨���е�����

	//����hsPayΪ���Ž�
	int max = 0;
	for (i = 0; i < D.size(); i++)
	{
		if (max < hsPay[D[i]])max = hsPay[D[i]];
		hsPay[D[i]] = max;
	}
	for (i = 0; i < M; i++)
		cout << hsPay[Capab[i]]<<endl;
}

/*
ʾ�����룺
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

ʾ�������
100
1000
1001
*/

