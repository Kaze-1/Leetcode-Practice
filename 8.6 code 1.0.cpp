// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string& S, int B) {
    // write your code in C++ (C++14 (g++ 6.2.0))  
    int n = S.length();
    vector<vector<int>>dp(n, vector<int>(B + 1));
    int i, j, Max = 0, flag = 0;
    for (i = 0; i < n; ++i)
        for (j = 1; j <= B; ++j)
        {
            if (i == 0)
            {
                if (S[i] == '.')
                {
                    dp[i][j] = 0; flag = 0;
                }
                else if (S[1] != 'x' && j < 2)
                {
                    dp[i][j] = 0; flag = 1;
                }
                else
                {
                    dp[i][j] = 1; flag = 1;
                }
            }
            else if (S[i] == '.') { dp[i][j] = dp[i - 1][j]; flag = 0; }
            else
            {
                if (flag == 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
                else
                {
                    if (j > 1)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 2] + 1);
                    else dp[i][j] = dp[i - 1][j];
                    flag = 1;
                }
            }
            if (dp[i][j] > Max)Max = dp[i][j];
            if(Max == 5)
                  cout << i << " " << j<<endl;
        }
    return Max;
}

int main()
{
    string s = "...xxx..x....xxx";
    int B = 7;
    cout << solution(s, B);
    
}