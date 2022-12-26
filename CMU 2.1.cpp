#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF


int solution(int N, std::vector<int>& A, std::vector<int>& B) {
    int M = A.size();

    // Create a 2D array to store the maximum possible sum of values of the edges' endpoints for each vertex and value
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
    //dp[0][0] = 0;

    // Iterate over the edges in the graph
    for (int k = 0; k < M; ++k) {
        int u = A[k];
        int v = B[k];

        for (int j = 1; j <= N; ++j) {
                dp[v][j] = std::max(dp[v][j], dp[u][j] + j);
                dp[u][j] = std::max(dp[u][j], dp[v][j] + j);
        }
    }

    // Find the maximum possible sum of values of the edges' endpoints
    int max_sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            max_sum = std::max(max_sum, dp[i][j]);
        }
    }

    return max_sum;
}



int main() {
    int N = 5;
    vector<int>A = { 2,2,1,2 };
    vector<int>B = { 1,3,4,4 };
    cout << solution(N, A, B);

    return 0;
}
