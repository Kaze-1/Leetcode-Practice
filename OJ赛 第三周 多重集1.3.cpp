#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

//����set�͹�ϣ��
//ÿ�δ𰸶��Ե�����˵��ʱ��������

int getAns(int k, multiset<int>Set)
{
    // vector<int>Set(n + 1, 0);       //���ؼ������ݽṹ ��¼������ÿ��Ԫ�ظ���

    int K = k, i, j, n, Min = 0;
    while (K--)
    {
        n = Set.size();
        int Max = *Set.rbegin();//���������һ��Ԫ��Ϊ���ֵ
        if (Set.find(0) !=Set.end())
        {
            for (i = 1; i < INT_MAX; i++)
                if (Set.count(i) == 0) { int Min = i; break; }
        }
        int key = ceil((Max + Min) / 2);
        Set.insert(key);
    }
    return Set.size();// accumulate(Set.begin(), Set.end(), 0);

}

int main()
{
    int t, i, j; cin >> t;
    for (i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        //vector<int>Set(n + 1, 0);
        multiset<int>Set;
        for (j = 0; j < n; j++)
        {
            int tem; cin >> tem;
            Set.insert(tem);
        }
        cout << getAns(k, Set) << endl;
    }


    return 0;
}

/*
3
2 7
0 1
2 5
0 1
6 7
4 5 3 0 2 1

*/