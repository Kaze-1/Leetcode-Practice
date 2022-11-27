#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;

int main()
{
    unordered_map<int,int>hash;
    int n, k,i;
    cin >> n >> k;
    vector<int>a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        if (hash.find(a[i]) == hash.end())
            hash[a[i]] = 1;
        else hash[a[i]]++;
    vector<tuple<int, int>>rec;
    for (i = 0; i < n; i++)
    {
        tuple<int, int>tem;
        tem = {a[i],i };
        rec.emplace_back(tem);
    }
    sort(rec.begin(),rec.end());
    set<int>res;
    for (i = n-1; i>=n-k; i--)
        res.insert(get<0>(rec[i]));
    int RES=0;
    for (i = 0; i < n; i++)
        if (res.find(a[i]) != res.end())RES++;
    
    cout << n -RES;
  
    
    return 0;
}