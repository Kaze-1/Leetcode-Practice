#include<bits/stdc++.h> 
#include<map> 

using namespace std;

//改用map做数据结构(红黑树)

int getAns(int k, map<int, int>Set)
{
    // vector<int>Set(n + 1, 0);       //多重集的数据结构 记录集合中每个元素个数
    
    int K = k, i, j,n;
    while (K--)
    {
        n = Set.size();
        int Max = 1, Min = n;
        for (i = n; i >= 0; i--)
            if (Set.count(i)&&Set[i]) { Max = i; break; }
       
        for (i = 0; i <= n; i++)
            if (Set.count(i)==0||Set[i] == 0) { Min = i; break; }
        Set[ceil((Max + Min) / 2)]++;
    }
    n = Set.size();
    int res = 0;
    for (i = 0; i <= n; i++)
        if (Set.count(i))res += Set[i];
    return res;// accumulate(Set.begin(), Set.end(), 0);
    
}

int main()
{
    int t, i, j; cin >> t;
    for (i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        //vector<int>Set(n + 1, 0);
        map<int, int>Set;   
        for (j = 0; j < n; j++)
        {
            int tem; cin >> tem;
            Set[tem] = 1;
        }
        cout << getAns(k, Set) << endl;
    }


    return 0;
}

/*
3
2 7
0 1
2 5
0 1
6 7
4 5 3 0 2 1

*/