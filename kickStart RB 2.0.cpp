#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;

vector <ll> getFactors(ll x) {
    // We will store all factors in `result`
    vector <ll> result;
    int i = 1;
    // This will loop from 1 to int(sqrt(x))
    while (i * i <= x) {
        // Check if i divides x without leaving a remainder
        if (x % i == 0) {
            result.push_back(i);
            // Handle the case explained in the 4th
            if (x / i != i) {
                result.push_back(x / i);
            }
        }
        i++;
    }
    // Return the list of factors of x
    return result;
}

int main()
{
    int T; cin >> T;
    for (int i = 1; i <= T; i++)
    {
        ll A; cin >> A;
        ll res = 0;
        vector <ll>factors = getFactors(A);
        for (int j = 0; j < factors.size(); j++)
        {
            bool flag = 1;
            ll n = to_string(factors[j]).size();
            for (ll k = 0; k < n / 2; k++)
                if (to_string(factors[j])[k] != to_string(factors[j])[n - 1 - k])
                    flag = 0;
            if (flag)res++;
        }
        cout << "Case #" << i << ": " << res << endl;
    }
}