/*

*/

#include<bits/stdc++.h>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF

//std::ios::sync_with_stdio(false); //写在main函数里！

int main()
{
	std::ios::sync_with_stdio(false); //写在main函数里！
	int n, m,i,j;
	cin >> n >> m;
	vector<int>testGrade(n);
	for (auto& e : testGrade)		//注意加&
		cin >> e;
	vector<int>ordiGrade(n);
	fill(ordiGrade.begin(), ordiGrade.end(), 100);//初始化成100

	vector<vector<int>>attendance(n,vector<int>(m));
	for(i=0;i<n;++i)
		for (j = 0; j < m; ++j)
		{
			cin >> attendance[i][j];
		}
	for (j = 0; j < m; ++j)//点名
	{
		int k; cin >> k;
		while (k--)
		{
			int tem; cin >> tem;
			if (attendance[tem - 1][j] == 0&& ordiGrade[tem - 1]>=10)
				ordiGrade[tem - 1] -= 10;
		}
	}
	vector<vector<float>>res;
	vector<float>finalRes(n);
	unordered_map<float, vector<int>>hash;
	for (i = 0; i < n; ++i)
	{
		float final = float(testGrade[i]) * 0.6 + float(ordiGrade[i]) * 0.4;
		//res.emplace_back(vector<float>{ final,float(i + 1) });
		finalRes[i]=final;
		hash[final].emplace_back(i + 1);
	}
	set<float>s(finalRes.begin(), finalRes.end());
	finalRes.assign(s.begin(), s.end());
	sort(finalRes.rbegin(), finalRes.rend());
	//vector 去重
/*vector<int>vec = {1,1,11,2,1};*/

	//对编号排序
	/*
	for (i = 0; i < n-1; ++i)
	{

		for(j=0;j<m;++j)
	}
	
	
	for (i = 0; i < n; ++i)
		cout<< int(res[i][1])<<" "<<fixed << setprecision(2)<<res[i][0] << "\n";
*/
	for (i = 0; i < finalRes.size(); ++i)
	{
		sort(hash[finalRes[i]].begin(),hash[finalRes[i]].end());
		for(j=0;j< hash[finalRes[i]].size(); ++j)
			cout << hash[finalRes[i]][j] << " " << fixed << setprecision(2) << finalRes[i] << "\n";
		
	}
}

/*
3 2
100 100 100
1 0
0 1
1 1
3 1 2 3
1 1

3 100.00
1 96.00
2 96.00


7 3
64 33 32 98 49 18 88
0 1 0
0 0 0
0 0 1
0 1 0
0 0 0
1 0 1
0 0 1
2 1 2
0
2 1 2
*/