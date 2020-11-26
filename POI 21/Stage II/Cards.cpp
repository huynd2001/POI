/*huypheu
4
2 5
3 4
6 3
2 7
2
3 4
1 3
*/

#include <bits/stdc++.h>
using namespace std;

bool it[1000007][2][2];
int ki[1000007][2][2];
int x[1000007][2];

void build(int node,int l,int r)
{
	if(l>r) return ;
	if(l==r)
	{
		ki[node][0][0]=x[l][0];
		ki[node][0][1]=x[l][1];
		ki[node][1][0]=x[l][0];
		ki[node][1][1]=x[l][1];
		it[node][1][1]=1;
		it[node][0][0]=1;
		it[node][0][1]=0;
		it[node][1][0]=0;
		return ;
	}
	it[node][1][1]=0;
	it[node][0][0]=0;
	it[node][0][1]=0;
	it[node][1][0]=0;
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int o=0;o<=1;o++)
				{
					if(it[node*2][i][j] && it[node*2+1][k][o] && ki[node*2][1][j]<=ki[node*2+1][0][k]) it[node][i][o]|=1;
				}
			}
		}
	}
	ki[node][0][0]=ki[node*2][0][0];
	ki[node][0][1]=ki[node*2][0][1];
	ki[node][1][0]=ki[node*2+1][1][0];
	ki[node][1][1]=ki[node*2+1][1][1];
	return ;
}

void update(int node,int l,int r,int ind,int x,int y)
{
	if(l>r || ind<l || r<ind) return ;
	if(l==r)
	{
		ki[node][1][0]=x;
		ki[node][0][0]=x;
		ki[node][0][1]=y;
		ki[node][1][1]=y;
		it[node][1][1]=1;
		it[node][0][0]=1;
		it[node][0][1]=0;
		it[node][1][0]=0;
		return ;
	}
	it[node][1][1]=0;
	it[node][0][0]=0;
	it[node][0][1]=0;
	it[node][1][0]=0;
	int mid=(l+r)/2;
	update(node*2,l,mid,ind,x,y);
	update(node*2+1,mid+1,r,ind,x,y);

	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int o=0;o<=1;o++)
				{
					if(it[node*2][i][j] && it[node*2+1][k][o] && ki[node*2][1][j]<=ki[node*2+1][0][k]) it[node][i][o]|=1;
				}
			}
		}
	}
	ki[node][0][0]=ki[node*2][0][0];
	ki[node][0][1]=ki[node*2][0][1];
	ki[node][1][0]=ki[node*2+1][1][0];
	ki[node][1][1]=ki[node*2+1][1][1];
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i][0] >> x[i][1];
		if(x[i][0]>x[i][1]) swap(x[i][0],x[i][1]);
	}
	build(1,1,n);
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin >> a >> b;
		swap(x[a][0],x[b][0]);
		swap(x[a][1],x[b][1]);
		update(1,1,n,a,x[a][0],x[a][1]);
		update(1,1,n,b,x[b][0],x[b][1]);
		if(it[1][0][0] || it[1][0][1] || it[1][1][0] || it[1][1][1]) cout << "TAK\n"; else cout << "NIE\n";
		// swap(x[a][0],x[b][0]);
		// swap(x[a][1],x[b][1]);
		// update(1,1,n,a,x[a][0],x[a][1]);
		// update(1,1,n,b,x[b][0],x[b][1]);
	}
	return 0;
}