#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

//������Greedy�㷨�� ���ǵ���DP��֤ȫ�����Ž�
bool stoneGame1(vector<int>& piles) {
    int n = piles.size();
    int sumA = 0, sumB = 0, i, j = n - 1, k = 0;
    vector<bool>flags(n);//record if a pile has been taken(1)
    for (i = 1; i <= n && j >= k; i++)//simiulate every turn
    {
        if (i % 2 == 1)//alice
            if (piles[k] > piles[j])
            {
                sumA += piles[k]; k++;
            }
            else
            {
                sumA += piles[j]; j--;
            }
        else
            if (piles[k] > piles[j])
            {
                sumB += piles[k]; k++;
            }
            else
            {
                sumB += piles[j]; j--;
            }
        int restSum = accumulate(piles.begin() + k, piles.begin() + j + 1, 0);
        if (sumA > sumB + restSum) return true;
    }
    return false;
}

//��̬�滮 ����dp[i][j] Ϊ���piles[i~j]ʱ��ǰ������õ��ķ������ֵ��max{ʯͷ�ܺ�}��
//�ɴ˿�������DP���������Ҫ�أ�
//1����׼ָ����ǰ״̬(����1~2���Ǳ�) 2������ȡֵ����==��ǰ���Ž⣨������Ҫ���bool�Ľ���Ҫ׼ȷȡֵ��ֱ����T/F��
bool stoneGame(vector<int>& piles) {
    const int N = 501;
    int dp[N][N] = { 0 };
    int sum = accumulate(piles.begin(), piles.end(), 0);
    int n = piles.size();
    int i = 0, j = n - 1,k=1;
    for (k = 1; j >= i; k++)
    {
        int last1=0, last2=0;
        if (i > 0)last1 = dp[i - 1][j];
        if (j < n - 1)last2 = dp[i][j + 1];
        if (last1 + piles[i] > last2 + piles[j])
        {
            dp[i][j] = last1 + piles[i];
            if (k % 2 == 1 && dp[i][j] > sum / 2)return true;
            i++;
        }
        else
        {
            dp[i][j] = last2 + piles[j];
            if (k % 2 == 1 && dp[i][j] > sum / 2)return true;
            j--;
        }
    }
    return false;
}

int main()
{
    vector<int>test = { 5, 3, 4, 5 };
    cout << stoneGame(test);
}