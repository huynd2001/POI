/*huypheu
3 3 1
2 3 3
*/

#include <bits/stdc++.h>
using namespace std;

int dem[1000007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	// scanf("%d",&n);
	cin >> n;
	int s,t;
	// scanf("%d %d", &s,&t);
	cin >> s >> t;
	int su=0;
	for(int i=1;i<=n;i++)
	{
		// scanf("%d",&dem[i]);
		cin >> dem[i];
		su+=dem[i];
	}
	if(su%2==0) 
	{
		for(int i=1;i<=n;i++)
		{
			if(dem[i]>su/2) 
			{
				// printf("0\n");
				cout << 0 << "\n";
				return 0;
			}
			if(dem[i]==su/2)
			{
				if(s==i && t!=i)
				{
					int cur=1;
					for(int j=1;j<=dem[i]-1;j++)
					{
						while(dem[cur]==0 || cur==i) cur++;
						// printf("%d %d ",i,cur);
						cout << i << " " << cur << " ";
						dem[cur]--;
					}
					// printf("%d %d\n",i,t);
					cout << i << " " << t ;
					cout << "\n";
					// cout << "done" << endl;
					return 0;
				}
				if(t==i && s!=i)
				{
					int cur=1;
					// printf("%d %d ",s,i);
					cout << s << " " << i << " ";
					for(int j=1;j<=dem[i]-1;j++)
					{
						while((cur==s && dem[t]==1) || dem[cur]==0 || cur==i) cur++;
						// printf("%d %d ",cur,i);
						cout << cur << " " << i << " ";
						dem[cur]--;
					}
					cout << "\n";
					// printf("\n");
					return 0;
				}

				if(t!=i && s!=i)
				{
					cout << 0 << "\n";
					// printf("0\n");
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(dem[i]>su/2+1)
			{
				cout << 0 << "\n";
				// printf("0\n");
				return 0;
			}
			if(dem[i]==su/2+1)
			{
				if(s==i && t==i)
				{
					int cur=1;
					for(int j=1;j<=dem[i]-1;j++)
					{
						while(dem[cur]==0 || cur==i) cur++;
						cout << i << " " << cur << " ";
						// printf("%d %d ",i,cur);
						dem[cur]--;
					}
					cout << i << "\n";
					// printf("%d\n",i);
					return 0;
				}
				cout << 0 << "\n";
				// printf("0\n");
				return 0;
			}
		}
	}
	priority_queue <pair<int,int> > q;
	vector <int> ans;
	ans.push_back(s);
	dem[s]--;
	dem[t]--;
	for(int i=1;i<=n;i++)
	{
		if(i==t) q.push(make_pair(dem[i],i)); else q.push(make_pair(dem[i],-i));
		if(dem[i]<0) 
		{
			cout << 0 << "\n";
			return 0;
		}
	}
	while(!q.empty())
	{
		pair<int,int> sk=q.top();
		q.pop();
		sk.second=abs(sk.second);
		// cout << sk.second << " " << sk.first << endl;
		if(sk.first==0) continue;
		if(ans[ans.size()-1]==sk.second)
		{
			pair<int,int> x=q.top();
			q.pop();
			x.second=abs(x.second);
			ans.push_back(x.second);
			if(sk.second!=t) sk.second=-sk.second;
			if(x.second!=t) x.second=-x.second;
			q.push(sk);
			if(x.first==1 || x.first==0) continue;
			q.push(make_pair(x.first-1,x.second));
		}
		else
		{
			ans.push_back(sk.second);
			if(sk.second!=t) sk.second=-sk.second;
			if(sk.first==1 || sk.first==0) continue;
			q.push(make_pair(sk.first-1,sk.second));
		}
	}
	ans.push_back(t);
	for(int i=0;i<ans.size();i++) cout << ans[i] << " "; /*printf("%d ",ans[i]);*/
		cout << "\n";
	// printf("\n");
	return 0;
}