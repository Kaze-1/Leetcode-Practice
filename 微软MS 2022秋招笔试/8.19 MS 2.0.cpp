/*
（其实题目换成任意字符的字符串也是可以同理做的）
贪心算法：
先排序

（所有数不一样的情况特殊处理？）

从数目>=2的较大数开始，放第一个和最后一个，直到所有剩余值都不重复
再从不重复的值里取最大的

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
    sort(s.rbegin(), s.rend());//逆序排序
    if (*s.begin() == *(s.end()-1) && *s.begin() == '0')return "0"; //考虑全0的情况
    //hash计数
    unordered_map<char, int>hash;
    for (i = 0; i < n; ++i)
        if (hash.find(s[i]) == hash.end())
            hash[s[i]] = 1;
        else ++hash[s[i]];
    string res="";
    char unique = '0';//结果中间的char
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
    sort(s.rbegin(), s.rend());//逆序排序
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