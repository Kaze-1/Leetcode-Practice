#include<bits/stdc++.h> 
#include<unordered_map>  

using namespace std;

//改用set和哈希表

int getAns(int k, set<int>Set,unordered_map<int,int>hash)
{
    // vector<int>Set(n + 1, 0);       //多重集的数据结构 记录集合中每个元素个数

    int K = k, i, j, n,Min=0;
    while (K--)
    {
        n = Set.size();
        int Max = *max_element(Set.begin(), Set.end());
        if(Set.count(0)>0) 
        {
            for (i = 1; i < INT_MAX; i++)
                if (Set.count(i) == 0) { int Min = i; break; }
        }
        int key = ceil((Max + Min) / 2);
        Set.insert(key);
        hash[key]++;
    }
    n = hash.size();
    int res = 0;
    for (i = 0; i <= n; i++)
        if (hash.count(i))res += hash[i];
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
        set<int>Set;
        unordered_map<int, int>hash;
        for (j = 0; j < n; j++)
        {
            int tem; cin >> tem;
            Set.insert(tem);
            hash[tem] = 1;
        }
        cout << getAns(k, Set, hash) << endl;
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