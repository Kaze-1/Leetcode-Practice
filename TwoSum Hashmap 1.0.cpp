/*
https://leetcode.com/problems/two-sum/
*/

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    int i;
    unordered_map<int, int> hashMap;
    vector<int>res;
    for (i = 0; i < nums.size(); i++)
        hashMap[nums[i]] = i;

    for (i = 0; i < nums.size(); i++)
        if(hashMap.find(target - nums[i])!=hashMap.end()&& hashMap[target - nums[i]] !=i)
        { 
            res.push_back(hashMap[target - nums[i]]);
            res.push_back(i);
            return res;
        }          
    return {};
}

int main()
{
    vector<int> nums= {3, 2, 4};
    int target = 6;
    //vector<int> res = twoSum(nums, target);
    cout << twoSum(nums, target)[0]<<" " << twoSum(nums, target)[1];
}