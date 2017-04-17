/*huypheu
100 0
*/

#include <bits/stdc++.h>
#define int int64_t
#define mod 1000000000
using namespace std;

pair <int,int> f[107][407][2][2];

pair<int,int> add(pair<int,int> x,pair<int,int> y)
{
	pair<int,int> ans;
	ans.second=(x.second+y.second)%mod;
	ans.first=x.first+y.first+(x.second+y.second)/mod;
	return ans;
}

int sochuso(int x)
{
	int dem=0;
	if(x==0) return 1;
	while(x>0) dem++,x=x/10;

	return dem;
}

signed main()
{
	int n,k;
	cin >> n >> k;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			f[i][j][0][0]=make_pair(0,0);
			f[i][j][0][1]=make_pair(0,0);
			f[i][j][1][0]=make_pair(0,0);
			f[i][j][1][1]=make_pair(0,0);
		}
	}
	f[0][0][0][0]=make_pair(0,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(j+i+1>k)
			{
				f[i+1][0][1][1]=add(f[i+1][0][1][1],f[i][j][0][0]);
			}
			else
			{
				f[i+1][j+i+1][0][1]=add(f[i+1][j+i+1][0][1],f[i][j][0][0]);
			}
			f[i+1][j][0][0]=add(f[i+1][j][0][0],add(f[i][j][0][1],f[i][j][0][0]));
		}
		f[i+1][0][1][1]=add(f[i+1][0][1][1],f[i][0][1][0]);
		f[i+1][0][1][0]=add(f[i+1][0][1][0],add(f[i][0][1][0],f[i][0][1][1]));
	}
	// cout << f[1][1][0][1] << endl;
	// cout << f[0][0][0][0] << endl;
	pair<int,int> ans=add(f[n][0][1][0],f[n][0][1][1]);
	if(ans.first==0)
	{
		cout << ans.second << endl;
	}
	else
	{
		cout << ans.first;
		int ka=sochuso(ans.second);
		for(int i=1;i<=9-ka;i++) cout << 0;
			cout << ans.second << endl;
	}
	return 0;
}