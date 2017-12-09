/*huypheu
10
1 2 1 2 1 2 1 2 1 2
*/

#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int h[50007],l[50007],r[50007];
int it[200007][4];
int pos[50007];
int mi[50007];
int cut[50007];
bool upd[50007];

map <int,pair<int,int> > mm;

bool dcp(int x,int y)
{
	if(l[x]!=l[y]) return (l[x]>l[y]); else return (x<y);
}

bool dc3(int x,int y)
{
	return (h[x]<h[y]);
}

bool dc2(int x,int y)
{
	return (h[x]>h[y]);
}

bool dcp2(int x,int y)
{
	if(r[x]!=r[y]) return (r[x]<r[y]); else return (x<y);
}

void build(int node,int l,int r)
{
	if(l>r) return ;
	if(l==r)
	{
		it[node][1]=oo;
		it[node][2]=oo;
		it[node][3]=oo;
		return ;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	it[node][1]=min(it[node*2][1],it[node*2+1][1]);
	it[node][2]=min(it[node*2][2],it[node*2+1][2]);
	it[node][3]=min(it[node*2][3],it[node*2+1][3]);
	return ;
}

void update(int node,int l,int r,int x,int y,int id)
{
	if(l>r || x<l || r<x) return ;
	if(l==r)
	{
		it[node][id]=y;
		// cout << "1kasksddfoih " << y << endl;
		return ;
	}
	int mid=(l+r)/2;
	update(node*2,l,mid,x,y,id);
	update(node*2+1,mid+1,r,x,y,id);
	it[node][id]=min(it[node*2][id],it[node*2+1][id]);
	return ;
}

int get(int node,int l,int r,int x,int y,int id)
{
	if(l>r || r<x || y<l || y<x) return oo;
	if(x<=l && r<=y) return it[node][id];
	int mid=(l+r)/2;
	return min(get(node*2,l,mid,x,y,id),get(node*2+1,mid+1,r,x,y,id));
}

signed main()
{
	int n;
	cin >> n;
	vector <int> vo;
	for(int i=1;i<=n;i++)
	{
		cin >> h[i];
		vo.push_back(i);
	}
	sort(vo.begin(),vo.end(),dc3);
	for(int i=0;i<n;i++)
	{
		pos[vo[i]]=i+1;
	}
	for(int i=1;i<=n;i++) 
	{
		if(mm.find(h[i])==mm.end())
		{
			mm[h[i]].first=pos[i];
			mm[h[i]].second=pos[i];
		}
		else 
		{
			mm[h[i]].first=min(mm[h[i]].first,pos[i]);
			mm[h[i]].second=max(mm[h[i]].second,pos[i]);
		}
	}
	for(int i=2;i<n;i++)
	{
		l[i]=min(h[i-1],h[i+1]);
		r[i]=max(h[i-1],h[i+1]);
	}
	r[1]=h[2];
	l[n]=h[n-1];
	int cap=0;
	for(int i=1;i<n;i++)
	{
		cap+=abs(h[i]-h[i+1]);
	}
	for(int i=1;i<=n;i++) mi[i]=cap;
	if(n==2)
	{
		for(int i=1;i<=n;i++) cout << mi[i] << "\n";
		return 0;
	}
	for(int i=3;i<n;i++)
	{
		mi[1]=min(mi[1],cap-abs(h[1]-h[2])-abs(h[i]-l[i])-abs(h[i]-r[i])+abs(h[i]-h[2])+abs(h[1]-l[i])+abs(h[1]-r[i]));
		mi[i]=min(mi[i],cap-abs(h[1]-h[2])-abs(h[i]-l[i])-abs(h[i]-r[i])+abs(h[i]-h[2])+abs(h[1]-l[i])+abs(h[1]-r[i]));
	}
	for(int i=2;i<=n-2;i++)
	{
		mi[n]=min(mi[n],cap-abs(h[n]-h[n-1])-abs(h[i]-l[i])-abs(h[i]-r[i])+abs(h[i]-h[n-1])+abs(h[n]-l[i])+abs(h[n]-r[i]));
		mi[i]=min(mi[i],cap-abs(h[n]-h[n-1])-abs(h[i]-l[i])-abs(h[i]-r[i])+abs(h[i]-h[n-1])+abs(h[n]-l[i])+abs(h[n]-r[i]));
	}
	mi[1]=min(mi[1],cap-abs(h[1]-h[2])-abs(h[n]-h[n-1])+abs(h[1]-h[n-1])+abs(h[n]-h[2]));
	mi[n]=min(mi[n],cap-abs(h[1]-h[2])-abs(h[n]-h[n-1])+abs(h[1]-h[n-1])+abs(h[n]-h[2]));
	//----------------------------------------------------------------------------------------------------------
	for(int i=2;i<n-1;i++)
	{
		mi[i]=min(mi[i],cap-abs(h[i]-h[i-1])-abs(h[i+2]-h[i+1])+abs(h[i]-h[i+2])+abs(h[i-1]-h[i+1]));
		mi[i+1]=min(mi[i+1],cap-abs(h[i]-h[i-1])-abs(h[i+2]-h[i+1])+abs(h[i]-h[i+2])+abs(h[i-1]-h[i+1]));
	}
	mi[1]=min(mi[1],cap-abs(h[2]-h[3])+abs(h[1]-h[3]));
	mi[2]=min(mi[2],cap-abs(h[2]-h[3])+abs(h[1]-h[3]));
	mi[n]=min(mi[n],cap-abs(h[n-1]-h[n-2])+abs(h[n]-h[n-2]));
	mi[n-1]=min(mi[n-1],cap-abs(h[n-1]-h[n-2])+abs(h[n]-h[n-2]));
	//----------------------------------------------------------------------------------------------------------
	vector <int> v;
	for(int i=2;i<n;i++)
	{
		v.push_back(i);
		cut[i]=abs(h[i]-l[i])+abs(h[i]-r[i]);
	}
	vector <int> vp;
	for(int i=2;i<n;i++) vp.push_back(i);
	//-------------------------------------------------------------------------------------------------------------
	sort(v.begin(),v.end(),dcp);
	int cur=0;
	build(1,1,n);
	sort(vp.begin(),vp.end(),dc2);
	for(int j=0;j<vp.size();j++)
	{
		int i=vp[j];
		while(cur<v.size() && l[v[cur]]>h[i])
		{
			update(1,1,n,pos[v[cur]],l[v[cur]]+r[v[cur]]-2*h[v[cur]]-cut[v[cur]],1);
			update(1,1,n,pos[v[cur]],l[v[cur]]+r[v[cur]]-cut[v[cur]],2);
			update(1,1,n,pos[v[cur]],l[v[cur]]+r[v[cur]]+2*h[v[cur]]-cut[v[cur]],3);
			upd[v[cur]]=1;
			cur++;
		}
		if(upd[i+1]) update(1,1,n,pos[i+1],oo,1),update(1,1,n,pos[i+1],oo,2),update(1,1,n,pos[i+1],oo,3);
		if(upd[i-1]) update(1,1,n,pos[i-1],oo,1),update(1,1,n,pos[i-1],oo,2),update(1,1,n,pos[i-1],oo,3);
		if(upd[i]) update(1,1,n,pos[i],oo,1),update(1,1,n,pos[i],oo,2),update(1,1,n,pos[i],oo,3);
		mi[i]=min(mi[i],cap+l[i]+r[i]-2*h[i]-cut[i]+get(1,1,n,1,mm[l[i]].first-1,1));
		mi[i]=min(mi[i],cap-l[i]+r[i]-2*h[i]-cut[i]+get(1,1,n,mm[l[i]].first,mm[r[i]].second,2));
		mi[i]=min(mi[i],cap-l[i]-r[i]-2*h[i]-cut[i]+get(1,1,n,mm[r[i]].second+1,n,3));
		if(upd[i+1]) update(1,1,n,pos[i+1],l[i+1]+r[i+1]-2*h[i+1]-cut[i+1],1);
		if(upd[i-1]) update(1,1,n,pos[i-1],l[i-1]+r[i-1]-2*h[i-1]-cut[i-1],1);
		if(upd[i]) update(1,1,n,pos[i],l[i]+r[i]-2*h[i]-cut[i],1);

		if(upd[i+1]) update(1,1,n,pos[i+1],l[i+1]+r[i+1]-cut[i+1],2);
		if(upd[i-1]) update(1,1,n,pos[i-1],l[i-1]+r[i-1]-cut[i-1],2);
		if(upd[i]) update(1,1,n,pos[i],l[i]+r[i]-cut[i],2);

		if(upd[i+1]) update(1,1,n,pos[i+1],l[i+1]+r[i+1]+2*h[i+1]-cut[i+1],3);
		if(upd[i-1]) update(1,1,n,pos[i-1],l[i-1]+r[i-1]+2*h[i-1]-cut[i-1],3);
		if(upd[i]) update(1,1,n,pos[i],l[i]+r[i]+2*h[i]-cut[i],3);
	}
	//-------------------------------------------------------------------------------------------------------------
	vector <pair<pair<int,int>,int> > event;
	for(int i=1;i<=n;i++) upd[i]=0;
	for(int i=2;i<n;i++)
	{
		event.push_back(make_pair(make_pair(l[i],0),i));
		event.push_back(make_pair(make_pair(h[i],1),i));
		event.push_back(make_pair(make_pair(r[i],2),i));
	}
	build(1,1,n);
	sort(event.begin(),event.end());
	for(int j=0;j<event.size();j++)
	{
		if(event[j].first.second==0)
		{
			int i=event[j].second;
			update(1,1,n,pos[i],-l[i]+r[i]-2*h[i]-cut[i],1);
			update(1,1,n,pos[i],-l[i]+r[i]-cut[i],2);
			update(1,1,n,pos[i],-l[i]+r[i]+2*h[i]-cut[i],3);
			upd[i]=1;
		}
		if(event[j].first.second==1)
		{
			int i=event[j].second;
			if(upd[i]) update(1,1,n,pos[i],oo,1),update(1,1,n,pos[i],oo,2),update(1,1,n,pos[i],oo,3);
			if(upd[i+1]) update(1,1,n,pos[i+1],oo,1),update(1,1,n,pos[i+1],oo,2),update(1,1,n,pos[i+1],oo,3);
			if(upd[i-1]) update(1,1,n,pos[i-1],oo,1),update(1,1,n,pos[i-1],oo,2),update(1,1,n,pos[i-1],oo,3);
			mi[i]=min(mi[i],cap+l[i]+r[i]-cut[i]+get(1,1,n,1,mm[l[i]].first-1,1));
			mi[i]=min(mi[i],cap-l[i]+r[i]-cut[i]+get(1,1,n,mm[l[i]].first,mm[r[i]].second,2));
			mi[i]=min(mi[i],cap-l[i]-r[i]-cut[i]+get(1,1,n,mm[r[i]].second+1,n,3));
			if(upd[i]) update(1,1,n,pos[i],-l[i]+r[i]-2*h[i]-cut[i],1);
			if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]+r[i+1]-2*h[i+1]-cut[i+1],1);
			if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]+r[i-1]-2*h[i-1]-cut[i-1],1);

			if(upd[i]) update(1,1,n,pos[i],-l[i]+r[i]-cut[i],2);
			if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]+r[i+1]-cut[i+1],2);
			if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]+r[i-1]-cut[i-1],2);

			if(upd[i]) update(1,1,n,pos[i],-l[i]+r[i]+2*h[i]-cut[i],3);
			if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]+r[i+1]+2*h[i+1]-cut[i+1],3);
			if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]+r[i-1]+2*h[i-1]-cut[i-1],3);
		}
		if(event[j].first.second==2)
		{
			int i=event[j].second;
			update(1,1,n,pos[i],oo,1);
			upd[i]=0;
		}
	}
	//-------------------------------------------------------------------------------------------------------------
	sort(v.begin(),v.end(),dcp2);
	build(1,1,n);
	sort(vp.begin(),vp.end(),dc3);
	for(int i=1;i<=n;i++) upd[i]=0;
	cur=0;
	for(int j=0;j<vp.size();j++)
	{
		int i=vp[j];
		while(cur<v.size() && r[v[cur]]<h[i])
		{
			update(1,1,n,pos[v[cur]],-l[v[cur]]-r[v[cur]]-2*h[v[cur]]-cut[v[cur]],1);
			update(1,1,n,pos[v[cur]],-l[v[cur]]-r[v[cur]]-cut[v[cur]],2);
			update(1,1,n,pos[v[cur]],-l[v[cur]]-r[v[cur]]+2*h[v[cur]]-cut[v[cur]],3);
			upd[v[cur]]=1;
			cur++;
		}
		if(upd[i+1]) update(1,1,n,pos[i+1],oo,1),update(1,1,n,pos[i+1],oo,2),update(1,1,n,pos[i+1],oo,3);
		if(upd[i-1]) update(1,1,n,pos[i-1],oo,1),update(1,1,n,pos[i-1],oo,2),update(1,1,n,pos[i-1],oo,3);
		if(upd[i]) update(1,1,n,pos[i],oo,1),update(1,1,n,pos[i],oo,2),update(1,1,n,pos[i],oo,3);
		mi[i]=min(mi[i],cap+l[i]+r[i]+2*h[i]-cut[i]+get(1,1,n,1,mm[l[i]].first-1,1));
		mi[i]=min(mi[i],cap-l[i]+r[i]+2*h[i]-cut[i]+get(1,1,n,mm[l[i]].first,mm[r[i]].second,2));
		mi[i]=min(mi[i],cap-l[i]-r[i]+2*h[i]-cut[i]+get(1,1,n,mm[r[i]].second+1,n,3));
		if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]-r[i+1]-2*h[i+1]-cut[i+1],1);
		if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]-r[i-1]-2*h[i-1]-cut[i-1],1);
		if(upd[i]) update(1,1,n,pos[i],-l[i]-r[i]-2*h[i]-cut[i],1);

		if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]-r[i+1]-cut[i+1],2);
		if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]-r[i-1]-cut[i-1],2);
		if(upd[i]) update(1,1,n,pos[i],-l[i]-r[i]-cut[i],2);

		if(upd[i+1]) update(1,1,n,pos[i+1],-l[i+1]-r[i+1]+2*h[i+1]-cut[i+1],3);
		if(upd[i-1]) update(1,1,n,pos[i-1],-l[i-1]-r[i-1]+2*h[i-1]-cut[i-1],3);
		if(upd[i]) update(1,1,n,pos[i],-l[i]-r[i]+2*h[i]-cut[i],3);
	}
	for(int i=1;i<=n;i++) cout << mi[i] << "\n";
	return 0;
}