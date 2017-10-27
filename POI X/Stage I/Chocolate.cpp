#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

bool dcp(int x,int y)
{
	return (x>y);
}

int f[1007][1007];
int a[1007],b[1007];

int main()
{
	int n,m;
	cin >> n >> m;
	n--;
	m--;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];
	sort(a+1,a+n+1,dcp);
	sort(b+1,b+m+1,dcp);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=oo;
		}
	}
	f[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 && j==0) continue;
			if(i>=1) f[i][j]=min(f[i][j],f[i-1][j]+a[i]*(j+1));
			if(j>=1) f[i][j]=min(f[i][j],f[i][j-1]+b[j]*(i+1));
		}
	}
	cout << f[n][m] << endl;
	return 0;
}