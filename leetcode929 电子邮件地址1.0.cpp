#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

string process(string s)
{

	int at = s.find("@");
	int dot = s.find(".");
	int i,n=s.size();
	string pre = "";
	for (i = 0; i <= at - 1; i++)
	{
		if (s[i] == '+')break;
		if (s[i] == '.')continue;
		pre += s[i];
	}
		
	string s1 = pre;
	for (i = at; i < n - 1; i++)
		s1+=s[i];
	return s1;
}

int numUniqueEmails(vector<string>& emails) {
	int n = emails.size(),i,j;
	set<string>res;
	for (i = 0; i < n; i++)
	{
		string s = process(emails[i]);
		res.insert(s);
	}
	return res.size();
}

int main()
{
	vector<string>emails = { "test.email + alex@leetcode.com", "test.e.mail + bob.cathy@leetcode.com", "testemail + david@lee.tcode.com" };
	vector<string>emails2 = { "a@leetcode.com", "b@leetcode.com", "c@leetcode.com" };
	cout << numUniqueEmails(emails2);
}