/*huypheu
6
0 1 2
2 4 3
4 2 0
0 5 4
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
	return (x > y);
}

int par[1007],d[1007],h[1007];
vector <int> v[1007],ar[1007][1007];
int ans;

void dfs(int node)
{
	int mi1=0,mi2=0;
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(k!=par[node])
		{
			par[k]=node,h[k]=h[node]+1;
			dfs(k);
			d[node]=max(d[node],d[k]+1);
			if(d[k]+1>mi1)
			{
				mi2=mi1;
				mi1=d[k]+1;
			} 
			else
			{
				if(d[k]+1>mi2)
				{
					mi2=d[k]+1;
				}
			}
		}
	}
	ans=max(ans,h[node]+mi1+mi2);
	return ;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n-2;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		ar[min(a,b)][max(a,b)].push_back(i);
		ar[min(a,c)][max(a,c)].push_back(i);
		ar[min(c,b)][max(c,b)].push_back(i);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			if(ar[i][j].size()==2)
			{
				v[ar[i][j][0]].push_back(ar[i][j][1]);
				v[ar[i][j][1]].push_back(ar[i][j][0]);
			}
		}
	}
	ans=0;
	// for(int i=1;i<=n-2;i++)
	// {
	// 	cout << i << " : " ;
	// 	for(int j=0;j<v[i].size();j++) cout << v[i][j] << " ";
	// 		cout << endl;
	// }
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1;j<=n-2;j++) par[j]=0,h[j]=0,d[j]=0;
		dfs(i);
	}
	cout << ans+1 << endl;
	return 0;
}