#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



vector<int> binarySearch(vector<int>index, int target, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        if (index[mid] == target)return { mid,mid };
        else if (index[mid] > target)
            return binarySearch(index, target, low, mid - 1);
        else return binarySearch(index, target, mid + 1, high);
    }
    return { low,high };
}

vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>>hash;
    int n = colors.size();
    int m = queries.size();
    int i;
    for (i = 0; i < n; i++)
        hash[colors[i]].emplace_back(i);
    for (auto e : hash)
        sort(e.second.begin(), e.second.end());  //注意这里遍历std::map的方式
    for (i = 0; i < m; i++)
    {
        int firstColor = queries[i][0];
        for (auto index : hash[firstColor])

    }

}