#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
//#define MAX 0x7FFFFFFF		//也可LONG_MAX, LONG_MIN, INT_MAX,INT_MIN

vector<int> getSumOnce(vector<int>nums, int target)
{
	unordered_map<int, int>hashMap;
	int n = nums.size(), i;
	for (i = 0; i < n; i++)
	{
		if (hashMap.count(target - nums[i]) > 0)
			return { nums[i], nums[hashMap[target - nums[i]]] };
		hashMap[nums[i]] = i;
	}
	return {};
}



int solution(vector<int>& A, int M) {
	//int MIN = *min_element(A.begin(), A.end());
	//int MAX = *max_element(A.begin(), A.end());
	int n = A.size();
	sort(A.begin(), A.end());
	int MIN = A[0];
	int MAX = A[n-1];

	int i,j;
	/*
	unordered_map<int, int>occur;
	for (auto e : A)
		if (occur.find(e) == occur.end())occur[e] = 1;
		else ++occur[e];
	*/
	//set<int>res;
	set<int>resCor;

	
	for (i = 0; i < n; ++i)
	{
		/*
		if (occur[A[i]] % 2 == 0 && occur[A[i]] > 0)
		{
			res.insert(A[i]);
			break;
		}
		*/
		for(j=i+1;j<n;j+=M)
			if ((A[j] - A[i]) % M == 0)
			{
				//res.insert(A[i]);
				resCor.insert(i);
				//res.insert(A[j]);
				resCor.insert(j);
				break;
			}
		if (resCor.size() > 1)break;
	}
	if (resCor.size() == 0)return 1;

	for (i = 0; i < n; ++i)
		if (abs(A[i] - A[* resCor.begin()]) % M == 0)
			resCor.insert(i);
	return resCor.size();

	// write your code in C++ (C++14 (g++ 6.2.0))


}


int main()
{

	
	std::ios::sync_with_stdio(false); //写在main函数里！
	vector<int> A = { -3,-2,1,0,8,7,1 };
	int M = 3;
	cout << solution(A, M);
}
