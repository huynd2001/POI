/*input
5 2
1 3 4 1 2
*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

vector<int> f[10];
int a[500003];

int main() {
	
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	for(int i = 0; i < d; i++) 
		f[i].resize(1, 0);

	f[0][0] = 1;

	int cap = 1;

	for(int i = 1; i <= n; i++) {

		while(cap <= a[i]) cap *= 2;

		for(int k = 0; k < d; k++) {
			f[k].resize(cap, 0);
		}

		for(int j = 0; j < cap; j++) {

			if((j ^ a[i]) < j) continue;

			if(d % 2 == 0) {
				int temp1 = f[d - 1][j ^ a[i]];
				int temp2 = f[d - 1][j];
				for(int k = 0; k < d; k++) {

					int tmp1 = f[k][j];
					int tmp2 = f[k][j ^ a[i]];

					f[k][j] = (f[k][j] + temp1) % mod;
					f[k][j ^ a[i]] = (f[k][j ^ a[i]] + temp2) % mod;

					temp1 = tmp2;
					temp2 = tmp1;
				}
			}
			else {
				int temp = f[d - 1][j ^ a[i]];
				for(int k = 0; k < 2 * d; k++) {

					if(k % 2 == 0) {
						int tmp = f[k %  d][j];
						f[k % d][j] = (f[k % d][j] + temp) % mod;
						temp = tmp;
					}
					else {
						int tmp = f[k %  d][j ^ a[i]];
						f[k % d][j ^ a[i]] = (f[k % d][j ^ a[i]] + temp) % mod;
						temp = tmp;
					}
				}
			}
		}
		
	}

	if(n % d != 0)
		cout << f[n % d][0] << endl;
	else
		cout << (f[n % d][0] + mod - 1) % mod;
}