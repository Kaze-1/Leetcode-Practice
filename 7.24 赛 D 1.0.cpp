#include<bits/stdc++.h> 
#include<unordered_map> 

using namespace std;
typedef long long ll;
const int MAX = 100001;


int main()
{
	int C; cin >> C;
	int res=-1;
	if (C % 4 == 0)res=0;
	else if(C>=12)
	{
		vector<int>pRes;
		int x,y;
		for (x = 3; x <= C - x - 3; x++)
		{
			for (y = 3; y < C - x; y++)
			{
				double Z = sqrt(x * x + y * y);
				int z = int(Z);
				vector<int>tem = {x,y,z};
				if (z + x + y == C&&z==Z)
				{
					int Min = *min_element(tem.begin(), tem.end());
					int Max = *max_element(tem.begin(), tem.end());
					pRes.emplace_back(Max-Min);
				}
			}
		}
		if(pRes.size()>0)res = *min_element(pRes.begin(), pRes.end());
	}
	cout << res;
}