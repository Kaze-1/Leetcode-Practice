#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>r#include<string>
using namespace std;

string Correct1(string str)//�Ȱ�����1ɾ��
{
    int i, j, num = 0,flag=0;
    char tem;
    for (i = 0; i < str.length(); i++)    //�ж����������ַ���ͬ����ɾ��������
    {
        /*
        for (j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])//&&str[i]==str[j+1]&&j+1<=str.length())
            {
                num++;
                if (num >= 2)str.erase(j,j);    //�ظ��������ξ�ɾ���������ظ���  �Ǳ�һ�±�ʾɾ��һ��Ԫ��(�±�Ϊj)
                //str.erase(j, j);    //�ظ��������ξ�ɾ���������ظ���  �Ǳ�һ�±�ʾɾ��һ��Ԫ��(�±�Ϊj)
            }
        }         */
        if (i >= 1 && str[i] == str[i - 1])
        {            
            for (j = i + 1; j < str.length() && str[j] == str[i]; j++)//��һ��˼·��ֱ���ҳ��ظ��Ĳ��֣�Ȼ��eraseɾ����ֻʣ2��
                flag=1;          
            if (flag)str.erase(str.begin()+i + 1, str.begin()+j);    //ɾ��[i+1,j)֮���Ԫ��
        }
    }
    return str;
}

string Correct2(string str)//�ٰ�����2ɾ��
{
    int i, last = -10, num = 0, flag = 0;//��0-1 flag���
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
        if (num >= 2 && last + 2 == i)   //����ظ������ϴκ��� ִ��ɾ��
        {
            str.erase(i, 1);//ɾ���±�Ϊi��Ԫ��
            flag = 0;
        }   
    }
    return str;
}

int main()
{
    int N, n; cin >> N; n = N;
    queue<string> res;
    while (n--)//����ʹ���
    {
        string str;
        cin >> str;
        str = Correct1(str);
        str = Correct2(str);
        res.push(str);
    }
    n = N;
    while (n--)    //���
    {
        cout << res.front()<<endl;
        res.pop();
    }
}
