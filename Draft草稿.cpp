#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF


//std::ios::sync_with_stdio(false); //д��main�����

//c++ ��split����
void Stringsplit(string str, const const char split)
{
	istringstream iss(str);	// ������
	string token;			// ���ջ�����
	while (getline(iss, token, split))	// ��splitΪ�ָ���
	{
		cout << token << endl; // ���
	}
}
