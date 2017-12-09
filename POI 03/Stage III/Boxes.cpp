#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

int n,flow,s,t,cost;
int d[1007],da[1007],dab[1007];
int co[8007],cap[8007],f[8007];
int ar[1007],br[1007];
bool inque[1007];
vector <pair<int,int> > v[1007];

bool bfs()
{
	if(flow==0) return 0;
	queue <int > que;
	for(int i=1;i<=t;i++) da[i]=oo,d[i]=0,dab[i]=0,inque[i]=0;
	da[s]=0,d[s]=-1,dab[s]=-1,inque[s]=1;
	que.push(s);
	while(!que.empty())
	{
		int sub=que.front();
		// cout << "hmm" << endl;
		que.pop();
		inque[sub]=0;
		// cout << sub << "\n";
		// if(sub.first==t) cout << "concak" << endl;
		for(int i=0;i<v[sub].size();i++)
		{
			pair<int,int> k=v[sub][i];
			// cout << k.first << " " ;
			// if(k.first==t) cout << cap[k.second] << " " << f[k.second] << " " << da[k.first] << " " << sub.second +co[k.second] << " | ";
			if(cap[k.second]>f[k.second] && da[k.first]>da[sub]+co[k.second])
			{
				da[k.first]=da[sub]+co[k.second];
				d[k.first]=sub;
				dab[k.first]=k.second;
				if(!inque[k.first]) que.push(k.first),inque[k.first]=1;
			}
		}
		// cout << "\n";
	}
	// cout << "done" << endl;
	// cout << d[t] << endl;
	if(d[t]==0) return 0; else return 1;
}

void buff()
{
	int p=t;
	int mi=oo;
	while(d[p]!=-1) 
	{
		mi=min(mi,cap[dab[p]]-f[dab[p]]);
		// cout << p << " " ;
		p=d[p];
	}
	// cout << p << endl;
	mi=min(flow,mi);
	flow-=mi;
	cost+=mi*da[t];
	// cout << flow << " " << cost << endl;
	p=t;
	while(d[p]!=-1) 
	{
		f[dab[p]]+=mi;
		f[dab[p]+(dab[p]%2==0)-(dab[p]%2==1)]-=mi;
		p=d[p];
	}
	return ;
}

int main()
{
	cin >> n;
	int canh=0;
	flow=0;
	int m;
	s=n+1,t=n+2;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		v[n+1].push_back(make_pair(i,canh));
		cap[canh]+=a;
		co[canh]+=1;
		canh++;
		v[i].push_back(make_pair(n+1,canh));
		co[canh]-=1;
		canh++;
		flow+=a;
	}
	m=flow;
	for(int i=1;i<=n;i++)
	{
		int j;
		if(i==n) j=1; else j=i+1;
		v[i].push_back(make_pair(j,canh));
		cap[canh]+=oo;
		co[canh]+=1;
		canh++;
		v[j].push_back(make_pair(i,canh));
		co[canh]-=1;
		canh++;
		v[j].push_back(make_pair(i,canh));
		cap[canh]+=oo;
		co[canh]+=1;
		canh++;
		v[i].push_back(make_pair(j,canh));
		co[canh]-=1;
		canh++;
	}
	for(int i=1;i<=n;i++)
	{
		v[i].push_back(make_pair(n+2,canh));
		cap[canh]+=1;
		co[canh]+=1;
		canh++;
		v[n+2].push_back(make_pair(i,canh));
		co[canh]-=1;
		canh++;
	}
	// cout << s << " " << t << endl;
	while(bfs())
	{
		buff();
		// cout << "yeah" << endl;
	}
	// cout << flow << endl;
	cout << cost-2*m << endl;
	return 0;
}