/*
https://blog.csdn.net/qq_41901915/article/details/105856914

官方题解的理解， 以及C++版本
用哈希表和排序降低时间复杂度
数据结构
核心：D[i] array (>=0),i=m+n, 先存入工作难度再存人能力值
hs_Pay  hashmap(D[i]->P[i])

对D[i]排序(sort), D[i]->P[i]的最大值就是max(P[0],P[1],..,P[i])
如此将hs_Pay更新成目标所求 maxPay

再用hs_Pay输出每个人的最大收入的工作（maxPay）

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
	for (i = 0; i < N; i++)//输入（工作难度，收入）
	{
		cin >> D[i];
		cin>>hsPay[D[i]];
	}
	vector<int>Capab;		//！易错点 别写成Capab(M)  否则后面别push_back，要改成直接赋值
	for (i = N; i < N + M; i++)//输入伙伴工作能力
	{
		cin >> D[i];
		Capab.push_back(D[i]);
		if (hsPay.find(D[i]) == hsPay.end())
			hsPay[D[i]] = 0;	//没有记录的能力值暂定收入为0，方便后续排序(贪心)
	}
	sort(D.begin(), D.end()); //算法库中的排序

	//更新hsPay为最优解
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
示例输入：
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

示例输出：
100
1000
1001
*/

