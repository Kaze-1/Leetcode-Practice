#include<bits/stdc++.h> 

using namespace std;

bool isPrime(int n)
{
    if (n == 1)return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int countPrimes(int n) {
    vector<int> isPrime(n, 1);
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            ans += 1;
            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
    }
    return ans;
}


int main()
{
    int n, i;
    cin >> n;
    //    vector<int>statis(n);
    int N = 0;
    N = countPrimes(n);
    //for (i = 1; i <= n; i++)
      //  if (isPrime(i))N++;
    cout << fixed << setprecision(3) << (N + 0.0) / n;
    return 0;
}