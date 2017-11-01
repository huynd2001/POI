#include <bits/stdc++.h>
using namespace std;

int nextu(int x,int n)
{
	if(x==1) return n; else return x-1;
}

vector <pair<int,char> > answering(vector <pair<int,char> > v,int n)
{
	vector <pair<int,char> > ans;
	for(int i=0;i<v.size();i++)
	{
		while(ans.size()>0 && ans[ans.size()-1].first==0) ans.pop_back();
		if(ans.size()==0) ans.push_back(v[i]); else
		{
			if(ans[ans.size()-1].second==v[i].second) ans[ans.size()-1].first=(ans[ans.size()-1].first+v[i].first)%n;
			else ans.push_back(v[i]);
		}
	}
	while(ans.size()>0 && ans[ans.size()-1].first==0) ans.pop_back();
	return ans;
}

int pos[2007],a[2007],tg;
queue<int> que;

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		que.push(a[i]);
	}
	int pap=a[1];
	while(que.front()!=1)
	{
		que.push(que.front());
		que.pop();
	}
	int poi=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=que.front();
		que.pop();
		if(a[i]==pap) poi=i;
		pos[a[i]]=i;
	}
//	for(int i=1;i<=n;i++) cout << a[i] << " ";
//	cout << endl;
	vector <pair<int,char> > ans;
	for(int i=2;i<=n-2;i++)
	{
		int dem=0;
//		cout << poi << " " << i << endl;
		while(poi!=pos[i])
		{
			dem++;
			poi=nextu(poi,n);
		}
		ans.push_back(make_pair(dem,'a'));
		while(pos[i]!=i)
		{
			if(pos[i]==i+1)
			{
				ans.push_back(make_pair(1,'a'));
				ans.push_back(make_pair(2,'b'));
				poi=nextu(poi,n);
				tg=a[poi];
				a[poi]=a[poi+1];
				a[poi+1]=a[poi+2];
				a[poi+2]=tg;
				pos[a[poi]]=poi;
				pos[a[poi+1]]=poi+1;
				pos[a[poi+2]]=poi+2;
			}
			else
			{
				ans.push_back(make_pair(2,'a'));
				ans.push_back(make_pair(1,'b'));
				poi=nextu(nextu(poi,n),n);
				tg=a[poi+2];
				a[poi+2]=a[poi+1];
				a[poi+1]=a[poi];
				a[poi]=tg;
				pos[a[poi]]=poi;
				pos[a[poi+1]]=poi+1;
				pos[a[poi+2]]=poi+2;
			}
		}
	}
	if(pos[n-1]!=n-1)
	{
		if(n%2==0)
		{
			int dem=0;
			while(poi!=n)
			{
				dem++;
				poi=nextu(poi,n);
			}
			ans.push_back(make_pair(dem,'a'));
			while(pos[n-1]!=2)
			{
				ans.push_back(make_pair(2,'a'));
				ans.push_back(make_pair(1,'b'));
				poi=nextu(nextu(poi,n),n);
				tg=a[poi+2];
				a[poi+2]=a[poi+1];
				a[poi+1]=a[poi];
				a[poi]=tg;
				pos[a[poi]]=poi;
				pos[a[poi+1]]=poi+1;
				pos[a[poi+2]]=poi+2;
			}
			ans.push_back(make_pair(2,'a'));
			ans.push_back(make_pair(1,'b'));
			tg=a[2];
			a[2]=a[1];
			a[1]=a[n];
			a[n]=tg;
			pos[a[1]]=1;
			pos[a[2]]=2;
			pos[a[n]]=n;
			ans.push_back(make_pair(n-2,'a'));
			ans=answering(ans,n);
			cout << ans.size() << endl;
			for(int i=0;i<ans.size();i++)
			{
				cout << ans[i].first << ans[i].second << " ";
			}
			cout << "\n";
		}
		else cout << "NIE DA SIE\n";
	}		
	else
	{
		int dem=0;
//		cout << poi << endl;
		while(a[poi]!=1)
		{
			dem++;
			poi=nextu(poi,n);
		}
		ans.push_back(make_pair(dem,'a'));
//			cout << ans.size() << endl;
//		for(int i=0;i<ans.size();i++)
//		{
//			cout << ans[i].first << ans[i].second << " ";
//		}
//		cout << "\n";
//		cout << "con cak " << endl;
		ans=answering(ans,n);
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++)
		{
			cout << ans[i].first << ans[i].second << " ";
		}
		cout << "\n";
	}
	return 0;
	// int dem=0;
}
