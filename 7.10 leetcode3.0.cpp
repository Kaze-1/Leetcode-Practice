#include<bits/stdc++.h>
using namespace std;

int main()
{
	string start, target, s = "", t = "";
	cin >> start >> target;
	int i;
	for (i = 0; i < start.size(); i++)
		if (start[i] == 'R' || start[i] == 'L')
		{
			s += start[i];
			if (start[i] == 'R' && i<start.size()-1&&start[i + 1] != '_' && target[i] != 'R')return false;
			else if (start[i] == 'L' && i>0&&start[i- 1] != '_' && target[i] != 'L')return false;
		}
			
	for (i = 0; i < target.size(); i++)
		if (target[i] == 'R' || target[i] == 'L')
			t+= target[i];
	if (t != s)return false;
	return true;
	//s = "abcd";
	//cout<<s.substr(0,s.size());
}