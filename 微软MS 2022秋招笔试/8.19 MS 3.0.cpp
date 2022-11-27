/*
* 每个节点最多连接一个非叶子节点
* 
用模拟的思想(不知是否最优)
按照到0的距离进行排序(dijstra? 或者按题目从0开始BFS)
从最远的(边缘)节点开始向内圈节点聚拢
直到所有人聚拢到0为止
期间res++



时间不够辣！！

*/

#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

void printGraph(vector<vector<int>> graph)
{
    int n = graph.size();
    for (auto e:graph)
    {
        for (auto Char:e)
            cout << Char << " ";
        cout << endl;
    }
}

int solution(vector<int>& A, vector<int>& B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size()+1,i;
    vector<vector<int>> graph(n);   //图(邻接表)  有n+1个节点，1~n个房子和办公室(0)，最大编号为n
    for (i = 0; i < n-1; ++i) {
        if (A[i] != B[i])graph[A[i]].emplace_back(B[i]);
        if (A[i] != B[i])graph[B[i]].emplace_back(A[i]);//?  
    }
   // printGraph(graph);
    queue<int>Q;
    Q.push(0);
    vector<int>rank(n);
    vector<bool>visited(n);
    int curRank = 0;
    while (Q.size() > 0)
    {
        int tem = Q.front();
        if (visited[tem] == false)
        {
            visited[tem] = true;
            bool flag = 0;
            for (auto e : graph[tem])
            {
                if (visited[e] == false)
                {
                    if (flag == 0)++curRank;
                    flag = 1;
                    rank[e] = curRank;
                    Q.push(e);
                }
            }   
 
        }
        Q.pop();
    }
       
    //for (auto e : rank)       //需要构造一个有序的数据结构，将节点根据rank排序，然后从rank高的节点开始遍历
    //    cout << e << " ";
    /*unordered_map<int, int>hash;
    for (int i = 0; i < n; ++i)
        hash[i] = rank[i];
        */
    vector<vector<int>>nodeRank;
    fill(visited.begin(), visited.end(), 0);        //将vector重置成0的最快方法
    priority_queue<vector<int>>Queue;
    for (i = 0; i < n; ++i)
    {
        Queue.push(vector<int>{rank[i],i});
    }
    //sort(nodeRank.begin(), nodeRank.end());     //对二维vector（嵌套容器）排序时，默认根据每个vector（容器）的第一个值排序
    
    int finalRes = 0;
    while(Queue.size()>0)//从最末端的节点弹出 向中间汇聚...
    {
        auto e = Queue.top();
        Queue.pop();
        //e向rank低一级的相邻节点汇聚，finalRes++
        //cout << e[0] << " " << e[1] <<endl;
    }
   
    

    
    
    

    return 0;
}


int main()
{
    std::ios::sync_with_stdio(false); //写在main函数里！
    //vector<int>A = { 0,1};
   //vector<int>B = { 1,2};
    vector<int>A = { 0,1,1};
    vector<int>B = { 1,2,3 };
    solution(A, B);
    //cout << solution(A, B) << endl;

    string s;
    getline(cin, s);
}