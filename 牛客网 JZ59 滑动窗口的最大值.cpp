#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	int p=0, q=p+size;// 左闭右开的滑动窗口[ )
	int n = num.size(),i;
	vector<int>res(0);
	while (q <=n)
	{
		vector<int>wind(0);
		for (i = p; i < q; i++)
			wind.push_back(num[i]);
		res.push_back(*max_element(wind.begin(), wind.end()));
		p++, q++;
	}
	return res;
}




int main()
{
	vector<int>test = { 2, 3, 4, 2, 6, 2, 5, 1 };
	int size = 3;
	vector<int> res=maxInWindows(test, size);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
	string a="asafasfafssf";	cout << a.substr(1, 2);

}