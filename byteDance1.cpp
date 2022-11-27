#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>r#include<string>
using namespace std;

string Correct1(string str)//先按规则1删除
{
    int i, j, num = 0,flag=0;
    char tem;
    for (i = 0; i < str.length(); i++)    //判断连续三个字符相同并且删除第三个
    {
        /*
        for (j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])//&&str[i]==str[j+1]&&j+1<=str.length())
            {
                num++;
                if (num >= 2)str.erase(j,j);    //重复超过两次就删除后面再重复的  角标一致表示删除一个元素(下标为j)
                //str.erase(j, j);    //重复超过两次就删除后面再重复的  角标一致表示删除一个元素(下标为j)
            }
        }         */
        if (i >= 1 && str[i] == str[i - 1])
        {            
            for (j = i + 1; j < str.length() && str[j] == str[i]; j++)//换一种思路，直接找出重复的部分，然后erase删除到只剩2个
                flag=1;          
            if (flag)str.erase(str.begin()+i + 1, str.begin()+j);    //删除[i+1,j)之间的元素
        }
    }
    return str;
}

string Correct2(string str)//再按规则2删除
{
    int i, last = -10, num = 0, flag = 0;//用0-1 flag标记
    char tem;
    for (i = 0; i < str.length(); i++)
    {
        if (i >= 1 && str[i] == str[i - 1])
        {
            num++;
            //if (num % 2 == 0&&num>=2)
            if (flag == 0)
            {
                last = i;
                flag = 1;
            }
        }
        if (num >= 2 && last + 2 == i)   //这次重复跟在上次后面 执行删除
        {
            str.erase(i, 1);//删除下标为i的元素
            flag = 0;
        }   
    }
    return str;
}

int main()
{
    int N, n; cin >> N; n = N;
    queue<string> res;
    while (n--)//输入和处理
    {
        string str;
        cin >> str;
        str = Correct1(str);
        str = Correct2(str);
        res.push(str);
    }
    n = N;
    while (n--)    //输出
    {
        cout << res.front()<<endl;
        res.pop();
    }
}
