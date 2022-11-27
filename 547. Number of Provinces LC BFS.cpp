/*
����BFS
ÿ��BFS������ÿһ��province��ȫ���ڵ㶼��ջ������Ƿ��ʹ���province++
����һ��δ���ʹ��ĵ㿪ʼ
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

void bfs(vector<vector<int>>& isConnected, int start, vector<int>& flags)
{
    int i, j;
    int n = isConnected.size();
    vector<int>Neighbors;
    Neighbors.push_back(start);
    while (Neighbors.size() > 0)
    {
        int newN = Neighbors.back();
        Neighbors.pop_back();
        flags[newN] = 1;
        for (j = 0; j < n; j++)
            if (isConnected[newN][j] && flags[j] == 0)
            {
                Neighbors.push_back(j);
            }
    }
}
   

int findCircleNum(vector<vector<int>>& isConnected) {
    int i, res = 0,j;
    int n = isConnected.size();
    vector<int> flags(n);
    for (i = 0; i < n; i++)
    {
        if (flags[i] == 1)continue;
        bfs(isConnected,i,flags);
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


