#include<bits/stdc++.h>
//#include<random>//C++随机数头文件
using namespace std;

//注意C++的rand()是返回0~32767的随机整数，要用公式返回[b,a+b-1]之间的随机数 rand()%a+b
int getIndex(vector<int>nums)
{
	int n = nums.size(),i,MAX=nums[0], max_i=-1;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (MAX < nums[i])
		{
			count = 1;
			MAX = nums[i], max_i = i;
		}
		else if (MAX == nums[i])
		{
			count++;
			srand(time(NULL));   //用当前时间作为随机数种子（面试的时候没实际跑代码，没发现C++随机数的问题）
			int ran = rand() % count + 1;
			cout << ran << "  "<<count<<endl;
			if (ran ==1)
			{
				MAX = nums[i], max_i = i;
			}
		}
	}
	return max_i;
}

int main()
{
	//int n; cin >> n;
	//vector<int>nums(n);
	//for (int i = 0; i < n; i++)
		//cin >> nums[i];
	vector<int>nums = { 1,2,2,4,4,4,4,4,4 };
	cout << getIndex(nums);
}
