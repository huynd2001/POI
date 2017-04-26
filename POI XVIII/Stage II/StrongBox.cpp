#include <bits/stdc++.h>
#define int long long
using namespace std;

// map <int,bool> good;
set<int> se;
vector <int> v,pri;
int m[250007];

int ucln(int x,int y)
{
	int i=x%y;
	while(i!=0)
	{
		x=y;
		y=i;
		i=(x%y);
	}
	return y;
}

void tinh_uoc(int n)
{
	int m=n;
	v.push_back(1);
	for(int i=2;i<sqrt(n);i++)
	{
//		cout << i << endl;
		if(n%i==0)
		{
			v.push_back(i);
			int dem=0;
			while(m%i==0)
			{
				dem++;
				m/=i;
//				cout << i << endl;
			}
			if(dem>=1) pri.push_back(i);
		}
	}
	if(m!=1) pri.push_back(m);
	int k=v.size()-1;
	if(floor(sqrt(n))==sqrt(n)) v.push_back((int)sqrt(n));
	for(int i=k;i>=0;i--)
	{
		v.push_back(n/v[i]);
	}
	return ;
}

signed main()
{
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=k;i++)
	{
		cin >> m[i];
		m[i]=ucln(m[i],n);
	}
	tinh_uoc(n);
//	cout << "done" << endl;
	for(int i=1;i<=k-1;i++)
	{
		se.insert(m[i]);
	}
//	for(int i=1;i<=k;i++)
//	{
//		cout << m[i] << " ";
//	}
//	cout << endl;
	int best=-1;
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		if(se.find(v[i])!=se.end())
		{
			for(int j=0;j<pri.size();j++)
			{
				if(v[i]%pri[j]==0)
				{
					se.insert(v[i]/pri[j]);
				}
			}
		}
		else if(m[k]%v[i]==0) best=max(best,n/v[i]);
	}
	cout << best << endl;
	return 0;
}
