#include<bits/stdc++.h>
using namespace std;

//xn+1=xn-f(xn)/f'(xn)
double mySqrt(double a)
{
	double x0 = 1,x1=x0;
	while (abs(x1 * x1 - a) > 1e-6)
	{
		x1 = x0 - (x0 * x0 - a) / (2 * x0);
		x0 = x1;
	}
	return x1;
}

//牛顿法解三元一次方程
double myEquSolution()
{
	double x0 = 1, x1 = x0;
	double value = 1;
	while (abs(value)-0 > 1e-6)
	{
		value = pow(x0, 3) + pow(x0, 2) + x0 + 1;
		x1 = x0 - value / (3 * pow(x0,2)+2*x0+1);
		x0 = x1;
	}
	return x1;
}

int main()
{
	cout << mySqrt(100)<<endl;
	cout << myEquSolution();
}