#include<bits/stdc++.h>
using namespace std;

// 由于这里N的设置，无法满足题目要求的n<=1e5的数据规模！！（尽管算法本身可行）
static const int N = 20000;//初始值设置足够大即可
//vector<vector<int>>G(N, vector<int>(N));
int G[N][N] = { 0 };
//vector<int>con(N);
int con[N] = { 0 };
bool visited[N] = { false };


void DFS(int n,int u,int id) {
    if (visited[u] == 0)
    {
        con[id]++;
        visited[u] = true;             //DFS核心就是标记visited
        for (int v = 0; v < n; v++) {
            if (G[u][v] != 0 && !visited[v])
                DFS(n,v,id);
        }
    }

}

int countComponents(int n, vector<vector<int>>& edges) {
        //memset(G, 0, sizeof G);
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1];
            G[u][v] = G[v][u] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
           // int tem = 0;
            if (!visited[i]) {
                DFS(n,i,res);
                res++;
             //   tem++;
            }
           //con.push_back(tem);
        }
        return res;
    }



long long countPairs(int n, vector<vector<int>>& edges) {
    //vector<vector<int>> con = getConnected(n, edges);
    //int m = con.size();//多少个分支
    vector<vector<int>>M(n, vector<int>(n));//n*n矩阵

    //getConnected(n, edges);
    int m = countComponents(n, edges);
    int i, j;
    long long res = 0;
    for (i = 0; i < m - 1; i++)
        for (j = i + 1; j < m; j++)
            res += con[i] * con[j];
    return res;
}

int main()
{
    int n = 7;
    vector<vector<int>>edges = { {0, 2},{0, 5},{2, 4},{1, 6},{5, 4} };
    cout<<countPairs(n, edges);
}