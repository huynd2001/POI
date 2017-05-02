#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector <int> ans,su,inde;
	vector <int> sub;
	su.push_back(0);
	inde.push_back(0);
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		inde.push_back(i);
		if(ch=='c')
		{
			int k=su[su.size()-1];
			su.push_back(k+1);
		}
		else
		{
			int k=su[su.size()-1];
			su.push_back(k);
		}
		if(su.size()>k && su[su.size()-1]-su[su.size()-1-k-1]==1)
		{
			for(int j=1;j<=k+1;j++)
			{
				sub.push_back(inde[inde.size()-1]);
				inde.pop_back();
				su.pop_back();
			}
			for(int j=1;j<=k+1;j++)
			{
				ans.push_back(sub[sub.size()-1]);
				sub.pop_back();
			}
		}
	}
	for(int i=(n/(k+1))-1;i>=0;i--)
	{
		for(int j=0;j<=k;j++)
		{
			cout << ans[i*(k+1)+j] << " ";
		}
		cout << endl;
	}
	return 0;
}
