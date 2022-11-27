/*
字典序处理方法：

直接模拟法是可行的，但是会超时(7/10)

宜使用其他的方法..改进
*/
#include<bits/stdc++.h> 

using namespace std;

bool isLower(deque<int> s1, deque<int> s2)
{
    int n = s1.size();
    while (n--&&s1.size()>0&&s2.size() > 0)
    {
        int n1 = s1.front(), n2 = s2.front();
        if (n1 < n2)return true;
        else if(n1 > n2)return false;
        else
        {
            s1.pop_front();s2.pop_front();     
        }
    }
    return false;
}

deque<int> Move(deque<int> s)
{
    int n = s.front();
    s.pop_front();
    s.emplace_back(n);
    return s;
}

int main()
{
     string s = "abcd";
     cout << Move(s);
    int N, i; cin >> N;
    deque<int> s;
    for (i = 0; i < N; i++)
    {
        int c; cin >> c;
        s.emplace_back(c);
    }
    deque<int> res = s;
    for (i = 0; i < N; i++)
    {
        s = Move(s);
        if (isLower(s, res))res = s;
    }
    for (i = 0; i < N; i++)
    {
        cout << res[i]<<" ";
    }
    return 0;
}