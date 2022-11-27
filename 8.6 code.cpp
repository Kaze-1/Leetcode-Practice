#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int Ask(string a, string b) {
    int ans = 0;
    while (!a.empty()) {
        int pos = b.rfind(a.back());
        ans += ((int)b.size() - pos - 1);
        a.pop_back();
        b.erase(b.begin() + pos);
    }
    return ans;
}
int getMinSwaps(string num, int k) {
    string target(num);
    while (k--) {
        next_permutation(target.begin(), target.end());
    }
    return Ask(target, num);

}

bool solution(vector<int>& A, vector<int>& B, int S) {
    
}


bool solution2(vector<int>& A, vector<int>& B, int S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int i, j, n = A.size();
    if (S < n)return false;
    // vector<vector<bool>>dp(n+1,vector<int>(2));
    // for(i=1;i<=n;++i)
    //     for(j=0;j<2;++j)
    //     {
    //         dp[i][j]=true
    //     }
    // 直接模拟法     
    unordered_map<int, int>hashRes;    //哈希表 解 哪个时段-哪个人
    for (i = 0; i < n; ++i)
    {
        if(hashRes.find(A[i])==hashRes.end())
            hashRes[A[i]] = i;
        else
        {
            if (B[i] == A[i])return false;
            hashRes[B[i]] = i;
        }
    }
    if (hashRes.size() == S) return true;
    else return false;

}

int main()
{
    vector<int>A = { 2,5,6,5 };
    vector<int>B = { 5,4,2,2 };
    int S = 8;
    cout << solution(A, B, S);
}