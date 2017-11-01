/*huypheu
4
0
2
0
0
*/

#include <bits/stdc++.h>
using namespace std;

int bit[40007];
int n,a[40007];
int ans[40007];
bool ok[40007];

void update(int inde,int kak)
{
	int j=inde;
	while(j<=n) 
	{
		// cout << j << endl;
		bit[j]+=kak;
		j+=j&(-j);
	}
	return ;
}

int get(int inde)
{
	int j=inde;
	int su=0;
	while(j>0)
	{
		su+=bit[j];
		// cout << j << endl;
		j-=j&(-j);
	}
	return su;
}

bool check(int k,int val)
{
	if(k==n+1) return 1;
	// if(ok[k]) return 0;
	int geto=get(k);
	// cout << geto << k << val << endl;
	if(geto>a[val]) return 1; else return 0;
}

int main()
{
	// int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) a[i]=i-1-a[i];
		// for(int i=1;i<=n;i++) cout << a[i] << " " ;
		// 	cout << endl;
	for(int i=n;i>=1;i--)
	{
		update(i,1);
		// cout << i << endl;
	}
	// cout << get(3) << endl;
	// cout << bit[1] << endl;
	// cout << get(1) << endl;
	for(int i=n;i>=1;i--)
	{
		// cout << i << endl;
		int l=1,r=n+1;
		while(l<r)
		{
			// cout << l << " " << r << endl;
			int mid=(l+r)/2;
			if(!check(mid,i)) l=mid+1; else r=mid;
		}
		if(l==n+1 || get(l-1)!=a[i])
		{
			// cout << i << endl;
			printf("NIE\n");
			return 0;
		}
		else
		{
			// cout << l << " " << i << endl;
			// cout << get(4) << endl;
			// cout << check(l,i) << " " << check(l-1,i) << endl;
			// cout << "concak" << endl;
			// cout << l << endl;
			// if(get(l-1)!=a[i])
			// {
			// 	cout << "NIE" << endl;
			// 	return 0;
			// }
			// // if()
			// cout << l << endl;
			ok[l]=1;
			ans[i]=l;
			update(l,-1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
}