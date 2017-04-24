#include <bits/stdc++.h>
using namespace std;

vector <int> v[500007];
int a[500007];
int su[500007][20];

bool check(int x,int l,int r)
{
	if(v[x].size()==0) return 0;
	if(v[x][v[x].size()-1]<l) return 0;
	int p=0,q=v[x].size()-1;
	while(p<q)
	{
		int mid=(p+q)/2;
		if(v[x][mid]<l) p=mid+1; else q=mid;
	}
	int o1=p,o2;
	p=0,q=v[x].size()-1;
	if(v[x][v[x].size()-1]<=r) o2=v[x].size()-1;
	else
	{
		while(p<q)
		{
			int mid=(p+q)/2;
			if(v[x][mid]>r) q=mid; else p=mid+1;
		}
		o2=q-1;
	}
	// cout << o1 << " " << o2 << endl;
	if((o2-o1+1)>(r-l+1)/2) return 1; else return 0;
}

int main()
{
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	int core=1;
	for(int i=0;i<=16;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]&core)
			{
				su[j][i]=su[j-1][i]+1;
			}
			else su[j][i]=su[j-1][i];
		}
		core*=2;
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin >> l >> r;
		core=1;
		int num=0;
		bool ok=1;
		for(int i=0;i<=16;i++)
		{
			if(su[r][i]-su[l-1][i]>(r-l+1)/2)
			{
				num+=core;
			}
			if(su[r][i]-su[l-1][i]==(r-l+1)/2 && (r-l+1)%2==0)
			{
				ok=0;
				break;
			}
			core*=2;
		}
		if(ok && check(num,l,r)) cout << num << endl; else cout << 0 << endl;
	}
	return 0;
}
