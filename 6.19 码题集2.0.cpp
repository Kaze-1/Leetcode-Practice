#include<bits/stdc++.h> 

using namespace std;

//数学原理就是排序不等式，排序后从小的开始合并就行！
int main()
{
    int n, i; cin >> n;
    vector<int>cargo(n);
    for (i = 0; i < n; i++)
        cin >> cargo[i];
    if (n == 1)
    {
        cout << cargo[0]; return 0;
    }
    sort(cargo.begin(), cargo.end());
    vector<int>rec(0);
    int sum = cargo[0]+ cargo[1];
    rec.push_back(sum);
    for (i = 2; i < n; i++)
    {
        sum += cargo[i];
        rec.push_back(sum);
    }
    cout << accumulate(rec.begin(), rec.end(),0);
    //cout << sum;
    return 0;
}


/*
3
1 2 3

9
*/