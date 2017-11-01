#include <bits/stdc++.h>
using namespace std;

int jum[250007],soz[250007];
int par[250007];
bool vst[250007];
int peak;
int tim[250007];
vector <int> v[250007];
int bit[250007];
int n;

void dfs(int node)
{
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		dfs(k);
		soz[node]+=soz[k];
	}
	soz[node]++;
	return ;
}

void hld(int node,bool ok)
{
	if(ok)
	{
		jum[node]=node;
	}
	else
	{
		jum[node]=jum[par[node]];
	}
	peak++;
	tim[node]=peak;
	int c=0;
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(c==0 || soz[c]<soz[k]) c=k;
	}
	if(c==0) return ;
	hld(c,0);
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(k!=c) hld(k,1);
	}
	return ;
}

void update(int x,int y)
{
	while(x<=n)
	{
		bit[x]+=y;
		x+=x&(-x);
	}
	return ;
}

int get(int x)
{
	int su=0;
	while(x>0)
	{
		su+=bit[x];
		x-=x&(-x);
	}
	return su;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		par[b]=a;
		v[a].push_back(b);
	}
	dfs(1);
	hld(1,1);
	int q;
	cin >> q;
	for(int i=1;i<=n;i++) update(i,1);
	for(int i=1;i<=q+n-1;i++)
	{
		char ch;
		cin >> ch;
		switch(ch)
		{
			case 'A' :
				int x,y;
				cin >> x >> y;
				if(par[x]==y) update(tim[x],-1); else update(tim[y],-1);
				break;
			case 'W' :
				int a;
				cin >> a;
				int su=0;
				while(a!=0)
				{
					su += get(tim[a])-get(tim[jum[a]]-1);
					a = par[jum[a]];
				}
				cout << su - 1 << "\n";
				break;
		}
	}
	return 0;
}