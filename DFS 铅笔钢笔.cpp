/*
有想法（DFS）
但还是没调对
*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;

void dfs(int total, int limit, int cost1, int cost2, int penNow, int pencilNow);
long long waysToBuyPensPencils(int total, int cost1, int cost2);



int main()
{
	int cost1, cost2, total;
	cin >> total >> cost1 >> cost2;
	cout << waysToBuyPensPencils(total, cost1, cost2);
}

//DFS
ll sum = 0;

set<vector<int>>res;


//limit：目前可以花的钱
void dfs(int total,int limit, int cost1, int cost2,int penNow, int pencilNow)
{
	if (limit > total||limit<=0) return;
	
	sum++;
	int pens = limit /cost1,i,j;
	int pencils = limit / cost2;
	//cout << pens << " " << pencils << " "<<endl;
	for (i = 0; i <= penNow; i++)
		for (j = 0; j <= pencilNow; j++)
		{
			if (i == 0 && j == 0)continue;//这种情况已经记上
			dfs(total, limit - i * cost1 - j * cost2, cost1, cost2,i,j);

			/*
			if (limit - i * cost1 - j * cost2 <= total && limit - i * cost1 - j * cost2 > 0)
			{
				//cout << i << " " << j << " " << endl;
				vector<int> oneRes;
				oneRes.push_back(i); oneRes.push_back(j);
				res.insert(oneRes);
			}*/
		}
		
}

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
	dfs(total,total, cost1, cost2,0,0);
	return res.size()+1;

}



// 5 10 10
//20 10 5