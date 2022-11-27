#include<bits/stdc++.h> 
#include<unordered_map>  

using namespace std;
typedef long long ll;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A < B)swap(A, B);
    ll n = 0;
    while (1)
    {
        if (A < B)swap(A, B);
        
        A = A - B;
        n++;
        if (A == 0)break;
    }
    cout << n;
    return 0;
}