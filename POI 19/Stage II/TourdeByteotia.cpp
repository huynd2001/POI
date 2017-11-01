#include <bits/stdc++.h>
using namespace std;

int a[2000007],b[2000007],par[1000007];
bool ok[2000007];
int gr[1000007];

int rooter(int x)
{
	int y=x;
	while(par[y]>0) y=par[y];
	if(y!=x) par[x]=y;
	return y;
}

void onion(int x,int y)
{
	x=rooter(x);y=rooter(y);
	if(par[x]>par[y]) swap(x,y);
	par[x]+=par[y];
	par[y]=x;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) par[i]=-1;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i] >> b[i];
		if(a[i]>k && b[i]>k && rooter(a[i])!=rooter(b[i]))
		{
			onion(a[i],b[i]);
		}			
	}
	for(int i=1;i<=n;i++)
	{
		gr[i]=rooter(i);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(gr[a[i]]!=gr[b[i]])
		{
			if(rooter(a[i])!=rooter(b[i]))
			{
				onion(a[i],b[i]);
			}
			else ans++,ok[i]=1;
		}
	}
	cout << ans << endl;
	for(int i=1;i<=m;i++)
	{
		if(ok[i]) cout << a[i] << " " << b[i] << endl;
	}
	return 0;
}