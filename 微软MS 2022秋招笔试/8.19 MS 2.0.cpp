/*
����ʵ��Ŀ���������ַ����ַ���Ҳ�ǿ���ͬ�����ģ�
̰���㷨��
������

����������һ����������⴦����

����Ŀ>=2�Ľϴ�����ʼ���ŵ�һ�������һ����ֱ������ʣ��ֵ�����ظ�
�ٴӲ��ظ���ֵ��ȡ����

*/
#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

string solution(string& S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    string s = S;
    int n = S.length(),i;
    sort(s.rbegin(), s.rend());//��������
    if (*s.begin() == *(s.end()-1) && *s.begin() == '0')return "0"; //����ȫ0�����
    //hash����
    unordered_map<char, int>hash;
    for (i = 0; i < n; ++i)
        if (hash.find(s[i]) == hash.end())
            hash[s[i]] = 1;
        else ++hash[s[i]];
    string res="";
    char unique = '0';//����м��char
    bool flag = false;
    for (i = 0; i < n; ++i)
        if (hash[s[i]] >= 2&&s[i]!='0')
        {
            res = s[i] + res + s[i];
            hash[s[i]] -= 2;
        }
        else if (hash[s[i]] ==1)
        {
            flag = true;
            if (s[i] >= unique)
                unique = s[i];
        }
    if (flag)
    {
        n = res.size();
        res = res.substr(0, n / 2) + unique + res.substr(n / 2);
    }
    return res;
}

int main()
{
    string s = "0000";
    sort(s.rbegin(), s.rend());//��������
    string res = "1abbav";
    char unique='#';
    int n = res.size();
    res = res.substr(0, n / 2) + unique + res.substr(n / 2 );
    //for (auto e : res)
     //   cout << e << " ";
    
    cout<<solution(s);
    //set<int>Set(s.begin(), s.end());
    //s.assign(Set.begin(), Set.end());
    //for (auto e : s)
    //    cout << s << " ";
}