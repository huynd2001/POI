// Palindromes
#include <bits/stdc++.h>
#define oo 1000000
using namespace std;

bool palin[207][207];
int mi[207],ma[207];
bool ok[207];
char ch[207];

int main()
{
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		ch[i+1]=s[i];
	}
	int n=s.size();
	for(int i=1;i<n;i++)
	{
		if(ch[i]==ch[i+1])
		{
			palin[i][i+1]=1;
			for(int j=1;j<=n;j++)
			{
				if(i-j>=1 && i+1+j<=n && ch[i-j]==ch[i+j+1])
				{
					palin[i-j][i+1+j]=1;
				}
				else break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ma[i]=-oo;
		mi[i]=oo;
	}
	ma[0]=0;
	mi[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(palin[j][i])
			{
				ma[i]=max(ma[i],ma[j-1]+1);
				mi[i]=min(mi[i],mi[j-1]+1);
			}
		}
	}
	if(ma[n]==-oo || mi[n]==oo) 
	{
		cout << "NIE" << endl;
		return 0;
	}
	else
	{
		// cout << ma[n] << " " << mi[n] << endl;
		int cur=n;
		while(cur>0)
		{
			for(int i=cur;i>=1;i--)
			{
				if(palin[i][cur] && mi[cur]==mi[i-1]+1)
				{
					ok[i-1]=1;
					cur=i-1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout << ch[i];
			if(ok[i]) cout << " ";
		}
		cout << endl;
		for(int i=0;i<=n;i++) ok[i]=0;
		cur=n;
		while(cur>0)
		{
			for(int i=cur;i>=1;i--)
			{
				if(palin[i][cur] && ma[cur]==ma[i-1]+1)
				{
					ok[i-1]=1;
					cur=i-1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout << ch[i];
			if(ok[i]) cout << " ";
		}
		cout << endl;
		return 0;
	}
}
