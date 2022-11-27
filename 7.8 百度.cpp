#include<bits/stdc++.h> 

using namespace std;

int main()
{
    int i, m, n;
    cin >> n >> m;
    vector<double>nums(n);
    for (auto& e : nums)
        cin >> e;
    vector<float>dp(n);
    float sum = 0;
    for (i = 0; i < m; i++)
        sum += nums[i];
    dp[m - 1] = (sum + 0.0) / n;

    for (i = m; i < n; i++)
    {
        float tem = dp[i - 1] + (nums[i] - nums[i - m] + 0.0 / m);
        if (tem > dp[i - 1])dp[i] = tem;
        else dp[i] = dp[i - 1];
    }
    cout << floor(*max_element(dp.begin(), dp.end()) * 1000);
    return 0;
}