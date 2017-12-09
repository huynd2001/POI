#include <bits/stdc++.h>
using namespace std;

int a[1000007],b[1000007],c[1000007],d[1000007];
int col[1000007],row[1000007];
vector <int> va,vb;

bool cmp1(int x,int y) {return (a[x]<a[y]);}
bool cmp2(int x,int y) {return (b[x]<b[y]);}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		va.push_back(i);
		vb.push_back(i);
	}
	sort(va.begin(),va.end(),cmp1);
	sort(vb.begin(),vb.end(),cmp2);
	// for(int i=0;i<va.size();i++) cout << va[i] << " ";
	// 	cout << endl;
	priority_queue <pair<int,int> > qu;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		while(cur<n && a[va[cur]]<=i) qu.push(make_pair(-c[va[cur]],va[cur])),cur++;
		col[qu.top().second]=i;
		qu.pop();
	}
	cur=0;
	for(int i=1;i<=n;i++)
	{
		while(cur<n && b[vb[cur]]<=i) qu.push(make_pair(-d[vb[cur]],vb[cur])),cur++;
		row[qu.top().second]=i;
		qu.pop();
	}
	for(int i=1;i<=n;i++)
	{
		if(col[i]<a[i] || col[i]>c[i] || row[i]<b[i] || row[i]>d[i]) 
		{
			cout << "NIE\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++) cout << col[i] << " " << row[i] << endl;
		return 0;
}