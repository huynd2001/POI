#include <bits/stdc++.h>
using namespace std;

vector <int> v[1000007];
int ar[1000007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		v[a].push_back(i);
	}
	int k;
	cin >> k;
	for(int i=1;i<=k;i++)
	{
		int m;
		cin >> m;
		int cur=0;
		bool ok=0;
		for(int j=1;j<=m;j++)
		{
			cin >> ar[j];
		}
		for(int j=1;j<=m;j++)
		{
			int a;
			a=ar[j];
			// cin >> a;
			if(v[a].size()==0) break;
			if(v[a][v[a].size()-1]<=cur) break;
			int l=0,r=v[a].size()-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(v[a][mid]<=cur) l=mid+1; else r=mid;
			}
			cur=v[a][l];
			if(j==m) ok=1;
		}
		if(ok) cout << "TAK\n"; else cout << "NIE\n";
	}
	return 0;
}
