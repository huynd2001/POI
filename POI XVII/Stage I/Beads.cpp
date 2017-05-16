/*huypheu
21
1 1 1 2 2 2 3 3 3 1 2 3 3 1 2 2 1 3 3 2 1
*/

#include <bits/stdc++.h>
#define int long long
#define mod 248439827
#define mod1 1000000009
using namespace std;

int ans[200007],a[200007],d[200007],su[200007];
int d1[200007],su1[200007];

signed main()
{
	int n;
	cin >> n;
	int pok=n+1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	d[0]=1;
	d1[0]=1;
	for(int i=1;i<=n;i++)
	{
		d[i]=(d[i-1]*pok)%mod;
		d1[i]=(d1[i-1]*pok)%mod1;
	}
	su[0]=0;
	su1[0]=0;
	for(int i=1;i<=n;i++)
	{
		su[i]=(su[i-1]+d[a[i]])%mod;
		su1[i]=(su1[i-1]+d1[a[i]])%mod1;
	}
	int dap_an=0,dem=0;
	for(int i=1;i<=n;i++)
	{
		set<pair<int,int> >se;
		int k=n/i;
		for(int j=1;j<=k;j++)
		{
			int st=(j-1)*i+1,ed=j*i;
			int ka=((su[ed]-su[st-1])%mod+mod)%mod;
			int ka1=((su1[ed]-su1[st-1])%mod1+mod1)%mod1;
			// if(i==2) cout << ka << endl;
			se.insert(make_pair(ka,ka1));
		}
		ans[i]=se.size();
		if(ans[i]>dap_an)
		{
			dap_an=ans[i];
			dem=1;
		}
		else
		{
			if(ans[i]==dap_an) dem++;
		}
	}
	cout << dap_an << " " << dem << endl;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==dap_an) cout << i << " ";
	}
	cout << endl;
	return 0;
}