#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int> > vo;
int a[1000007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> m >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(i==n || a[i+1] > a[i] + 1)
		{
			int gr = i-last;
			int num = m - a[i] - (n-i);
			vo.push_back(make_pair(gr,num));
			last = i;
		}
	}
	int sum=0;
	for(int i=0;i<vo.size();i++) if(vo[i].second & 1) sum = sum ^ vo[i].first;
	if(!vo.empty() && vo[vo.size()-1].second==1)
	{
		 cout << vo[vo.size()-1].first << "\n";
		 return 0;
	}
	if(sum == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	int ans=0;
	for(int i=0;i<vo.size();i++)
	{
		if(vo[i].second & 1)
		{
			int ka = sum ^ vo[i].first;
			if(ka <= vo[i].first) ans++;
		}
		else if(vo[i].second != 2)
		{
			int curr1, tar, curr2;
			if(i != vo.size()-1)
			{
				if(vo[i+1].second == vo[i].second - 1)
				{
					curr1 = vo[i].first;
					tar = sum ^ vo[i+1].first;
					curr2 = vo[i+1].first;
				}
				else 
				{
					curr1 = vo[i].first;
					tar = sum;
					curr2 = 0;
				}
			}
			else
			{
				curr1 = vo[i].first;
				tar = sum;
				curr2 = 0;
			}
			if(tar >= curr2 && (tar - curr2) <= curr1) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}