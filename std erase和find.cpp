#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;



int main()
{
	unordered_set<int> set;
	int n = 4;
	while (n--)
		set.insert(1);
	set.erase(1);
	//cout << *set.begin();

	string s = "aaaabbbcadfd";
	//s.erase('f');   
	s.erase(s.begin() + 1, s.begin() + 4);//ɾ���±�Ϊ1,2,3���ַ�
	cout << s << endl;

	s = "aaaabbbcadfd";
	s.erase(1, 3);//ɾ���±�Ϊ1,2,3���ַ�
	cout << s << endl;

	//���erase�������Iterator,ֻɾ��һ��Ԫ��
	//���erase�������index,ɾ��index��֮�������Ԫ��
	s = "aaaabbbcadfd";
	auto it = s.find('b');//string��find�����±꣬��std::find��ͬ
	s.erase(it);
	cout << s << endl;

	s = "aaaabbbcadfd";
	auto it2 = find(s.begin(),s.end(),'b');//std::find ����iterator
	s.erase(it2);
	cout << s << endl;	

	s = "aaaabbbcadfd";
	string str = "XXX";
	s.insert(s.begin() + 1, str.begin(), str.end());
	cout << s << endl;
}
