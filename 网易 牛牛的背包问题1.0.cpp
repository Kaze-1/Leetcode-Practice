/*
http://www.k6k4.com/blog/show/aaawcsdra1528985482372
对vector(解空间)进行的DFS
DFS/BFS不一定是对图而言，可以是任意某个涉及遍历问题的解法

*/


#include<bits/stdc++.h>
using namespace std;
long ans = 0;
int n;
long w;
vector<long>value;
void dfs(long sum, int loc);
int main()
{
    cin >> n >> w;
    long total = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        value.push_back(b);
        total += value[i];
    }
    if (total <= w)
        ans = pow(2, n);
    else {
        sort(value.begin(), value.end());
        dfs(0, 0);
    }
    cout << ans << endl;
    return 0;
}
//带者当前已装载总体积sum进行DFS，保持sum<阈值w
void dfs(long sum, int loc)
{
    if (sum > w)
        return;
    if (sum <= w) {
        ++ans;
    }
    for (int i = loc; i < n; ++i) {
        dfs(sum + value[i], i + 1);
    }
}

/*
3 10
1 2 4

8
*/