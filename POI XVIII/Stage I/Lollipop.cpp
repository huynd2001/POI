#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;

int a[1000007],s[1000007];
pair<int,int> ans[2000007];
//int q[1000007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
	{
		char ch;
		cin >> ch;
		if(ch=='T') a[i]=2; else a[i]=1;
	}
	int miev=0,miod=-1;
	int maev=0,maod=-1;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		if(s[i]%2==0)
		{
			maev=i;
		}
		else
		{
			if(miod==-1) miod=i;
			maod=i;
		}
	}
	int x,y;
	if(miod==-1)
	{
		x=miev;
		y=maev;
	}
	else
	{
		if(s[maev]-s[miev]>s[maod]-s[miod])
		{
			x=miev;
			y=maev;
		}
		else
		{
			x=miod;
			y=maod;
		}
	}
	int tot=s[y]-s[x];
	while(tot>0)
	{
		ans[tot]=make_pair(x+1,y);
		tot-=2;
		if(a[y]==2)
		{
			y--;
		}
		else
		{
			if(a[x+1]==2)
			{
				x++;
			}
			else
			{
				y--;
				x++;
			}
		}
	}
	if(miod!=-1)
	{
		if(s[maev]-s[miod]>s[maod]-s[miev])
		{
			x=miod;
			y=maev;
		}
		else
		{
			x=miev;
			y=maod;
		}
		tot=s[y]-s[x];
		while(tot>0)
		{
			ans[tot]=make_pair(x+1,y);
			tot-=2;
			if(a[y]==2)
			{
				y--;
			}
			else
			{
				if(a[x+1]==2)
				{
					x++;
				}
				else
				{
					y--;
					x++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int k;
		cin >> k;
		if(k==0) cout << 2 << " " << 1 << endl; else
		if(ans[k].first==0) cout << "NIE" << endl; else cout << ans[k].first << " " << ans[k].second << endl;
	}
	return 0;
}
