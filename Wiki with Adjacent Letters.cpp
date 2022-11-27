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
    for (i = 0; i <=24; i++)//注意前后两次扫描的上界不一样！26个字母所以扫描26-1次(数组别越界！)
    {
        total += flag[i + 1] * flag[i];
    }
    cout << total;
    return 0;

}