// ţ�ٷ�

#include<iostream>
using namespace std;


//������
//ע�ⷽ�̱���
int pivotInteger(int n) {
	double x = 1, newX=0,diff=LONG_MAX;
	while (abs(diff) > 10e-9)
	{
		//double tem = newX;
		newX = x - (2*x * x - n*n - n) / (4 * x);
		diff = newX - x;
		x = newX;
	}
	if (abs(int(x) - x)< 10e-9)
		return x;
	else return -1;

}

int main()
{
	cout << pivotInteger(8) << endl;
}


