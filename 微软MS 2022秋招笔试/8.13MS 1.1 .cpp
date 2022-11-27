#include<bits/stdc++.h>
#include<unordered_map>

#include<algorithm>
#include <functional>
#include <queue>
using namespace std;


//以排污量为优化目标  当成数学问题解决，每次挑最优的(贪心算法)减半
int solution(vector<int>& A) {
	float sum = accumulate(A.begin(), A.end(), 0);
	float target = sum / 2;
	int res = 0,i,n=A.size();
	sort(A.begin(), A.end());
	//unordered_map<int, set<int>>hash;
	priority_queue<int>q;
	for (i = 0; i < n; i++)
	{
		//hash[A[i]].insert(i);
		q.push(A[i]);
	}
		
/*	
	while (q.size()>0)
	{
		int a = q.top();
		cout <<a<<" ";
		q.pop();
	}
	*/
	while (sum > target)
	{
		int tem = q.top();
		q.pop();
		tem /= 2;
		q.push(tem);
		sum -= tem;
		res++;
	}
	return res;
}

int main()
{
	vector<int>  A = { 5,19,8,1 };
	cout<<solution(A);
}

