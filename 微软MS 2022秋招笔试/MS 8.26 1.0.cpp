#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF		//也可LONG_MAX, LONG_MIN, INT_MAX,INT_MIN

//错误的dp
int solution(string& S) {
	// write your code in C++ (C++14 (g++ 6.2.0))
	int n = S.size();
	vector<int>dp(n);
	unordered_map<char, int>total;
	unordered_map<char, int>occur;

	for (char e : S)
		if (total.find(e) == total.end())total[e] = 1;
		else ++total[e];
	for (int i=1;i<n;++i)
	{
		if (total[S[i]] % 2 == 0)dp[i] = dp[i - 1] + 1;
		else
		{
			if (occur.find(S[i]) == occur.end())occur[S[i]] = 1;
			else ++occur[S[i]];
			if (occur[S[i]] < total[S[i]])dp[i] = dp[i - 1] + 1;
			else dp[i] = dp[i - 1];
		}	
	}
	return dp[n-1]+1;
}


int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	//string s = "zthtzh";
	string s = "aaadad";

	cout << solution(s);
	
}