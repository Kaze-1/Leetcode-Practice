#include <bits/stdc++.h>
#include<algorithm> 
#include<numeric> 

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

//  
int TentoAny(ll num, int k)//ʮ������ת��Ϊ k����(2<=k<=36)
{
	vector<int> v;//����������
	ll t;//���� 
	while (num)
	{
		t = num % k;
		v.push_back(t);//��β�����Ԫ��
		num /= k;
	}
	reverse(v.begin(), v.end());
	//return v;
	return accumulate(v.begin(), v.end(), 0);   //������ֵ����
}


int main()
{
	// __gcd��int i��int j) ����С������

	int n;
	cin >> n;
	int k;
	int sum = 0;
	
	
	for (k = 2; k <= n - 1; k++)
	{
		sum += TentoAny(n, k);
		//cout<< TentoAny(n, k)<<"\n";
	}
	int c = gcd(sum, n - 2);
	// cout << c << endl;
	cout << sum / c << '/' << (n - 2) / c;

	/*
	vector<char>v= TentoAny(15, 16);
	for (int i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	*/
	return 0;
}


