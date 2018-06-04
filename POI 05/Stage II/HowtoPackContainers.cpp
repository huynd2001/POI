#include <bits/stdc++.h>
using namespace std;

vector <int> vnone;
vector <int> v[100007];
int cnt[100007];

bool dcp(int x,int y)
{
	return (x>y);
}

int main()
{
	
	int n;
	cin >> n;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		ma=max(ma,a);
	}
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin >> a >> b;
		cnt[a]+=b;
		ma=max(ma,a);
	}
	int val=0;
	for(int i=0;i<=ma;i++)
	{
		sort(v[i].begin(),v[i].end());
		if(v[i].size()<cnt[i])
		{
			cout << "NIE\n";
			return 0;
		}
		else
		{
			for(int j=0;j<cnt[i];j++)
			{
				val+=v[i][j];
			}
			for(int j=cnt[i];j<(int)v[i].size()-1;j+=2)
			{
				v[i+1].push_back(v[i][j]+v[i][j+1]);
			}
			v[i]=vnone;
		}
	}
	cout << val << "\n";
	return 0;
}
