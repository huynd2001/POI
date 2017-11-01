/*huypheu
aba
7
*/

#include <bits/stdc++.h>
using namespace std;

bool ok[207][37][2]={0};
vector <int> dem[207];
vector <int> add(vector <int> x,vector <int> y)
{
	while(x.size()<y.size()) x.push_back(0);
	while(x.size()>y.size()) y.push_back(0);
	vector <int> ans;
	int carry=0;
	for(int i=0;i<x.size();i++)
	{
		ans.push_back((x[i]+y[i]+carry)%10);
		carry=(x[i]+y[i]+carry)/10;
	}
	if(carry!=0) ans.push_back(carry);
	return ans;
}
vector <int> donvi;

void prep()
{
	donvi.push_back(1);
	return ;
}

void printa(vector <int> v)
{
	if(v.size()==0) cout << 0 << endl;
	else
	{
		for(int i=(int)v.size()-1;i>=0;i--) cout << v[i] ;
			cout << endl;
	}
	return ;
}

signed main()
{
	string s;
	prep();
	cin >> s;
	int cnt=1;
	string ka="b",kb="a",kc;
	int n;
	cin >> n;
	while(ka.size()<s.size())
	{
		cnt++;
		kc=kb+ka;
		ka=kb;
		kb=kc;
	}
	// cout << ka << " " << kb << endl;
	// cout << cnt << endl;
	int m=s.size();
	for(int i=1;i<m;i++)
	{
		ok[cnt][i][0]=1;
		for(int j=1;j<=i;j++)
		{
			if(ka[j-1]!=s[m-i+j-1])
			{
				ok[cnt][i][0]=0;
				break;
			}
		}
		ok[cnt][i][1]=1;
		for(int j=1;j<=i;j++)
		{
			if(ka[ka.size()-i+j-1]!=s[j-1])
			{
				ok[cnt][i][1]=0;
				break;
			}
		}
	}
	for(int i=1;i<m;i++)
	{
		ok[cnt+1][i][0]=1;
		for(int j=1;j<=i;j++)
		{
			if(kb[j-1]!=s[m-i+j-1])
			{
				ok[cnt+1][i][0]=0;
				break;
			}
		}
		ok[cnt+1][i][1]=1;
		for(int j=1;j<=i;j++)
		{
			if(kb[kb.size()-i+j-1]!=s[j-1])
			{
				ok[cnt+1][i][1]=0;
				break;
			}
		}
	}
	for(int i=0;i<ka.size()-m+1;i++)
	{
		bool okt=1;
		for(int j=1;j<=m;j++)
		{
			if(ka[i+j-1]!=s[j-1])
			{
				okt=0;
				break;
			}
		}
		if(okt) dem[cnt]=add(dem[cnt],donvi);
	}
	for(int i=0;i<kb.size()-m+1;i++)
	{
		bool okt=1;
		for(int j=1;j<=m;j++)
		{
			if(kb[i+j-1]!=s[j-1])
			{
				okt=0;
				break;
			}
		}
		if(okt) dem[cnt+1]=add(dem[cnt+1],donvi);
	}
	// cout << n << endl;
	for(int i=cnt+2;i<=n;i++)
	{
		// cout << i << endl;
		dem[i]=add(dem[i-1],dem[i-2]);
		for(int j=1;j<m;j++)
		{
			if(ok[i-1][j][1] && ok[i-2][m-j][0]) dem[i]=add(dem[i],donvi);
		}
		for(int j=1;j<m;j++)
		{
			ok[i][j][0]=ok[i-1][j][0];
			ok[i][j][1]=ok[i-2][j][1];
		}
	}
	// cout << ok[5][2][0] << endl;
	printa(dem[n]);
	return 0;
}