/*
* ÿ���ڵ��������һ����Ҷ�ӽڵ�
* 
��ģ���˼��(��֪�Ƿ�����)
���յ�0�ľ����������(dijstra? ���߰���Ŀ��0��ʼBFS)
����Զ��(��Ե)�ڵ㿪ʼ����Ȧ�ڵ��£
ֱ�������˾�£��0Ϊֹ
�ڼ�res++



ʱ�䲻��������

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
    vector<vector<int>> graph(n);   //ͼ(�ڽӱ�)  ��n+1���ڵ㣬1~n�����ӺͰ칫��(0)�������Ϊn
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
       
    //for (auto e : rank)       //��Ҫ����һ����������ݽṹ�����ڵ����rank����Ȼ���rank�ߵĽڵ㿪ʼ����
    //    cout << e << " ";
    /*unordered_map<int, int>hash;
    for (int i = 0; i < n; ++i)
        hash[i] = rank[i];
        */
    vector<vector<int>>nodeRank;
    fill(visited.begin(), visited.end(), 0);        //��vector���ó�0����췽��
    priority_queue<vector<int>>Queue;
    for (i = 0; i < n; ++i)
    {
        Queue.push(vector<int>{rank[i],i});
    }
    //sort(nodeRank.begin(), nodeRank.end());     //�Զ�άvector��Ƕ������������ʱ��Ĭ�ϸ���ÿ��vector���������ĵ�һ��ֵ����
    
    int finalRes = 0;
    while(Queue.size()>0)//����ĩ�˵Ľڵ㵯�� ���м���...
    {
        auto e = Queue.top();
        Queue.pop();
        //e��rank��һ�������ڽڵ��ۣ�finalRes++
        //cout << e[0] << " " << e[1] <<endl;
    }
   
    

    
    
    

    return 0;
}


int main()
{
    std::ios::sync_with_stdio(false); //д��main�����
    //vector<int>A = { 0,1};
   //vector<int>B = { 1,2};
    vector<int>A = { 0,1,1};
    vector<int>B = { 1,2,3 };
    solution(A, B);
    //cout << solution(A, B) << endl;

    string s;
    getline(cin, s);
}