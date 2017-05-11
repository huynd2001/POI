#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

int a[1000007],dp[1000007][3];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=oo;dp[i][1]=oo;dp[i][2]=oo;
		// pd[i][0]=oo;pd[i][1]=oo;pd[i][2]=oo;
	}
	dp[1][a[1]+1]=0;
	for(int i=2;i<=n;i++)
	{
		switch(a[i])
		{
			case -1 :
				dp[i][2]=min(dp[i-1][2]+2,dp[i][2]);
				// dp[i][1]=min(dp[i-1][2]+1,dp[i][1]);
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				break;
			case 0 :
				dp[i][2]=min(dp[i-1][2]+1,dp[i][2]);
				dp[i][1]=min(dp[i-1][0],dp[i][1]);
				dp[i][1]=min(dp[i-1][1],dp[i][1]);
				dp[i][0]=min(dp[i-1][0]+1,dp[i][0]);
				break;
			case 1 :
				dp[i][2]=min(dp[i-1][2],dp[i][2]);
				dp[i][2]=min(dp[i-1][1],dp[i][2]);
				dp[i][2]=min(dp[i-1][0],dp[i][2]);
				dp[i][1]=min(dp[i-1][0]+1,dp[i][1]);
				dp[i][0]=min(dp[i-1][0]+2,dp[i][0]);
		}
	}
//	cout << dp[3][0] << endl;
	int ans=min(dp[n][1],min(dp[n][2],dp[n][0]));
	if(ans!=oo) cout << ans << endl; else cout << "BRAK" << endl;
	return 0;
}
