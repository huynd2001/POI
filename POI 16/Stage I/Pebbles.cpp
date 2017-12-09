#include <bits/stdc++.h>
using namespace std;

int d[10007],a[1007];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int x=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		for(int i=1;i<=n;i++)
		{
			d[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			if(i%2==n%2) x=x^d[i]; 
		}
		if(x==0) cout << "NIE\n"; else cout << "TAK\n";
	}
	return 0;
}