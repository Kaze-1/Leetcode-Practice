#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

int main()
{
	string s;
	cin >> s;//原始字符
	int n = s.length(),i;
	bool flagNum = 1;//是否全为数字
	vector<bool> numsInc(10, 0);//出现了的数字(0~9之间)
	for (i = 0; i < n; i++)
	{
		if (isdigit(s[i]) == 0)
			flagNum = 0;
		else
			numsInc[s[i]] = 1;
	}
	vector<int>numsLeft;
	for (i = 0; i <= 9; i++)
		if (numsInc[i] == 0)
			numsLeft.push_back(i);
	
	//先分割 后替换
	int dotNum = 3;
	i = 0;//当前指针
	int lastD = 0;//上一个点
	string res = "";
	while (dotNum > 0)
	{
		if (i > lastD)
		{
			string numNowS = s.substr(lastD, i - lastD + 1);
			int numNow = stoi(s.substr(lastD, i - lastD + 1));
			if (numNow <= 255 && numNow >= 0 && numNowS[0] != '0')
			{
				res += numNowS + ".";
				dotNum--;
			}
		}
		i++;
	}




}