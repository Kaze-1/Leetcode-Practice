#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <iostream>
#include <vector>

using namespace std;


long long numSnacks(int n, int w, const std::vector<int>& v) {
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(w + 1));
    
    //dp[0][0] = 1;//初始化有问题
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 0; i <= w; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = w; j>=0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - v[i - 1]];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::cout << numSnacks(n, w, v) << std::endl;
    return 0;
}


/*
3 10

1 2 4
*/
