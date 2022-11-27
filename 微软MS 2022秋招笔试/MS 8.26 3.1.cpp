//再改进?

//但不知为什么不认我的priority队列

#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;

int solution(vector<int>& A, vector<int>& B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size(), i, j;
    int A_MAX = INT_MIN, A_MIN = INT_MAX;
    for (i = 0; i < n; ++i)
    {
        if (A[i] < A_MIN)A_MIN = A[i];
        if (A[i] > A_MAX)A_MAX = A[i];
    }
    int B_MAX = INT_MIN, B_MIN = INT_MAX;
    for (i = 0; i < n; ++i)
    {
        if (B[i] < B_MIN)B_MIN = B[i];
        if (B[i] > B_MAX)B_MAX = B[i];
    }
    if (A_MIN > 1 || B_MIN > 1)return 1; //返回1的所有情况
    priority_queue<int, vector<int>,less<int>> Q;
    for (i = 0; i < n; ++i)
        if (A[i] != B[i])
        {
            Q.push(A[i]);
            Q.push(B[i]);
        }
    if (Q.size() == 0)//A B完全一致
    {
        return A_MAX + 1;
    }
    /*
    while (Q.size() > 1)
        Q.pop();
    */
    return Q.top();
    //unordered_map<int,int>
}


int main()
{
    //vector<int>A = { 1,2,4,3 };
    vector<int>A = { 3,2,1,6,5 };

    //vector<int>B = { 1,3,2,3 };
    vector<int>B = { 4,2,1,3,3};
    cout<<solution(A, B);
}