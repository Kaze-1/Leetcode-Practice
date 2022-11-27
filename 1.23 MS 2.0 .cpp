#include<bits/stdc++.h>
using namespace std;
#define INF 0x7FFFFFFF 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//机器人顺时针走 状态dir:0,1,2,3表示现在前进方向，遇到障碍后更新dir

//map[N][M]:-1,0,1 标记是否清理过,-1是障碍物
//res 不断更新
//大循环 重复N*M次，最后输出res肯定不会再更新
int solution(vector<string>& R) {
    // write your code in C++14 (g++ 6.2.0)
    int N = R.size();
    int M = R[0].size(), i, j;
    vector<vector<int>>map(N, vector<int>(M, 0));
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (R[i][j] == 'X')map[i][j] = -1;
    /*
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }*/
     
    // vector<vector<int>>flag=map;
    int dir = 0, MAX_TIMES = N * M, res = 0;
    i = j = 0;//机器人位置指针
    while (MAX_TIMES--)
    {
        if (map[i][j] == 0)//未清理 
            map[i][j] = 1, res++;
        bool obs_flag = 0;
        //判断前方是否有障碍物
        do {
            if (dir == 0 && (j == M - 1 || map[i][j + 1] == -1))
                obs_flag = 1;
            else if (dir == 1 && (i == N - 1 || map[i + 1][j] == -1))
                obs_flag = 1;
            else if (dir == 2 && (j == 0 || map[i][j - 1] == -1))
                obs_flag = 1;
            else if (dir == 3 && (i == 0 || map[i - 1][j] == -1))
                obs_flag = 1;
            else obs_flag = 0;
            if (obs_flag)dir = (dir + 1) % 4;//更新dir
        } while (obs_flag&&N*M>1);//排除只有一个方块的情况

        //移动机器人
        if (dir == 0)j++;
        if (dir == 1)i++;
        if (dir == 2)j--;
        if (dir == 3)i--;

    }
    return res;
}


int main()
{
    //vector<string> R = { "...X..","....XX","..X..."};
    vector<string> R = { "." };
    cout << solution(R);
}