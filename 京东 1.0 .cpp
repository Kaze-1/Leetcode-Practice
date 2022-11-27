#include<bits/stdc++.h> 
#include<unordered_map>  
#include<set>  

using namespace std;

int main()
{
	int n, k,i,j;
	cin >> n >> k;
	set<int>Seq;
	for (i = 0; i < n; i++)
		{
			int tem; cin >> tem;
			Seq.insert(tem);
		}
	set<int>subSeq;
	auto it = subSeq.begin();
	///copy(Seq.begin(), Seq.begin()+k, subSeq.begin());
	
	
	for (i = 0; i < k; it++,i++)
	{
		int tem = *it;
		cout << tem<<" ";
		//subSeq.insert(tem);
	}
	
	
}

/*
7 4
1 4 7 2 5 6 3
*/