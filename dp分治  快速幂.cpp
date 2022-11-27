#include<bits/stdc++.h>
using namespace std;

//分治法快速幂
double myPow(double x, long long n)
{
	if (n == 0)return 1;
	if (x == 0 || x == 1 || n == 1)return x;
	double tem = myPow(x, n / 2);
	if (n % 2 == 0) return tem * tem;
	else return tem * tem*x;
}

int main()
{
	cout << myPow(2, 13);
}