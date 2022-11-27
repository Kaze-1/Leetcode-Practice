#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int solution0(vector<int>& A) {
    //错解 考虑不周全
    // write your code in C++14 (g++ 6.2.0)
    int maxVal = *max_element(A.begin(), A.end());
    if (maxVal < 1)return 1;
    else return maxVal + 1;


}

//通过所有测试        也考虑使用一遍哈希，但是需要先排序O(nlogn)，时间复杂度还不如两遍哈希
int solution1(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    //哈希表解法 ；两遍哈希     
    int maxVal = *max_element(A.begin(), A.end());
    if (maxVal < 1)return 1;
    unordered_map<int, int> hashTable;
    int i;
    for (i = 0; i < A.size(); i++)
    {
        hashTable[A[i]] = 1;
    }
    for (i = 1; i <= maxVal; i++)
    {
        if (hashTable[i] == 0)return i;
    }
    return maxVal + 1;
    
}

int main()
{

}