/*huypheu
5
1 2
1 3
2 2
2 5
1 4
*/

#include <bits/stdc++.h>
using namespace std;

int w[250007],d[250007];
int it[2000007];
int n;

void build(int node,int l,int r)
{
	if(l>r) return ;
	if(l==r)
	{
		it[node]=l;
		return ;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	if(w[it[node*2]]<w[it[node*2+1]]) it[node]=it[node*2]; else it[node]=it[node*2+1];
}

int get(int node,int l,int r,int x,int y)
{
	if(l>r || y<l || r<x) return 0;
	if(x<=l && r<=y) return it[node];
	int mid=(l+r)/2;
	int a=get(node*2,l,mid,x,y),b=get(node*2+1,mid+1,r,x,y);
	// cout << "!@# "<< a << " " << b << endl;
	if(a==0) return b;
	if(b==0) return a;
	if(w[a]<w[b]) return a; else return b;

}

int ans(int i,int j,int h)
{
	if(i>j) return 0;
	// cout << i << " " << j << endl;
	int mi=get(1,1,n,i,j);
	// cout << i << " " << j << " " << mi << endl;
	int ak=ans(i,mi-1,w[mi])+ans(mi+1,j,w[mi]);
	if(w[mi]>h) ak++;
	return ak;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> d[i] >> w[i] ;
	}
	// cout << "lz" << endl;
	build(1,1,n);
	cout << ans(1,n,0) << endl;
	return 0;
}