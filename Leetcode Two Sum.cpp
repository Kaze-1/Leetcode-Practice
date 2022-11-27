/*
Leetcode:Two Sum
https://leetcode.com/problems/two-sum/
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<unordered_map>
using namespace std;

/*
�ܽ᣺ǿ��[begin(),end())����ҿ�����ĸ���,end()�������n�����Ԫ�ص���һ����

ѧ��iterator��int��ת���±�=iterator-begin()

*/

int recurisonBinarySearch(vector<int>& nums,int left, int right, int x)
{
	if (left > right)
	{
		return -1;
	}
	int mid = (left + right) / 2;
	if (x == nums[mid])
	{
		return mid;
	}
	if (x > nums[mid])
	{
		return recurisonBinarySearch(nums,mid + 1, right, x);
	}
	else
	{
		return recurisonBinarySearch(nums,left, mid - 1, x);
	}
}


vector<int> twoSum1(vector<int>& nums, int target) 
{
	int n = nums.size();
	vector<int>nums_copy = nums;
	sort(nums.begin(), nums.end());//������
	int i, num1, num2;
	for (i = 0; i < n - 1; i++)
	{
		num1 = i;
		//num2 = recurisonBinarySearch(nums, i + 1, n - 1, target - nums[i]);
		num2 = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i])- nums.begin();
		//��������ת����int�ķ��� ע��.end()ת���õ�n������n-1
		///num2 = *lower_bound(i, nums.end(), target - num1);
		if (num2 != -1&&num2!=n && nums[num2] == target - nums[num1])
			break;
	}
	
	int k1 = -1, k2 = -1,j;
	for (i = 0; i < n; i++)
	{
		if (nums_copy[i] == nums[num1])
		{
			k1 = i; break;
		}
	}
	for (i = 0; i < n; i++) 
	{
		if (nums_copy[i] == nums[num2]&&i!=k1) { k2 = i; break; }
	}
	if (k1 == -1 || k2 == -1)
		return {};
		
	vector<int>res;
	res.push_back(k1);
	res.push_back(k2);
	//res.push_back(int(num2_i - nums.begin());
	return res;
	
}

vector<int> twoSum2(vector<int>& nums, int target)
{
	unordered_map<int, int> hashTable;  //������int��Ԫ��ֵ����int��Ԫ���±꣩�Ĺ�ϣӳ��
	int i,j;
	for (i = 0; i < nums.size(); i++)
		hashTable[nums[i]] = i;
	for (i = 0; i < nums.size(); i++)
	{
		j = hashTable[target - nums[i]];
		if (nums[i] + nums[j] == target && i != j)
			break;
	}
	vector<int>res;
	res.push_back(i);
	res.push_back(j);
	return res;
}

vector<int> twoSum3(vector<int>& nums, int target)
{
	unordered_map<int, int> hashTable;  //������int��Ԫ��ֵ����int��Ԫ���±꣩�Ĺ�ϣӳ��
	int i, j;

	for (i = 0; i < nums.size(); i++)
	{
		j = hashTable[target - nums[i]];
		if (nums[i] + nums[j] == target && i != j)
			break;
		hashTable[nums[i]] = i;
	}
	vector<int>res;
	res.push_back(i);
	res.push_back(j);
	return res;
}

int main()
{
	vector<int> input = { 1, 6142, 8192, 10239 };
	input=twoSum3(input, 8192+ 10239);
	if (input.size())cout << input[0] << " " << input[1];
	else cout << "�գ�";
	
}