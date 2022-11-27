//Ë«Ö¸Õë

#include<iostream>
using namespace std;


int appendCharacters(string s, string t) {
	int m = s.length(), n = t.length();
	int p = 0, q = 0;
	while (q != n && p != m)
	{
		if (s[p] == t[q])
			++q;
		++p;
	}
	return n - q;
	//if (q == n)
	//	return 0;
	
}




int main()
{
	string s = "z";
	string t = "abcde";
	cout << appendCharacters(s, t)<<endl;
	return 0;
}