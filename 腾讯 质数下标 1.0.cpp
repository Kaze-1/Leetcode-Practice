#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;

unordered_map<int, int>primeList;


bool firstPrimeJudge(int num)
{
    if (primeList[num])
        return 1;
    if (num == 1)
    {
        primeList[num] = 0;
        return 0;
    }
    int sqr = sqrt(num);
    for (int i = 2; i <= sqr; i++)
        if (num % i == 0)
        {
            primeList[num] = 0;
            return 0;
        }
    primeList[num] = 1;
    return 1;
}

int getNumber(vector<int>& a) {
    // write code here
    int N = a.size()+1,n= a.size();
    int i;
    for (i = 0; i < N; i++)
        firstPrimeJudge(i+1);
    vector<int>lastNums = a;
    vector<int>nums;
    do {
        nums.clear();
        for (i = 0; i < n; i++)
            if (primeList[i + 1])
                nums.push_back(lastNums[i]);
        lastNums = nums;
        n= lastNums.size();
    } while (nums.size() != 1);
    return nums[0];
}

int main()
{
    vector<int>a = { 3,1,1,4,5,6 };
    vector<int>a1 = { 1,2,3,4 };

    cout<<getNumber(a1);
}