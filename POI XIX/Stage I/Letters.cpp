#include <bits/stdc++.h>
// #define int long long
using namespace std;

char ch1[1000005],ch2[1000005];
int pos[1000007];
int a[1000005],n;
vector <int> v[30];
int bit[1000007];

int get(int k)
{
	int su=0;
	while(k>0)
	{
		su+=bit[k];
		k-=k&(-k);
	}
	
	return su;
}

void update(int k,int y)
{
	while(k<=n)
	{
		bit[k]+=y;
		k+=k&(-k);
	}
	return ;
}

int main()
{
	// int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> ch1[i];
	for(int i=1;i<=n;i++) cin >> ch2[i];
	for(int i=n;i>=1;i--)
	{
		v[int(ch2[i])-int('A')].push_back(i);
	}		
	for(int i=1;i<=n;i++)
	{
		a[i]=v[int(ch1[i])-int('A')][v[int(ch1[i])-int('A')].size()-1];
		v[int(ch1[i])-int('A')].pop_back();
	}
	for(int i=1;i<=n;i++)
	{
		pos[a[i]]=i;
		// cout << a[i] << endl;
	}
	int64_t ans=0;
	for(int i=n;i>=1;i--)
	{
		ans+=get(pos[i]);
		update(pos[i],1);
	}
	cout << ans << endl;
	return 0;
}
