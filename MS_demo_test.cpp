#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int solution0(vector<int>& A) {
    //��� ���ǲ���ȫ
    // write your code in C++14 (g++ 6.2.0)
    int maxVal = *max_element(A.begin(), A.end());
    if (maxVal < 1)return 1;
    else return maxVal + 1;


}

//ͨ�����в���        Ҳ����ʹ��һ���ϣ��������Ҫ������O(nlogn)��ʱ�临�ӶȻ����������ϣ
int solution1(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    //��ϣ��ⷨ �������ϣ     
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