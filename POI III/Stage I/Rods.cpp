/*huypheu
3
1000 20
15000 10
60 2.83185
*/

#include <bits/stdc++.h>
#define pi 3.14159265359
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	while(test--)
	{
		double a,b;
		cin >> a >> b;
		b=b+a;
		// cout << a << " " <<  b << endl;
		// cout << sin(pi/4) << endl;
		double l=0.00,r=pi;
		while(abs(l-r)>10e-15)
		{
			double mid=(l+r)/2.00;
			double k=(mid*a)/(2.00*sin(mid/2));
			// cout << mid << endl;
			// cout  << k << endl;
			if(k>b) r=mid; else l=mid;
		}
		int ans=round(-a/(2.00*tan(l/2.00))+a/(2.00*sin(l/2.00))) ;
		// if(ans==854) printf("%d\n",ans+1);
		//else 
		printf("%d\n",ans);
		// cout << l << endl;
		// cout << l << " " << pi/3 << endl;

	}
	// cout << 60 << " " << 120*pi/6-60 << endl;
	// cout << 60 << " " << 60*(pi/2-1) << endl;
	// cout << (pi*60)/(2.00*sin(pi/2)) << endl;
	// cout << tan(pi/2) << endl;
}