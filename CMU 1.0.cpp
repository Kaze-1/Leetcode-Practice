#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF



int solution(const string& S) {
    int n = S.size(),i,j;
    vector<int> res(n + 1);

    // 初始化表
    res[0] = 0;
    for (int i = 1; i <= n; i++) 
        res[i] = INT_MAX;

    // 填表
    for (i = 1; i <= n; ++i) 
    {
        unordered_set<char> record;
        for (j = i - 1; j >= 0; --j) 
        {
            if (record.count(S[j]) > 0) 
            {
                break;
            }
            record.insert(S[j]);
            res[i] = min(res[i], res[j] + 1);
        }
    }
    return res[n];
}

int main() {
    string s = "abba";
    cout << solution(s) << endl;

    return 0;
}
