#include <bits/stdc++.h>
#include "cliclib.h"
using namespace std;

int n;
int po[4][20];
bool f[30007][16][16],ok[30007][16][16];

bool lose(int x,int i,int j)
{
	if(x>=n) return 0;
	else
	{
		if(ok[x][i][j]) return f[x][i][j];
		else
		{
			ok[x][i][j]=1;
			f[x][i][j]=!(lose(x+1,0,0) && lose(x+po[2][i]*po[3][j],i+1,j) && lose(x+po[2][i]*po[3][j]*2,i,j+1));
			return f[x][i][j];
		}
	}
}

int main()
{
	n=inicjuj();
	int st=1,pot=0;
	int x=0,y=0;
	for(int i=0;i<=15;i++)
	{
		po[2][i]=1<<i;
	}
	int core=1;
	for(int j=0;j<=10;j++)
	{
		po[3][j]=core;
		core*=3;
	}
	while(st+pot<n)
	{
		if(!lose(st+pot+1,0,0))
		{
			alojzy(1);
			pot+=st;
			st=1;
			x=0;
			y=0;
		}
		else
		{
			if(!lose(pot+st*2,x+1,y))
			{
				alojzy(2);
				st*=2;
				x++;
			}
			else
			{
				alojzy(3);
				st*=3;
				y++;
			}
		}
		int k=bajtazar();
		switch(k)
		{
			case 1 :
				pot+=st;
				st=1;
				x=0;
				y=0;
				break;
			case 2 :
				st*=2;
				x++;
				break;
			case 3 :
				st*=3;
				y++;
				break;
			default :
				;
		}
	}
	return 0;
}
