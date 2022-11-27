#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*
姑且下面的三个测试通过
*/

long long isPairSum(vector<double> A,double X)
{
    //long long ans=0;
    int N = A.size();
    set<set<int>>ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            else if (abs(A[i] + A[j] - X) < 10e-10)
            {
                ans.insert({ i, j });
            }
            else if (A[i] + A[j] > X)
                break;
        }
    }
    // No pair found with given sum.
    return ans.size();
}

int solution(vector<int>& X, vector<int>& Y)
{
	int n = X.size(), i;
	vector<double>nums(n);
	for (i = 0; i < n; i++)
		nums[i] = double(X[i]) / Y[i];
	//sort(nums.begin(), nums.end());
    return isPairSum(nums,1);
}

int main()
{
    vector<int>X = { 1,1,2 };
    vector<int>Y = { 3,2,3 };
    cout << solution(X, Y);
	
	//	检测精度
	//double n1 = double(1)/ 63 ;
	//double n2 = double(62)  / 63;
	//cout<<fixed<<setprecision(20) << n1<<endl<<n2<<endl<<n1+n2<<endl;
	
}