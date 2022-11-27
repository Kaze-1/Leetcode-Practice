#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

//std::ios::sync_with_stdio(false); //写在main函数里！

bool judgePrime(int n)
{
	int i = 2;
	for (i = 2; i <=n/2; ++i)
		if (n % i ==0)return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	//用搜索法计算质因数个数
	int n, k,i,j; 
	cin >> n >> k;
	vector<int>nums(n);
	for (auto& e : nums)
		cin >> e;
	unordered_map<int,int>Primes;//质数表 hashMap
	int maxPrime=-1;//表里的最大质数
	unordered_map<int, int>weight;
	for (j = 0; j < n; ++j)
	{
		for (i = 2; i <=nums[j]/2; ++i)
		{
			if (Primes[i] == 1 &&  nums[j] % i == 0)
				++weight[nums[j]];
			/*
			if (maxPrime >= i)
			{
				if (Primes[i] == 1 && i % nums[i]==0)
					++weight[j];
			}*/
			else if (maxPrime < i && judgePrime(i) == true)
			{
				maxPrime = i;
				Primes[i] = 1;
				if (nums[j]%i == 0)
					++weight[nums[j]];
			}
		}
		if (maxPrime >= nums[j] && Primes[nums[j]] == 1)
			++weight[nums[j]];
		else if (maxPrime < nums[j] && judgePrime(nums[j]) == true)
		{
			maxPrime = i;
			Primes[i] = 1;
			++weight[nums[j]];
		}
	}

	
	/*
	for (auto e : weight)
		cout << e << " ";
	*/	
	//cout << 6%2;

	//cout << judgePrime(23);
	
	ll totalSum = 0;
	for (i = 0; i < n; ++i)
		totalSum += weight[nums[i]];
	
	vector<ll>res(n-k+1);  //存储{k子数组值， i}
	for (i = 0; i < k; ++i)
	{
		res[0] += weight[nums[i]];
	}

	for (i = 1; i <= n - k; ++i)
		res[i] = res[i - 1] - weight[nums[i-1]] + weight[nums[i]];
	cout<< totalSum -*min_element(res.begin(),res.end());
		

	/*
	ll qSum=0;
	queue<int>Q;
	for (i = 0; i < k; ++i)
	{
		Q.push(i);
		qSum += nums[i];
	}
	for (i = 1; i < n - k; ++i)
	{
		if(nums[i]>Q.front())

	}
	*/
	/*
	vector<vector<int>>dp(n, vector<int>(k + 1));
	for (i = 1; i < n; ++i)
		for (j = 1; j < n; ++j)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - nums[i] * weight[i]);
			*/
}
/*
5 2
6 2 4 1 3

4

1 2 
3 
*/