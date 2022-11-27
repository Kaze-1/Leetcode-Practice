#include<iostream>
#include<vector>
#include<string>

using namespace std;

string capitalizeTitle(string title)
{
    int i,j=0;
    vector<string>res;
    for (i = 0; i < title.length();i++)//É¨ÃèÕû¸ö×Ö·û´®
    {
        string tem_title="";
        while (title[j] != ' '&& j < title.length())
        {
            tem_title += title[j];
            j++;
        }
        if (title[j] == ' ' && j < title.length())j++;
        if (tem_title == "")break;//ÒÑ¾­É¨ÃèÍê±Ï
        res.push_back(tem_title);// store all the words into a vector "res"
    }
    for (i = 0; i < res.size(); i++)
    {
        int len = res[i].length();
        if (len == 1 || len == 2)
            for (j = 0; j < len; j++)
                res[i][j] = tolower(res[i][j]);
        else
        {
            res[i][0] = toupper(res[i][0]);
            for (j = 1; j < len; j++)
                res[i][j] = tolower(res[i][j]);
        }
    }
    string res_s="";
    for (i = 0; i < res.size() - 1; i++)
        res_s = res_s + res[i] + ' ';
    res_s += res[res.size() - 1];
    return res_s;
}

int main()
{
    string title = "capiTalIze tHe titLe";
    string new_t = capitalizeTitle(title);
    cout << new_t;
}