/*huypheu
2
1
0
*/

#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

int f[107][10][10]={0};
	int ban[107];
int g[107][10][10][300]={0};

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> ban[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<8;k++)
			{
				f[i][j][k]=-oo;
			}
		}
	}
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int mask1=0;mask1<8;mask1++)
		{
			for(int mask2=0;mask2<8;mask2++)
			{
				for(int mask3=0;mask3<8;mask3++)
				{
					if(i-2>=1)
					{
						if(ban[i-2]!=0 && mask1&(1<<(ban[i-2]-1))) continue;
					}
					if(i-1>=1)
					{
						if(ban[i-1]!=0 && mask2&(1<<(ban[i-1]-1))) continue;
					}
					if(ban[i]!=0 && mask3&(1<<(ban[i]-1))) continue;
					if(mask1&1)
					{
						if(mask2&4 || mask3&2) continue;
					}
					if(mask1&2)
					{
						if(mask3&1 || mask3&4) continue;
					}
					if(mask1&4)
					{
						if(mask2&1 || mask3&2) continue;
					}
					if(mask2&1 && mask3&4) continue;
					if(mask2&4 && mask3&1) continue;
					int su=0;
					if(mask3&1) su++;
					if(mask3&2) su++;
					if(mask3&4) su++;
					f[i][mask2][mask3]=max(f[i][mask2][mask3],f[i-1][mask1][mask2]+su);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			ans=max(ans,f[n][i][j]);
			// cout << i << " " << j << " " << f[n][i][j] << endl;
		}
	}
	cout << ans << " ";
	g[0][0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int mask1=0;mask1<8;mask1++)
		{
			for(int mask2=0;mask2<8;mask2++)
			{
				for(int mask3=0;mask3<8;mask3++)
				{
					if(i-2>=1)
					{
						if(ban[i-2]!=0 && mask1&(1<<(ban[i-2]-1))) continue;
					}
					if(i-1>=1)
					{
						if(ban[i-1]!=0 && mask2&(1<<(ban[i-1]-1))) continue;
					}
					if(ban[i]!=0 && mask3&(1<<(ban[i]-1))) continue;
					if(mask1&1)
					{
						if(mask2&4 || mask3&2) continue;
					}
					if(mask1&2)
					{
						if(mask3&1 || mask3&4) continue;
					}
					if(mask1&4)
					{
						if(mask2&1 || mask3&2) continue;
					}
					if(mask2&1 && mask3&4) continue;
					if(mask2&4 && mask3&1) continue;
					int su=0;
					if(mask3&1) su++;
					if(mask3&2) su++;
					if(mask3&4) su++;
					for(int k=0;k<=ans-su;k++)
					{
						g[i][mask2][mask3][k+su]+=g[i-1][mask1][mask2][k];
					}
				}
			}
		}
	}
	int kk=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			kk+=g[n][i][j][ans];
		}
	}
	cout << kk << endl;
	return 0;
}