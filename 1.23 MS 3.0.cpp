#include<bits/stdc++.h>
using namespace std;

int solution1(vector<int>& H, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int> > dp(X+1, vector<int>(Y+1, 0));
    int i = 0, j = 0, total = (X+1)* (Y+1), k;
    while (total--)
    {
        for (i = 0; i <= X; i++)
            for (j = 0; j <= Y; j++)
            {
                int Max = -1;
                for (k = 0; k < H.size(); k++)
                {
                    int last1 = 0, last2 = 0;
                    if (i >= H[k]) last1 = dp[i - H[k]][j] + 1;
                    if (j >= H[k]) last1 = dp[i][j - H[k]] + 1;
                    int res = max(max(last1, last2), dp[i][j]);
                    if (res > Max)Max = res;
                }
                dp[i][j] = Max;
            }
    }
    int Max = -1;
    for (i = 0; i <= X; i++)
        for (j = 0; j <= Y; j++)
            if (dp[i][j] > Max)
                Max = dp[i][j];

    return Max;
}

int solution2(vector<int>& H, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int> > dp(X + 1, vector<int>(Y + 1, 0));
    int i = 0, j = 0, total = (X + 1) * (Y + 1), k;
    int n = H.size();

    vector<int>flag(n, 0);//标记这辆车生产过与否
    for (i = 0; i <= X; i++)
        for (j = 0; j <= Y; j++)
        {
            int Max = -1;
            for (k = 0; k < H.size(); k++)
            {
                int last1 = 0, last2 = 0;
                int upd_flag = 0;
                if (flag[k] == 0 && i >= H[k]) last1 = dp[i - H[k]][j] + 1, flag[k] = 1, upd_flag=1;
                else if (flag[k] == 0 && j >= H[k]) last2 = dp[i][j - H[k]] + 1, flag[k] = 1, upd_flag=1;
                else flag[k] = 0;//回溯
                //int res = max(max(last1, last2), dp[i][j]);
                int res;
                if (upd_flag) res = max(last1, last2);
                else res = 0;
                if (res > Max)Max = res;
            }
            dp[i][j] = Max;
        }
    return dp[X][Y];
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution_final(vector<int>& H, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    int n = H.size();
    vector<vector<int> > dp(X + 1, vector<int>(Y + 1, 0));
    int i = 0, j = 0, total = (X + 1) * (Y + 1), k;

    for (i = 0; i <= X; i++)
        for (j = 0; j <= Y; j++)
        {
            int Max = -1;
            for (k = 0; k < n; k++)
            {
                int last1 = 0, last2 = 0;
                if (i >= H[k]) last1 = dp[i - H[k]][j] + 1;
                if (j >= H[k]) last1 = dp[i][j - H[k]] + 1;
                //int res = max(max(last1, last2), dp[i][j]);
                int res = min(max(last1, last2), n);
                if (res > Max)Max = res;
            }
            dp[i][j] = Max;
        }

    /*
    int Max = -1;
    for (i = 0; i <= X; i++)
        for (j = 0; j <= Y; j++)
            if (dp[i][j] > Max)
                Max = dp[i][j];
                */

    return dp[X][Y];
}

//改良后版本
int solution(vector<int>& H, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    int n = H.size();
    vector<vector<vector<int>> > dp(n,vector<vector<int>>(X + 1, vector<int>(Y + 1, 0)));
    int i = 0, j = 0, k;

    for (k = 0; k <n; k++)
        for (i = 0; i <= X; i++)
            for (j = 0; j <= Y; j++)
            {
                int last1 = 0, last2 = 0;
                if (i >= H[k] && k > 0)last1 = dp[k - 1][i - H[k]][j] + 1;
                else if (i >= H[k] && k == 0) last1 = 1;
                if (j >= H[k]&&k>0)last2 = dp[k - 1][i][j - H[k]]+1;
                else if (j >= H[k] && k == 0) last2 = 1;
                if (k > 1)dp[k][i][j] = max(max(last1, last2), dp[k - 1][i][j]);
                else dp[k][i][j] = max(last1, last2);
            }
    return dp[n-1][X][Y];
}


int main()
{
    //[1, 1, 3], 1, 1
    //[6, 5, 2, 1, 8], 17, 5
    //[6,5,5,4,3],8,9
    //[5,5,4,6],8,8
    vector<int> H = { 5,5,4,6 };
    int X = 8;
    int Y = 8;
    cout << solution(H,X,Y);
}