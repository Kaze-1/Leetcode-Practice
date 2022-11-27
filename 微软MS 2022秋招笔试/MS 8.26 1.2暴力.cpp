#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF		//也可LONG_MAX, LONG_MIN, INT_MAX,INT_MIN

int check(string S)
{
	unordered_map<char, int>occur;
	
	for(int i=0;i<S.size(); i++)
		if (occur.find(S[i]) == occur.end())occur[S[i]] = 1;
		else ++occur[S[i]];
	for (int i = 0; i < S.size(); i++)
		if (occur[i] % 2 == 1)return 0;
	return S.size();
}

int solution(string& S) {
	// write your code in C++ (C++14 (g++ 6.2.0))
	int n = S.size();
	int i = 0, j = 1;
	unordered_map<char, int>occur;
	unordered_map<char, int>total;
	/*
	for (char e : S)
		if (total.find(e) == total.end())total[e] = 1;
		else ++total[e];	*/
	int res = 0;


	for (i = 0; i < n - 1; i++)
	{
		//if (occur.find(S[i]) == occur.end())occur[S[i]] = 1;
		//else ++occur[S[i]];
		for (j = i + 1; j < n; j++)
		{
			if (j - i == 0 || (j - i) % 2 == 1)continue;
			int tem = check(S.substr(i, j - i + 1));
			res = tem > res ? tem : res;
		}
	}
	return res;


	/*
	while (j <= n - 1&&i<=n-2)
	{
		/*
		if (occur.find(S[i]) == occur.end())occur[S[i]] = 1;
		else ++occur[S[i]];
		if (occur.find(S[j]) == occur.end())occur[S[j]] = 1;
		else ++occur[S[j]];

	}
	*/
}


int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	//string s = "zthtzh";
	string s = "aaadad";

	cout << solution(s);
}

