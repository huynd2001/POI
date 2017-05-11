#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000007],dp[1000007];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=0;
	int maxim=0+a[1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=maxim;
		if(i<n) maxim=max(maxim,-dp[i]+a[i+1]);
	}		
	// cout << maxim << endl;
	cout << dp[n] << endl;
	return 0;
}
