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
	s.erase(s.begin() + 1, s.begin() + 4);//删除下标为1,2,3的字符
	cout << s << endl;

	s = "aaaabbbcadfd";
	s.erase(1, 3);//删除下标为1,2,3的字符
	cout << s << endl;

	//如果erase传入的是Iterator,只删除一个元素
	//如果erase传入的是index,删掉index及之后的所有元素
	s = "aaaabbbcadfd";
	auto it = s.find('b');//string的find返回下标，和std::find不同
	s.erase(it);
	cout << s << endl;

	s = "aaaabbbcadfd";
	auto it2 = find(s.begin(),s.end(),'b');//std::find 返回iterator
	s.erase(it2);
	cout << s << endl;	

	s = "aaaabbbcadfd";
	string str = "XXX";
	s.insert(s.begin() + 1, str.begin(), str.end());
	cout << s << endl;
}
