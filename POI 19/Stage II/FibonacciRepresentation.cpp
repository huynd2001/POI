#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[100007];
int cnt;

int ans(int k)
{
	if(k==0) return 0;
	int l=0,r=cnt;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(f[mid]<k) l=mid+1; else r=mid;
	}
	int lap;
	lap=min(f[l]-k,k-f[l-1]);
	return ans(lap)+1;
}

signed main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		f[0]=0;
		f[1]=1;
		cnt=2;
		f[2]=1;
		while(f[cnt]<n)
		{
			cnt++;
			f[cnt]=f[cnt-1]+f[cnt-2];
		}
		cout << ans(n) << endl;
	}
	return 0;
}
