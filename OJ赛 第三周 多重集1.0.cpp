#include<bits/stdc++.h> 

using namespace std;

int getAns(int n, int k, vector<int>Set)
{
   // vector<int>Set(n + 1, 0);       //多重集的数据结构 记录集合中每个元素个数
    int K = k,i,j;
    while (K--)
    {
        int Max = 1,Min=n;
        for(i=n;i>=1;i--)
            if (Set[i]) { Max = i; break; }
        for (i = 1; i <= n; i++)
            if (Set[i]==0) { Min = i; break; }
        Set[ceil((Max + Min) / 2)]++;
    }
    return accumulate(Set.begin(), Set.end(), 0);
}

int main()
{
    int t, i, j; cin >> t;
    for (i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int>Set(n + 1, 0);
        for (j = 0; j < n; j++)
        {
            int tem; cin >> tem;
            Set[tem] = 1;
        }
        cout << getAns(n, k, Set) << endl;
    }


    return 0;
}

/*
2
2 7
0 1
2 5 
0 1
6 7
4 5 3 0 2 1

*/