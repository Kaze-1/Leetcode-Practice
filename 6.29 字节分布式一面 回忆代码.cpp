#include<bits/stdc++.h>
//#include<random>//C++�����ͷ�ļ�
using namespace std;

//ע��C++��rand()�Ƿ���0~32767�����������Ҫ�ù�ʽ����[b,a+b-1]֮�������� rand()%a+b
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
			srand(time(NULL));   //�õ�ǰʱ����Ϊ��������ӣ����Ե�ʱ��ûʵ���ܴ��룬û����C++����������⣩
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
