#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int ar[2];
	bool la;
};

bool Leaf[400007];
int par[400007];
int equi[400007];
bool vst[400007],inst[400007];
bool ans;

Node gop(int x,int y, bool k)
{
	Node a;
	a.ar[0]=x;
	a.ar[1]=y;
	a.la=k;
	return a;
}

vector <Node> Trie;

void add(string s)
{
	int curr=0;
	for(int i=0;i<s.size();i++)
	{
		bool ka=(s[i]=='1');
		if(Trie[curr].ar[ka]==-1)
		{
			Trie[curr].ar[ka]=Trie.size();
			Trie.push_back(gop(-1,-1,ka));
		}
		par[Trie[curr].ar[ka]]=curr;
		curr=Trie[curr].ar[ka];
	}
	Leaf[curr]=1;
	return ;
}

void contruct()
{
	queue <int> que;
	que.push(0);
	while(!que.empty())
	{
		int node=que.front();
		if(node==0)
		{
			equi[node]=0;
		}
		else
		{
			if(equi[par[node]]==par[node]) equi[node]=0;
			else
			{
				bool t=Trie[node].la;
				equi[node]=Trie[equi[par[node]]].ar[t];
			}
		}
		if(Trie[node].ar[0]>-1) que.push(Trie[node].ar[0]);
		if(Trie[node].ar[1]>-1) que.push(Trie[node].ar[1]);
		if(Trie[node].ar[0]==-1) Trie[node].ar[0]=Trie[equi[node]].ar[0];
		if(Trie[node].ar[1]==-1) Trie[node].ar[1]=Trie[equi[node]].ar[1];
		if(Leaf[equi[node]]) Leaf[node]=1;
		que.pop();
	}
	return ;
}

void check(int node)
{
	if(ans) return ;
	vst[node]=1;
	inst[node]=1;
	int x=Trie[node].ar[0],y=Trie[node].ar[1];
	if(inst[x])
	{
		ans=1; return ;
	}
	else if(!Leaf[x] && !vst[x]) check(x);
	if(ans) return ;
	if(inst[y])
	{
		ans=1; return ;
	}
	else if(!Leaf[y] && !vst[y]) check(y); 
	inst[node]=0;
	return ;
}

int main()
{
	int n;
	cin >> n;
	Trie.push_back(gop(-1,-1,0));
	for(int i=1;i<=n;i++)
	{
		string s;
		cin >> s;
		add(s);
	}
	contruct();
	check(0);
	if(ans) cout << "TAK\n"; else cout << "NIE\n";
	return 0;
}
