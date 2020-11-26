#include <bits/stdc++.h>
#define int long long
using namespace std;

int par[500007],ar[500007],ma[500007],su[500007];
vector <int> v[500007],chil[500007];

bool dcp(int x,int y)
{
	return (max(ma[x]+1,ma[y]+su[x]+3)<max(ma[x]+su[y]+3,ma[y]+1));
}

void dfs(int node)
{
	// cout << node << endl;
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(par[node]!=k) chil[node].push_back(k),par[k]=node,dfs(k);
	}
	sort(chil[node].begin(),chil[node].end(),dcp);
	int trav=0;
	ma[node]=ar[node];
	for(int i=0;i<chil[node].size();i++)
	{
		int k=chil[node][i];
		ma[node]=max(ma[node],1+trav+ma[k]);
		trav+=su[k]+2;
		su[node]+=su[k]+2;
	}
	return ;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> ar[i];
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << max(ma[1],ar[1]+2*n-2) << endl;
	return 0;
}
