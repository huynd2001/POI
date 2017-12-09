/*huypheu
8
2 3 2 2 6 7 8 5
*/

#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

int n;
int par[1000007],v[1000007];
bool root[1000007];
vector <int> loop[1000007];
int gr[1000007],gro=0;
int ans[1000007];
bool de[1000007];
bool vst[1000007];

void solve1()
{
	int an=0;
	queue<int> qu;
	for(int i=1;i<=n;i++) if(v[i]==0) qu.push(i),vst[i]=1;
	while(!qu.empty())
	{
		int s=qu.front();
		qu.pop();
		if(de[s]) continue;
		if(!de[par[s]])
		{
			an++;
			de[par[s]]=1;
			vst[par[s]]=1;
			v[par[par[s]]]--;
			if(v[par[par[s]]]==0 && !de[par[par[s]]]) qu.push(par[par[s]]),vst[par[par[s]]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			int p=gr[i];
			for(int j=0;j<loop[p].size();j++)
			{
				int k=loop[p][j];
				vst[k]=1;
			}
			an+=loop[p].size()/2+loop[p].size()%2;
		}
	}
	cout << an << " ";
	return ;
}

void solve2()
{
	for(int i=1;i<=n;i++) v[i]=0;
	for(int i=1;i<=n;i++) v[par[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0) ans[gr[i]]++;
	}
	// for(int i=1;i<=gro;i++) cout << ans[i] << " " << endl;
	int su=0;
	for(int i=1;i<=gro;i++)
	{
		if(ans[i]>0) su+=ans[i];
		else if(loop[i].size()==1) ; else su+=1;
	}
	cout << n-su << "\n";
	return ;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> par[i];
		v[par[i]]++;
	}
	// for(int i=1;i<=n;i++) cout << par[i] << " " ;
	// 	cout << endl;
	for(int i=1;i<=n;i++)
	{
		if(gr[i]==0)
		{
			int k=i;
			gr[k]=-1;
			while(gr[par[k]]==0) gr[par[k]]=-1,k=par[k];
			if(gr[par[k]]==-1)
			{
				k=par[k];
				gro++;
				gr[k]=gro;
				root[k]=1;
				loop[gro].push_back(k);
				// cout<< k << endl;
				while(gr[par[k]]==-1) k=par[k],root[k]=1,loop[gro].push_back(k),gr[k]=gro;
				k=i;
				gr[k]=gro;
				while(gr[par[k]]==-1) k=par[k],gr[k]=gro;
			}
			else
			{
				int l=gr[par[k]];
				k=i;
				gr[k]=l;
				while(gr[par[k]]==-1) k=par[k],gr[k]=l;
			}
		}
	}
	// cout << gro << endl;
	// for(int i=1;i<=gro;i++) 
	// {
	// 	for(int j=0;j<loop[i].size();j++) cout << loop[i][j] << " ";
	// 		cout << endl;
	// }
	solve1();
	solve2();
	return 0;
}