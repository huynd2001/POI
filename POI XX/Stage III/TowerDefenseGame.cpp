#include <bits/stdc++.h>
using namespace std;

int vst[500007];
vector <int> v[500007];

void bfs(int node)
{
	queue<pair<int,int> > que;
	que.push(make_pair(node,0));
	vst[node]=1;
	while(!que.empty())
	{
		pair<int,int> sub=que.front();
		que.pop();
		// cout << sub.first << endl;
		if(sub.second==2) continue;
		for(int i=0;i<v[sub.first].size();i++)
		{
			int ka=v[sub.first][i];
			que.push(make_pair(ka,sub.second+1));
			vst[ka]=1;
		}
	}
	return ;
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// int dem=0;
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			ans.push_back(i);
			bfs(i);
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
