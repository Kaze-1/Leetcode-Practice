#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF


//std::ios::sync_with_stdio(false); //写在main函数里！

//c++ 的split函数
void Stringsplit(string str, const const char split)
{
	istringstream iss(str);	// 输入流
	string token;			// 接收缓冲区
	while (getline(iss, token, split))	// 以split为分隔符
	{
		cout << token << endl; // 输出
	}
}
