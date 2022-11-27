#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int canBeTypedWords(string text, string brokenLetters) {
    string str[100];
    istringstream is(text);
    int word_count = 0;
    while (is >> str[word_count])
    {
        word_count++;
    }
    
    int sum = word_count;
    int i, j, k;
    for (i = 0; i < word_count; i++)
    {
        for (j = 0; j < brokenLetters.length(); j++)
            for (k = 0; k < str[i].length(); k++)
            {
                if (str[i][k] == brokenLetters[j])
                {
                    sum--;
                    goto out;
                }
            }
    out:;
    }
        

    return sum;

}

int main()
{
    string text, brokenLetters;
    text = "hello world", brokenLetters = "ad";
    //text = "leet code", brokenLetters = "e";
    cout<<canBeTypedWords(text, brokenLetters);
}