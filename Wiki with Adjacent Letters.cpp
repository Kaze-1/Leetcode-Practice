#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;


int main()
{
    ll num, i;
    string str;
    cin >> num >> str;

    ll flag[26] = { 0 };
    for (i = 0; i < str.length(); i++)
    {
        int order = str[i] - 'a';
        flag[order]++;
    }
    ll total = 0;
    for (i = 0; i <=24; i++)//ע��ǰ������ɨ����Ͻ粻һ����26����ĸ����ɨ��26-1��(�����Խ�磡)
    {
        total += flag[i + 1] * flag[i];
    }
    cout << total;
    return 0;

}