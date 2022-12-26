#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;


/*
和官方解法区别：使用unordered_set(Java的HashSet)

*/

int lengthOfLongestSubstring1(string s) {
	int n = s.length(),i=0,j=0,k;
	if (n == 0)return 0;
	//vector<vector<int>>slide(n, vector<int>(n));
	unordered_set<int>set;
	vector<int>res = {0, 0}; //record optimal i&j
	//vector<int>cur = {0, 0}; //record current i&j
	//for(i=0;i<n-1;++i)
	//	for (j = 0; j < n; ++j)
	while (j < n)
	{
		auto index = set.find(s[j]);
		int n = res.size();
		if (index == set.end())
		{
			set.insert(s[j]);
			//res[1] = j;
			if (res[1] - res[0] < j - i)
				res[0] = i, res[1] = j;

		}
		else
		{
			for (k = i; k < j; ++k)
				if (s[j] == s[k])break;
				else set.erase(s[k]);
			i = k+1;	//缩小i到k+1，只有i可能缩小
			//set.clear();
			//for (; k <= j; ++k)
			//	set.insert(s[k]);
		}
		++j;//j无脑加
	}
	return res[1] - res[0] + 1;
}

// 官方解法: 滑动窗口 1
int lengthOfLongestSubstring2(string s) {
	unordered_map<char, int> chars;		

	int left = 0;
	int right = 0;

	int res = 0;
	while (right < s.length()) {
		char r = s[right];
		chars[r]++;

		while (chars[r] > 1) {
			char l = s[left];
			chars[l]--;
			left++;					
		}

		res = max(res, right - left + 1);

		right++;
	}

	return res;
}

// 官方解法: 滑动窗口 优化版		
// 用哈希表记录字符——>index的映射，直接修改映射值
int lengthOfLongestSubstring3(string s) {
	int n = int(s.length()), res = 0;
	unordered_map<char, int> mp;

	for (int j = 0, i = 0; j < n; j++) {
		if (mp[s[j]] > 0) {
			i = max(mp[s[j]], i);
		}
		res = max(res, j - i + 1);
		mp[s[j]] = j + 1;
	}
	return res;
}


int main()
{
	string s = "abca";
	cout << lengthOfLongestSubstring1(s);

}