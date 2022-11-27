/*
http://www.k6k4.com/blog/show/aaawcsdra1528985482372
��vector(��ռ�)���е�DFS
DFS/BFS��һ���Ƕ�ͼ���ԣ�����������ĳ���漰��������Ľⷨ

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
//���ߵ�ǰ��װ�������sum����DFS������sum<��ֵw
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