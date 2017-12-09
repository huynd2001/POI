/*huypheu
7 16
1 3
1 4
1 5
2 3
3 4
4 5
4 7
4 6
5 6
6 7
2 4
2 7
2 5
3 5
3 7
1 7
*/

#include <bits/stdc++.h>
using namespace std;

set <int> se;
set<pair<int,int> > ed;

void dfs(int node)
{
	vector <int> va;
	for(set<int>::iterator it=se.begin();it!=se.end();it++)
	{
		int k=*it;
		if(ed.find(make_pair(min(k,node),max(k,node)))==ed.end()) va.push_back(k);
	}
	for(int i=0;i<va.size();i++) se.erase(va[i]);
	for(int i=0;i<va.size();i++) dfs(va[i]);
		return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin >> a >> b ;
		ed.insert(make_pair(min(a,b),max(a,b)));
	}
	for(int i=1;i<=n;i++) se.insert(i);
		vector <int> ans;
	while(!se.empty())
	{
		int k=se.size();
		int x=*se.begin();
		se.erase(x);
		dfs(x);
		ans.push_back(k-se.size());
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
		cout << "\n";
	return 0;
}