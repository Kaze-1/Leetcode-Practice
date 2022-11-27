#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();//行数    
    int n = matrix[0].size();//列数
    int top = 0, bottom = m - 1, left = 0, right = n - 1, i, j;
    vector<int>res;
    while (bottom >= top && right >= left)//循环继续条件：严格大于
    {
        for (i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        top++;
        for (i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        right--;
        for (i = right; i >= left; i--)
            res.push_back(matrix[bottom][i]);
        bottom--;
        for (i = bottom; i >= top; i--)
            res.push_back(matrix[i][left]);
        left++;
    }
    while (res.size() > m * n)
        res.pop_back();
    return res;
}

vector<int> printMatrix(vector<vector<int>> matrix)
{
    int m = matrix.size();//行数    
    int n = matrix[0].size();//列数
    //用拷贝构造函数初始化flags为m*n 全为0的矩阵 
    vector<vector<int>> flags(m, vector<int>(n));
    int status = 0;//记录当前节点的状态（移动方向 0->1->2->3）
    int num, i = 0, j = 0;
    vector<int>res;
    for (num = 0; num < m * n; num++)
    {
        //访问:打印，标记
        res.push_back(matrix[i][j]);
        flags[i][j] = 1;

        if ((j == n - 1 || (j!=n-1&&flags[i][j + 1])) && status == 0)//边界处理部分 更正flags
            status++;
        else if ((i == m - 1 || (i!=m-1&&flags[i + 1][j])) && status == 1)
            status++;
        else if ((j == 0 || (j!=0&& flags[i][j - 1])) && status == 2)
            status++;
        else if ((i == 0 || (i!=0&&flags[i - 1][j])) && status == 3)
            status = 0;
        //移动部分 
        if (status == 0)
            j++;
        else if (status == 1)
            i++;
        else if (status == 2)
            j--;
        else if (status == 3)
            i--;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9 }};
    vector<int> res= spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++)
        cout << res[i]<<" ";
} 