/*huypheu
5 2
1
1
1
1
1
*/

#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int a[100007],it[400007];
int su[400007];
int pos[100007],cap[100007];
int v[100007];

void update(int node,int l,int r,int x,int y)
{
	if(l>r || x<l || r<x) return ;
	if(l==r)
	{
		it[node]+=y;
		su[node]=it[node]*a[cap[l]];
		return ;
	}
	int mid=(l+r)/2;
	update(node*2,l,mid,x,y);
	update(node*2+1,mid+1,r,x,y);
	it[node]=it[node*2]+it[node*2+1];
	su[node]=su[node*2]+su[node*2+1];
	return ;
}

int getsu(int node,int l,int r,int x,int y)
{
	if(l>r || y<l || r<x) return 0;
	if(x<=l && r<=y) return su[node];
	int mid=(l+r)/2;
	return (getsu(node*2,l,mid,x,y)+getsu(node*2+1,mid+1,r,x,y));
}

int cra(int node,int l,int r,int k)
{
	if(l>r) return 0;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(k<=it[node*2]) return cra(node*2,l,mid,k); else return cra(node*2+1,mid+1,r,k-it[node*2]);
}

bool dcp(int x,int y) 
{
	return (a[x]<a[y]);
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	int n,k;
	// cin >> n >> k;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		// cin >> a[i];
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++) v[i]=i;
	sort(v+1,v+n+1,dcp);
	for(int i=1;i<=n;i++) pos[v[i]]=i,cap[i]=v[i];
	for(int i=1;i<=k;i++)
	{
		update(1,1,n,pos[i],1);
	}
	int ans=oo;
	int ja=0;
	int ans2=0;
	for(int i=1;i<=n-k+1;i++)
	{
		int j=cra(1,1,n,k/2+k%2);
		int cal=a[cap[j]]*(k/2+k%2)+su[1]-2*getsu(1,1,n,1,j)-a[cap[j]]*(k-k/2-k%2);
		if(ans>cal)
		{
			ja=i;
			ans=cal;
			ans2=cap[j];
		}
		if(i==(n-k+1)) continue;
		update(1,1,n,pos[i],-1);
		update(1,1,n,pos[i+k],1);
	}
	// cout << ans << "\n";
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(ja<=i && i<=ja+k-1) /*cout << a[ans2] << "\n"*/printf("%lld\n",a[ans2]); else /*cout << a[i] << "\n"*/printf("%lld\n",a[i]);
	}
	return 0;
}