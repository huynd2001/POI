// Trees
#include <bits/stdc++.h>
using namespace std;

int a,par[100007],conv[100007];
int ans[100007];
vector <int> v[100007];
vector <int> euler;
string concat="";

void dfs(int node)
{
	euler.push_back(node);
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		dfs(k);
	}
	return ;
}

void dfs2(int node)
{
	concat=concat+"(";
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i];
		dfs2(k);
	}
	concat=concat+")";
	return ;
}

int main()
{
	int n;
	cin >> n;
	int cnt=1;
	stack <pair<int,int> > st;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		while(!st.empty() && st.top().first==a)
		{
			par[st.top().second]=cnt+1;
			par[cnt]=cnt+1;
			v[cnt+1].push_back(st.top().second);
			v[cnt+1].push_back(cnt);
			st.pop();
			cnt++;
			a--;
		}
		st.push(make_pair(a,cnt));
		cnt++;
	}
	cnt--;
	if(st.size()==1 && st.top().first==0)
	{
		dfs(cnt);
		conv[0]=0;
		for(int i=0;i<euler.size();i++)
		{
			conv[euler[i]]=i+1;
		}
		for(int i=1;i<=cnt;i++)
		{
			ans[i]=conv[par[euler[i-1]]];
		}
		for(int i=1;i<=cnt;i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		dfs2(cnt);
		cout << concat << endl;
	}
	else
	{
		cout << "NIE" << endl;
	}
	return 0;
}
