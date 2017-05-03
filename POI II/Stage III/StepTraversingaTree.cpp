#include <bits/stdc++.h>
using namespace std;

vector <int> v[5007];
int par[5007],h[5007];

void dfs(int node)
{
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(par[node]!=k)
		{
			h[k]=h[node]+1;
			par[k]=node;
			dfs(k);
		}
	}
	return ;
}

void dfsans(int node)
{
	if(h[node]%2==1) cout << node << "\n";
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(par[node]!=k)
		{
			dfsans(k);
		}
	}
	if(h[node]%2==0) cout << node << "\n";
	return ;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	dfsans(1);
	return 0;
}
