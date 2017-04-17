/*huypheu
4
4
1 2
2 3
3 4
4 15
4
1 2
2 3
3 4
4 1
*/

#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

vector <int> v[3007],v2[3007],grope[3007];
int gr[3007];
bool inst[3007];
int dow[3007],tim[3007],peak=0;
int pa[8007],pb[8007];
int cost[3007],costo[3007];
stack<int>st;
int cnt=0;

void tplt(int node)
{
	st.push(node);
	inst[node]=1;
	peak++;
	dow[node]=peak;
	tim[node]=peak;
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		if(tim[k]==0)
		{
			tplt(k);
			dow[node]=min(dow[node],dow[k]);
		}
		else if(inst[k]) dow[node]=min(dow[node],tim[k]);
	}
	if(dow[node]==tim[node])
	{
		cnt++;
		gr[node]=cnt;
		grope[cnt].push_back(node);
		while(!st.empty() && st.top()!=node)
		{
			int k=st.top();
			st.pop();
			gr[k]=cnt;
			inst[k]=0;
			grope[cnt].push_back(k);
		}
		st.pop();
		inst[node]=0;
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	int p;
	cin >> p;
	for(int i=1;i<=n;i++) cost[i]=oo;
	for(int i=1;i<=p;i++)
	{
		int a,b;
		cin >> a >> b;
		cost[a]=b;
	}
	int r;
	cin >> r;
	for(int i=1;i<=r;i++)
	{
		cin >> pa[i] >> pb[i];
		v[pa[i]].push_back(pb[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(tim[i]==0)
		{
			peak=0;
			tplt(i);
		}
	}
	// for(int i=1;i<=n;i++) cout << gr[i] << " ";
	// cout << endl;
	set<pair<int,int> > se;
	for(int i=1;i<=r;i++)
	{
		int a,b;
		a=gr[pa[i]];
		b=gr[pb[i]];
		if(a==b) continue;
		if(se.find(make_pair(a,b))==se.end())
		{
			v2[b].push_back(a);
			se.insert(make_pair(a,b));
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		costo[i]=oo;
	}
	for(int i=1;i<=n;i++)
	{
		costo[gr[i]]=min(costo[gr[i]],cost[i]);
	}
	int su=0;
	// cout << cnt << endl;
	// for(int i=1;i<=n;i++) cout << cost[i] << endl;
	for(int i=1;i<=cnt;i++)
	{
		if(v2[i].size()==0)
		{
			if(costo[i]==oo)
			{
				cout << "NIE\n";
				cout << grope[i][0] << endl;
				return 0;
			}
			else
			{
				// cout << "comcal" << endl;
				su+=costo[i];
			}
		}
	}
	cout << "TAK\n" ;
	cout << su << endl;
	return 0;
}