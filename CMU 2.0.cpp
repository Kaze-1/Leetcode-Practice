#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF


const int MAX_N = 100;



int solution(int N, vector<int>& A, vector<int>& B) {
    // Initialize the DP table
    
    unordered_map<int, vector<int>> adj;
    //int dp[MAX_N + 1][MAX_N + 1];
    vector<vector<int>>dp(N, vector<int>(N));
    int i, j,M=A.size();

    for (i = 0; i < M; ++i)
    {
        adj[A[i]].emplace_back(B[i]);
        adj[B[i]].emplace_back(A[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = -1;           //Î´±»¼ÆËãÐ´³É0
        }
    }

    // Fill in the DP table
    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            int max_val = 0;
            for (int k : adj[i]) {
                max_val = max(max_val, dp[j][k]);
            }
            dp[i][j] = max_val + i * j;
        }
    }

    // Return the final result
    int res = 0;
    for (int i = 1; i <= N; ++i)
        res = max(res, dp[1][i]);
    return res;
}

int main() {
    int N = 5;
    vector<int>A = { 2,2,1,2 };
    vector<int>B = { 1,3,4,4};
    cout << solution(5, A, B);

    return 0;
}
