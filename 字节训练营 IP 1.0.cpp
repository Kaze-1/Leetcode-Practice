#include<bits/stdc++.h>	
#include<unordered_map>
using namespace std;

int main()
{
	string s;
	cin >> s;//ԭʼ�ַ�
	int n = s.length(),i;
	bool flagNum = 1;//�Ƿ�ȫΪ����
	vector<bool> numsInc(10, 0);//�����˵�����(0~9֮��)
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
	
	//�ȷָ� ���滻
	int dotNum = 3;
	i = 0;//��ǰָ��
	int lastD = 0;//��һ����
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