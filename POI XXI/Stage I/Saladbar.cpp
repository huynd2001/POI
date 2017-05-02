/*huypheu
6
jpjppj
*/

#include <bits/stdc++.h>
using namespace std;

int f[1000007][21];
int cap[1000007];
int a[1000007],s[1000007],l[1000007];
int mist[1000007];

// int get(int l,int r)
// {
// 	int i=cap[r-l+1];
// 	int x=f[l][i],y=f[r-(1<<i)+1][i];
// 	if(s[x]!=s[y])
// 	{
// 		if(s[x]>s[y]) return y; else return x;
// 	}
// 	else if(x<y) return x; else return y;
// }

int main()
{
	int n;
	cin >> n;
	int core=1,dem=0;
	for(int i=1;i<=n;i++)
	{
		if(i<core*2) cap[i]=dem;
		else
		{
			core*=2;
			dem++;
			cap[i]=dem;
		}
	}
	// cout << cap[1] << endl;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		if(ch=='j') a[i]=-1; else a[i]=1; 
		s[i]=s[i-1]+a[i];
	}
	// cout << "cak" << endl;
	// for(int i=1;i<=n;i++) cout << s[i] << " ";
	// 	cout << endl;
	for(int i=1;i<=n;i++)
	{
		mist[i]=i;
	}
	stack <int> st;
	for(int i=0;i<=n;i++)
	{
		while(!st.empty() && s[st.top()]<=s[i])
		{
			int k=mist[st.top()];
			if(s[mist[i]]>=s[k]) mist[i]=k;
			st.pop();
		}
		if(st.empty()) l[i]=-1; else l[i]=st.top();
		st.push(i);
	}
	// cout << "cak" << endl;
	// for(int i=1;i<=n;i++) cout << l[i] << " ";
	// 	cout << endl;
	int best=0;
	for(int i=1;i<=n;i++)
	{
		int k=mist[i];
		// cout << i << " " << k << endl;
		best=max(i-k,best);
	}
	cout << best << endl;
	return 0;
}
