/* һά ��̬�滮  ֱ��˺��

��һ�Ź���
����һ��������ժˮ�� ������ժȡ������
*/

#include<bits/stdc++.h>
using namespace std;

int getFruitMax(vector<int>fruit)
{
    int n = fruit.size(), i;
    vector<int>dp(n);
    for (i = 0; i < n; i++)
    {
        if (i == 0)dp[0] = fruit[0];
        else if (i == 1)dp[i] = max(dp[i - 1], fruit[i]);
        else dp[i] = max(dp[i - 2] + fruit[i], dp[i - 1]);
    }
    return dp[n - 1];
}

int main()
{
    int n; cin >> n;
    vector<int>fruit(n);
    for (auto& e : fruit)
        cin >> e;
    cout << getFruitMax(fruit);
}