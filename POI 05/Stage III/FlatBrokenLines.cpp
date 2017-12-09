/*huypheu
6
1 6
10 8
1 5
2 20
4 4
6 2
*/

#include <bits/stdc++.h>
using namespace std;

int x[30007],y[30007];

bool cmp(int a,int b)
{
	if(x[a]!=x[b]) return (x[a]<x[b]); else return (y[a]<y[b]);
}

int main()
{
	int n;
	cin >> n;
	vector <int> v;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin >> a >> b;
		x[i]=a+b;
		y[i]=a-b;
		v.push_back(i);
	}
	sort(v.begin(),v.end(),cmp);
	multiset<int> se;
	for(int i=0;i<v.size();i++)
	{
		multiset<int>::iterator it=se.upper_bound(y[v[i]]);
		if(it==se.begin()) ; else
		{
			it--;
			se.erase(it);
		}
		se.insert(y[v[i]]);
	}
	cout << se.size() << "\n";
	return 0;
}