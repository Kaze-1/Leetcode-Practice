/*
讨论区正解
排序后修改
每个数修改成[1,n]序列中下标相同的数改动就是最小的
可以反证法证明！
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


using namespace std;

int main() {
    int n, ans = 0;;
    cin >> n;
    vector<int>que(n, 0);
    for (int i = 0; i < n; ++i) cin >> que[i];
    sort(que.begin(), que.end());
    for (int i = 1; i <= n; ++i) {
        ans += abs(i - que[i - 1]);
    }
    cout << ans;
    return 0;
}