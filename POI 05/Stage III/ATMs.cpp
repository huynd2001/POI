#include <bits/stdc++.h>
using namespace std;

vector <int> ar[107];
int dem[107],cnt[107];

vector <int> tich(vector <int> x,vector <int> y)
{
	int it[1007]={0};
	for(int i=0;i<x.size();i++)
	{
		for(int j=0;j<y.size();j++)
		{
			it[i+j]+=x[i]*y[j];
		}
	}
	vector <int> ans;
	for(int i=0;i<=(int)x.size()+(int)y.size()-2;i++)
	{
		ans.push_back(it[i]%100000);
		it[i+1]+=it[i]/100000;
	}
	int p=(int)x.size()+(int)y.size()-1;
	while(it[p]>0)
	{
		ans.push_back(it[p]%100000);
		it[p]/=100000;
	}
	return ans;
}

vector <int> tong(vector <int> x,vector <int> y)
{
	while(x.size()<y.size()) x.push_back(0);
	while(y.size()<x.size()) y.push_back(0);
	int carry=0;
	vector <int> ans;
	for(int i=0;i<x.size();i++)
	{
		ans.push_back((x[i]+y[i]+carry)%100000);
		carry=(x[i]+y[i]+carry)/100000;
	}
	if(carry>0) ans.push_back(carry);
}

bool nho_hon_hoac_bang(vector <int> x,vector <int> y)
{
	if(x.size()!=y.size()) return (x.size()<y.size()); 
	else for(int i=(int)x.size()-1;i>=0;i--)
	{
		if(x[i]!=y[i]) return (x[i]<y[i]);
	}
	return 1;
}

vector <int> hieu(vector <int> x,vector <int> y)
{
	while(x.size()<y.size()) x.push_back(0);
	while(y.size()<x.size()) y.push_back(0);
	int carry=0;
	vector <int> ans;
	for(int i=0;i<x.size();i++)
	{
		y[i]+=carry,carry=0;
		if(x[i]<y[i]) carry++,x[i]+=100000;
		ans.push_back(x[i]-y[i]);
	}
	while(ans[ans.size()-1]==0) ans.pop_back();
	return ans;
}

void solve()
{
	string s;
	cin >> s;
	vector <int> va;
	int ka=0;
	int demk=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		ka=ka+(int(s[i])-int('0'))*demk;
		if(i==0 || (s.size()-1-i)%5==4) va.push_back(ka),ka=0,demk=1; else demk*=10;
	}
	for(int i=0;i<=102;i++) cnt[i]=0,dem[i]=0;
	for(int i=102;i>=0;i--)
	{
		if(nho_hon_hoac_bang(ar[i],va)) cnt[i]=1,dem[i]=1,va=hieu(va,ar[i]); else cnt[i]=0,dem[i]=0;
	}
	vector <int> ans;
	for(int i=0;i<=102;i++)
	{
		cnt[i+1]+=cnt[i]/2;
		if(i%2==0)
		{
			if(cnt[i]==1) ans.push_back(i);
		}
		else
		{
			if(cnt[i]==1) cnt[i+1]++,ans.push_back(i);
		}
	}
	if(ans.size()==0) ;
	else
	{
		if(ans[ans.size()-1]>99) cout << "NIE"; else for(int i=(int)ans.size()-1;i>=0;i--) cout << ans[i] << " ";
	}
	cout << "\n";
	ans.clear();
	for(int i=0;i<=102;i++)
	{
		dem[i+1]+=dem[i]/2;
		if(i%2==1)
		{
			if(dem[i]==1) ans.push_back(i);
		}
		else
		{
			if(dem[i]==1) dem[i+1]++,ans.push_back(i);
		}
	}
	if(ans.size()==0) ;
	else
	{
		if(ans[ans.size()-1]>99) cout << "NIE"; else for(int i=(int)ans.size()-1;i>=0;i--) cout << ans[i] << " ";
	}
	cout << "\n";
	return ;
}

int main()
{
	ar[0].push_back(1);
	vector <int> hai;
	hai.push_back(2);
	for(int i=1;i<=102;i++)
	{
		ar[i]=tich(ar[i-1],hai);
	}
	int test;
	
	cin >> test;
	while(test--) solve();
	return 0;
}