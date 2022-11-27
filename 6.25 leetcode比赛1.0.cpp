#include<bits/stdc++.h>
using namespace std;


int countAsterisks(string s) {
    queue<int>rec;//记录竖线的index
    int n = s.length(), i;
    for (i = 0; i < n; i++)
        if (s[i] == '|')rec.push(i);
    vector<bool>flags(n, 1);//是否可以计入
    if (rec.size() > 1)
    {
        while (rec.size() != 0)
        {
            int start = rec.front();
            rec.pop();
            int last = rec.front();
            rec.pop();
            for (i = start + 1; i <= last - 1; i++)
                flags[i] = 0;
        }
    }
    int res = 0;
    for (i = 0; i < n; i++)
        if (flags[i] == 1 && s[i] == '*')res++;
   
    return res;

}

int main()
{
    string s = "l|*e*et|c**o|*de|";
    s = "yo|uar|e**|b|e***au|tifu|l";
    cout << countAsterisks(s);
    
}