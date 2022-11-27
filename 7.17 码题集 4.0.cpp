/*
字典序处理方法：
*/
#include<bits/stdc++.h> 

using namespace std;

string Move(string s)
{
    char c = s[0];
    int n = s.length(), i;
    return s.substr(1, n - 1) + c;
}

int main()
{
    // string s = "abcd";
    // cout << Move(s);
    int N, i; cin >> N;
    string s = "";
    for (i = 0; i < N; i++)
    {
        char c; cin >> c;
        s += c;
    }
    string res = s;
    for (i = 0; i < N; i++)
    {
        string new_s = Move(res);
        if (new_s < res)res = new_s;
    }
    cout << res;
    return 0;
}