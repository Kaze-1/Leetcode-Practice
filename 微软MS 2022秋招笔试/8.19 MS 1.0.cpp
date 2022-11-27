#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

/*
测试集都通过
*/
int solution(vector<int>& X, vector<int>& Y, int W) {
	// write your code in C++ (C++14 (g++ 6.2.0))
	vector<int>X1 = X;
	set<int>s(X1.begin(), X1.end());
	X1.assign(s.begin(), s.end());
	int res = 1;
	int last = X1[0];
	for (int i = 1; i < X1.size(); ++i)
	{
		if (last + W < X1[i])
		{
			last = X1[i];
			res++;
		}
	}
	return res;
}


int main()
{
	//vector 去重
	/*vector<int>vec = {1,1,11,2,1};
	set<int>s(vec.begin(), vec.end());
	vec.assign(s.begin(), s.end());
	
	for (auto e : vec)
		cout << e << " ";*/
	vector<int>X = { 2,4,2,6,7,1 };
	vector<int>Y = { 0,5,3,2,1,5 };
	int W = 2;
	cout << solution(X, Y, W);
}