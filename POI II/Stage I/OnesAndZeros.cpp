/*huypheu
6
17
11011
17
999
125
173
*/

#include <bits/stdc++.h>
using namespace std;

int par[20007];
vector <int> v[20007],vnone;

int main()
{
	int test;
	cin >> test;

	while(test--)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			cout << 1 << endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			v[i]=vnone;
			v[i].push_back((i*10)%n);
			v[i].push_back((i*10+1)%n);
		}
		queue<int> que;
		que.push(1);
		for(int i=0;i<n;i++) par[i]=-1;
			par[1]=-2;
		bool ok=0;
		while(!que.empty())
		{
			int k=que.front();
			que.pop();
			if(k==0) ok=1;
			for(int i=0;i<v[k].size();i++)
			{
				int j=v[k][i];
				if(par[j]==-1)
				{
					par[j]=k;
					que.push(j);
				}
			}
		}
		int cur=0;
		vector <int> ans;
		if(ok)
		{
			while(par[cur]!=-2)
			{
				int j=par[cur];
				if((j*10)%n==cur)
				{
					ans.push_back(0);
				}
				else ans.push_back(1);
				cur=j;
			}
			ans.push_back(1);
			if(ans.size()>100)
			{
				cout << "BRAK" << endl;
			}
			else
			{
				for(int i=(int)ans.size()-1;i>=0;i--)
				{
					cout << ans[i] ;
				}
				cout << endl;
			}
		}
		else
		{
			cout << "BRAK" << endl;
		}
	}
}