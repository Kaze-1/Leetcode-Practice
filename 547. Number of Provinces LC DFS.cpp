/*
������DFS ���ǲ��ɹ�
������û��ʶ�������״�����ӹ�ϵ

�������Լ���DFSд���ˣ�DFS����Ҫ�ݹ�����Լ��������DFS
*/

#include<bits/stdc++.h>
#include<vector>

using namespace std;


void dfs(vector<vector<int>>& isConnected, int start, vector<int>&flags)
{
    int i;
    bool not_counted = 1;
    int n = isConnected.size();
    flags[start] = 1;
    for (i = 0; i < n; i++)
    {
        if (isConnected[i][start] && flags[i] == 0)
        {
            dfs(isConnected, i, flags);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int i, res = 0, j;
    int n = isConnected.size();
    vector<int> flags(n);
    for (i = 0; i < n; i++)
    {
        if (flags[i] == 1)continue;
        dfs(isConnected, i, flags);
        res++;
    }
    return res;

}

    
int main()
{
    //vector<vector<int>> test = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
    //[[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]
    vector<vector<int>> test = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
    vector<vector<int>> test2 = { {1, 0, 0, 1},{0, 1, 1, 0},{0, 1, 1, 1},{1, 0, 1, 1} };
    cout << findCircleNum(test) << endl;
    //cout << b << endl;
}


