/*huypheu
5
0 1 0 1 0
0 0 0 0 0
0 0 0 0 1
1 0 0 0 0
0 1 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;

short int le[2007],ri[2007],a[2007][2007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool k;
			cin >> k;
			if(k) a[i][j]=0; else a[i][j]=a[i-1][j]+1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		stack <int> st;
		for(int j=1;j<=n;j++)
		{
			while(!st.empty() && a[i][st.top()]>=a[i][j]) st.pop();
			if(st.empty()) le[j]=0; else le[j]=st.top();
			st.push(j);
		}
		while(!st.empty()) st.pop();
		for(int j=n;j>=1;j--)
		{
			while(!st.empty() && a[i][st.top()]>=a[i][j]) st.pop();
			if(st.empty()) ri[j]=n+1; else ri[j]=st.top();
			st.push(j);
		}
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,a[i][j]*(ri[j]-le[j]-1));
		}
	}
	cout << ans << endl;
	return 0;
}