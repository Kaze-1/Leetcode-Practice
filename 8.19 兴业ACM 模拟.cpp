#include<bits/stdc++.h>

//#include<iostream>
//#include<string>
#include<unordered_map>
using namespace std;


int main()
{
    string s1, s2;
    getline(cin, s1);
    cin>> s2;
    //set<char>Set;
    unordered_map<char, int>hash;
    for (int i = 0; i < s2.length(); ++i)
        hash[s2[i]] = i;
        
    for (auto e = s1.begin(); e < s1.end(); ++e)    //这里需要优化
    {
        if (hash.find(*e) != hash.end())
            s1.erase(e);
        if (s1=="") { break; s1 = ""; }
    }
        
    cout << s1;
}
/*
They are students.
aeiou

aeiouaa
aeiou
*/