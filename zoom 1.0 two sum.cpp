#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>res;
    for (int i = 0; i < nums.size(); i++)
        for (int j = i; j < nums.size(); j++)
            if (nums[j] + nums[i] == target && i != j)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }

    return {};
}

int main()
{
    int target, n;
    vector<int>nums;
    cin >> target>>n;
    while (n--)
    {
        int tem; cin >> tem;
        nums.push_back(tem);
    }
    vector<int>res = twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}