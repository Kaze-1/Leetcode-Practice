#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
# define M_PI           3.14159265358979323846  /* pi */

int main()
{
	int R, A, B,N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		cin >> R >> A >> B;
		int Radius = R;
		long double sum = Radius * Radius * M_PI;
		//cout << sum << " ";
		int round = 0;
		while (Radius > 0)
		{
			if (round % 2 == 0)
				Radius *= A;
			else Radius /= B;
			if (Radius == 0)break;
			sum += Radius * Radius * M_PI;
			round++;
		}
		cout << "Case #" << i<<":";
		cout << fixed << setprecision(11) << sum<<endl;
	}
}