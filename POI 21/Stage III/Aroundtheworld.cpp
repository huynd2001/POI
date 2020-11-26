/*huypheu
6 4
2 2 1 3 3 1
3 2 4 11
*/

#include <bits/stdc++.h>
using namespace std;

int ar[1000007],nex[1000007];
bool vst[1000007];
int n;

void solve(int len)
{
	for(int i=0;i<n;i++) nex[i]=i,vst[i]=0;
	int cur=0;
	for(int i=0;i<n;i++) 
	{
		while(cur<len && cur+ar[nex[i]]<=len) cur+=ar[nex[i]],nex[i]=(nex[i]+1)%n;
		cur-=ar[i];
		if(i<n-1) nex[i+1]=nex[i];
	}
	// for(int i=0;i<n;i++) cout << nex[i] << " ";
	// 	cout << endl;
	for(int i=0;i<n;i++) if(nex[i]==i){
		cout << "NIE\n";
		return ;
	} 
	int k=0;
	while(!vst[k]) vst[k]=1,k=nex[k];
	int j=k;
	int dem=1;
	k=j;
	while(1)
	{
		int l=nex[k];
		if((l+n-j)%n<(k+n-j)%n) 
		{
			cout << dem << "\n";
			return ;
		}
		else dem++,k=l;
	}
	return ;
}

int main()
{
	int q;
	cin >> n >> q;
	int su=0;
	for(int i=0;i<n;i++)
	{
		cin >> ar[i];
		su+=ar[i];
	}
	int mi=ar[0];
	for(int i=0;i<n;i++) mi=min(mi,ar[i]);
	for(int i=0;i<q;i++)
	{
		int len;
		cin >> len ;
		if(len>=su) cout << 1 << "\n"; else solve(len);
	}
	return 0;
}