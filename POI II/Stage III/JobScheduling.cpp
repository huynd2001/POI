/*huypheu
5
0.002000 0.003000
0.016000 0.001000
0.100000 0.300000
0.016000 0.005000
0.030000 0.060000
*/

#include <bits/stdc++.h>
using namespace std;

pair<double,double> a[10007];
int ans[100007];

bool dcp(int x,int y)
{
	if(a[x].first==0) return 0;
	if(a[y].first==0) return 1;
	return (a[x].second/a[x].first<a[y].second/a[y].first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		ans[i]=i;
	}
	sort(ans+1,ans+n+1,dcp);
	for(int i=1;i<=n;i++) cout << ans[i] << endl;
	return 0;
}