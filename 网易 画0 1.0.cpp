#include <bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF

int main() {
    int n; cin >> n;
    vector<vector<char>>res(4 * n, vector<char>(4 * n));
    int i, j;
    //只计算上半部分
    for (i = 0; i < n; i++)//顶部
        for (j = 0; j < 4 * n; j++)
        {
            if (j < n-i || j >= 4*n-(n-i))res[i][j] = '.';
            else res[i][j] = '*';
        }
    for (i = n; i < 2*n; i++)//中部
        for (j = 0; j < 4 * n; j++)
        {
            if (j < n || j >= 3 * n)res[i][j] = '*';
            else res[i][j] = '.';
        }
    //再对称
    for (i = 2 * n; i < 4 * n; i++)
        for (j = 0; j < 4 * n; j++)
            res[i][j] = res[4*n-1 - i][j];
    for (i = 0; i < 4 * n; i++)
    {
        for (j = 0; j < 4 * n; j++)
            cout << res[i][j];
        cout << endl;
    }
        

}
// 64 位输出请用 printf("%lld")