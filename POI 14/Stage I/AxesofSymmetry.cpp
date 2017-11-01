#include <bits/stdc++.h>
#define int long long
#define cap 1000009
using namespace std;

int a[400007],b[400007];
int x[100007],y[100007];
int m1[400007];
int ha1[400007];
int hb1[400007];

bool check(int p,int q,int s,int t)
{
	if(p<s)
	{
		return (((ha1[q]*m1[t-q])-(ha1[p-1]*m1[s-p]))==(hb1[t]-hb1[s-1]));
	}
	else
	{
		return ((ha1[q]-ha1[p-1])==((hb1[t]*m1[q-t])-(hb1[s-1]*m1[p-s])));
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> x[i] >> y[i];
		}
		for(int i=0;i<n;i++)
		{
			a[i*2+1]=(x[(i+1)%n]-x[i%n])*(x[(i+1)%n]-x[i%n])+(y[(i+1)%n]-y[i%n])*(y[(i+1)%n]-y[i%n]);
			a[i*2+2]=(x[(i+1)%n]-x[i%n])*(y[(i+2)%n]-y[i%n])-(x[(i+2)%n]-x[i%n])*(y[(i+1)%n]-y[i%n]);
		}
		for(int i=n;i<2*n;i++)
		{
			a[i*2+1]=a[(i-n)*2+1];
			a[i*2+2]=a[(i-n)*2+2];
		}
		for(int i=0;i<n;i++)
		{
			int j=n-i;
			b[i*2+1]=(x[j%n]-x[(j-1+n)%n])*(x[j%n]-x[(j-1+n)%n])+(y[j%n]-y[(j-1+n)%n])*(y[j%n]-y[(j-1+n)%n]);
			b[i*2+2]=(x[(j-1+n)%n]-x[(j-2+n)%n])*(y[j%n]-y[(j-2+n)%n])-(x[j%n]-x[(j-2+n)%n])*(y[(j-1+n)%n]-y[(j-2+n)%n]);
		}
		for(int i=n;i<2*n;i++)
		{
			b[i*2+1]=b[(i-n)*2+1];
			b[i*2+2]=b[(i-n)*2+2];
		}
		m1[0]=1;
		for(int i=1;i<=4*n;i++) m1[i]=(m1[i-1]*cap);
		for(int i=1;i<=4*n;i++)
		{
			ha1[i]=(ha1[i-1]+(a[i]*m1[i]));
			hb1[i]=(hb1[i-1]+(b[i]*m1[i]));
		}
		int dem=0;
		int len=n-1;
		for(int i=1;i<=2*n;i++)
		{
			if(check(i,i+len-1,2*n+2-i,2*n-i+1+len)) dem++;
		}
		cout << dem/2 << endl;
	}
	return 0;
}