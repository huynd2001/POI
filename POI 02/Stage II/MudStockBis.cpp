/*huypheu
3 12
2 2 3 2 3
3 3 2 2 0 2 3
3 3 4 1 3 2 3
*/

#include <bits/stdc++.h>
using namespace std;

int cap[357][107],l[357][107];
int totcap[357],su[357];
int tottotcap,totsu;
int N[357];

int main()
{
	int n;
	cin >> n >> cap[0][0];
	for(int i=1;i<=n;i++)
	{
		cin >> N[i];
		for(int j=1;j<=N[i];j++)
		{
			cin >> l[i][j] >> cap[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int len=0;
		su[i]=0;
		for(int j=1;j<=N[i];j++)
		{
			su[i]+=(len+l[i][j])*cap[i][j];
			totcap[i]+=cap[i][j];
			len+=l[i][j];
		}
		tottotcap+=totcap[i];
		totsu+=su[i];
	}
	ans=totsu;
	int x=0,y=0;
	tottotcap+=cap[0][0];
	// cout << totsu << endl;
	for(int i=1;i<=n;i++)
	{
		int sub=totsu-su[i];
		int peas=tottotcap-totcap[i];
		int cur=su[i];
		for(int j=1;j<=N[i];j++)
		{
			cur-=(tottotcap-peas)*l[i][j];
			sub+=peas*l[i][j];
			peas+=cap[i][j];
			// cout << cur+sub << " ";
			if(cur+sub<ans)
			{
				ans=cur+sub;
				x=i;
				y=j;
			}
		}
	}
	cout << ans << endl;
	cout << x << " " << y << endl;
	return 0;
}