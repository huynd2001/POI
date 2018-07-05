#include <bits/stdc++.h>
using namespace std;

bool a[10000007];

int main()
{
	int n;
	cin >> n;
	if(n == 1) return cout << "1\na\n", 0;
	if(n == 2) return cout << "2\nab\n", 0;
	if(n == 3) return cout << "2\naba\n", 0;
	cout << 3 << "\n";
	for(int i = 0; i <= n; i++)
	{
		if(i == 0) a[i] = 0;
		else
		{
			if( i % 2 == 1) a[i] = !a[i / 2]; else a[i] = a[i / 2];
		}
	}
	// I have no idea why this works
	for(int i = 0 ; i < n ; i++) if(a[i] == a[i + 1]) cout << "a"; else if(a[i]) cout << "b"; else cout << "c";
	cout << "\n";
	return 0;
}
