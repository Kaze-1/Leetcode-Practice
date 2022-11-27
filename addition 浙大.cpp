#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 0x3FFFFFFF
typedef long long  ll;


int main()
{
    ll a, b, c, c_tem;
    cin >> a >> b;
    c = a + b, c_tem = abs(c);
    if (c == 0) { cout << 0; return 0; }
    vector<int> res;
    int sign = c / abs(c);
    while (c_tem != 0)
    {
        int tem = c_tem % 10;
        res.push_back(tem);
        c_tem = c_tem / 10;
    }
    //reverse(res.begin(), res.end());

    string res_s;
    if (sign == -1)
        cout << "-";
    //else res_s="";
    int times = 0;
    while (res.size() != 0)
    {
        cout << res.back();
        //res_s.append(d);
        res.pop_back(); times++;
        if (times % 3 == 0&& res.size() != 0)
            cout << ',';
    }
    return 0;
}