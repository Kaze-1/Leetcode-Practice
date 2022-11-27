#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


void myReverse(string& s)
{
	for (int i = 0; i < s.length() / 2; i++)
		swap(s[i], s[s.length() - 1 - i]);
}

void myReverse(vector<int>& s)
{
	for (int i = 0; i < s.size() / 2; i++)
		swap(s[i], s[s.size() - 1 - i]);
}

int main()
{
	string a = "This is a String";
	reverse(a.begin(), a.end());		//操作等价于myReverse
	myReverse(a);
	cout << a<<endl;

	vector<int>nums = {1,2,3,4,5};
	reverse(nums.begin(), nums.end());
	myReverse(nums);					//操作等价于myReverse(重载)
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i]<<" ";
	cout << endl;
}