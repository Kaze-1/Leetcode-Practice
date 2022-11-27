#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

//改用set和哈希表
//每次答案都对但就是说超时！！！！

int getAns(int k, multiset<int>Set)
{
    // vector<int>Set(n + 1, 0);       //多重集的数据结构 记录集合中每个元素个数

    int K = k, i, j, n, Min = 0;
    while (K--)
    {
        n = Set.size();
        int Max = *Set.rbegin();//集合中最后一个元素为最大值
        if (Set.find(0) !=Set.end())
        {
            for (i = 1; i < INT_MAX; i++)
                if (Set.count(i) == 0) { int Min = i; break; }
        }
        int key = ceil((Max + Min) / 2);
        Set.insert(key);
    }
    return Set.size();// accumulate(Set.begin(), Set.end(), 0);

}

int main()
{
    int t, i, j; cin >> t;
    for (i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        //vector<int>Set(n + 1, 0);
        multiset<int>Set;
        for (j = 0; j < n; j++)
        {
            int tem; cin >> tem;
            Set.insert(tem);
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