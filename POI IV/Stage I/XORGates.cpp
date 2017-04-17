/*huypheu
5 6 5
-1 -2
1 3
1 -2
2 -3
4 6
-4 -5
00111
01110
*/

#include <bits/stdc++.h>
using namespace std;

bool vst[3007]={0};
int dem[3007][107];
pair<int,int> a[3007];
int n;

bool difin(vector <int> x,vector <int> y)
{
	if(x.size()!=y.size()) return 1;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]!=y[i]) return 1;
	}
	return 0;
}

void dfs(int node)
{
	int k=a[node].first;
	vst[node]=1;
	if(k<0)
	{
		dem[node][-k]++;
	}
	else
	{
		if(!vst[k])
		{
			dfs(k);
		}
		for(int i=1;i<=n;i++)
		{
			dem[node][i]=(dem[node][i]+dem[k][i])%2;
		}
	}
	k=a[node].second;
	// vst[node]=1;
	if(k<0)
	{
		dem[node][-k]++;
	}
	else
	{
		if(!vst[k])
		{
			dfs(k);
		}
		for(int i=1;i<=n;i++)
		{
			dem[node][i]=(dem[node][i]+dem[k][i])%2;
		}
	}
	return ;
}

vector <int> v1,v2;
vector <int> incre(vector <int> vo)
{
	vector <int> v=vo;
	int k=(int)v.size()-1;
	while(v[k]==1) k--;
	v[k]=1;
	for(int i=k+1;i<v.size();i++)
	{
		v[i]=0;
	}
	return v;
}

int main()
{
	int m,k;
	cin >> n >> m >> k;
	// cout << "cak" << endl;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	// cout << "cak" << endl;
	dfs(k);
	// cout << "cak" << endl;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		// cout << ch << endl;
		v1.push_back(int(ch)-int('0'));
	}
	// cout << "cak" << endl;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		v2.push_back(int(ch)-int('0'));
	}
	int ans=0;
	// for(int i=0;i<v1.size();i++) cout << v1[i];
	// 		cout << endl;
	// cout << "cak" << endl;
	while(difin(v1,v2))
	{
		// cout << "concak" << endl;
		int su=0;
		for(int i=1;i<=n;i++)
		{
			// cout << i << endl;
			su=(su+dem[k][i]*v1[i-1])%2;
		}
		ans+=su;
		// for(int i=0;i<v1.size();i++) cout << v1[i];
		// 	cout << endl;
		v1=incre(v1);
	}
	// cout << "done" << endl;
	int su=0;
	for(int i=1;i<=n;i++)
	{
		su=(su+dem[k][i]*v1[i-1])%2;
	}
	ans+=su;
	cout << ans << endl;
	return 0;
}