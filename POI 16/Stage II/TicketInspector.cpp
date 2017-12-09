/*huypheu
7 2
2 1 8 2 1 0
3 5 1 0 1
3 1 2 2
3 5 6
3 2
1
*/

#include <bits/stdc++.h>
#define int int64_t
#define oo (LONG_MAX/2)
using namespace std;

int c[607][607],s[607][607],dp[607][57],pre[607][57];

signed main()
{
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cin >> c[i][i+j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int su=0;
		for(int j=1;j<=n;j++)
		{
			su+=c[i][j];
			s[i][j]=s[i-1][j]+su;
		}
	}
	for(int i=1;i<=k;i++)
	{
		dp[0][i]=-oo;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int l=0;l<i;l++)
			{
				if(dp[i][j]<dp[l][j-1]+s[i][n]-s[l][n]-s[i][i]+s[l][i])
				{
					pre[i][j]=l;
					dp[i][j]=dp[l][j-1]+s[i][n]-s[l][n]-s[i][i]+s[l][i];
				}
			}
		}
	}
	int ans=0;
	int p=0;
	for(int i=0;i<=n;i++)
	{
		if(ans<dp[i][k])
		{
			p=i;
			ans=dp[i][k];
		}
	}
	// cout << p << endl;
	vector <int> v;
	while(p!=0)
	{
		v.push_back(p);
		p=pre[p][k];
		k--;
	}
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}