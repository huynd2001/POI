#include <bits/stdc++.h>
#define oo (INT_MAX)
using namespace std;

int N, K, t[300007];

struct concak
{
    int val,inde,lazy;
}it[2500007];

int bit[300007];

void build(int node,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        it[node].val=t[l];
        it[node].lazy=0;
        it[node].inde=l;
        return ;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    it[node].val=max(it[node*2].val,it[node*2+1].val);
    if(it[node].val==it[node*2].val) it[node].inde=it[node*2].inde; else it[node].inde=it[node*2+1].inde;
    it[node].lazy=0;
    return ;
}

void update(int node,int l,int r,int m,int n,int x)
{
    // cout << node << " " << l << " " << r << endl;
    it[node].val+=it[node].lazy;
    it[node*2].lazy+=it[node].lazy;
    it[node*2+1].lazy+=it[node].lazy;
    it[node].lazy=0;
    if(l>r || r<m || n<l) return ;
    if(m<=l && r<=n)
    {
        it[node].lazy+=x;
        // if(node==2) cout << "!@#rer@#dfdf" << it[node].val << endl;
        it[node].val+=it[node].lazy;
        // if(node==2) cout << "!@#rer@#" << it[node].val << endl;
        it[node*2].lazy+=it[node].lazy;
        it[node*2+1].lazy+=it[node].lazy;
        it[node].lazy=0;
        return ;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,m,n,x);
    update(node*2+1,mid+1,r,m,n,x);
    it[node].val=max(it[node*2].val,it[node*2+1].val);
    // if(node==1)
    // {
    //     // cout << "!#@#" << it[node*2].val << " " << it[node*2+1].val << endl;
    // }
    if(it[node].val==it[node*2].val) it[node].inde=it[node*2].inde; else it[node].inde=it[node*2+1].inde;
    return ;
}

void update2(int node,int l,int r,int x,int cap)
{
    // cout << node << " " << l << " " << r << endl;
    it[node].val+=it[node].lazy;
    it[node*2].lazy+=it[node].lazy;
    it[node*2+1].lazy+=it[node].lazy;
    it[node].lazy=0;
    if(l>r || x<l || r<x) return ;
    if(l==r)
    {
        it[node].val=cap;
        return ;
    }
    int mid=(l+r)/2;
    update2(node*2,l,mid,x,cap);
    update2(node*2+1,mid+1,r,x,cap);
    it[node].val=max(it[node*2].val,it[node*2+1].val);
    if(it[node].val==it[node*2].val) it[node].inde=it[node*2].inde; else it[node].inde=it[node*2+1].inde;
    return ;
}

void upd(int x,int k)
{
    while(x<=N)
    {
        bit[x]+=k;
        x+=x&(-x);
    }
    return ;
}

pair<int,int> gett(int node,int l,int r,int m,int n)
{
    // cout << node << " " << l << " " << r << endl;
    it[node].val+=it[node].lazy;
    it[node*2].lazy+=it[node].lazy;
    it[node*2+1].lazy+=it[node].lazy;
    it[node].lazy=0;
    if(l>r || r<m || n<l) return make_pair(-oo,0);
    if(m<=l && r<=n) return make_pair(it[node].val,it[node].inde);
    int mid=(l+r)/2;
    pair<int,int> x,y;
    x=gett(node*2,l,mid,m,n);
    y=gett(node*2+1,mid+1,r,m,n);
    if(x.first>y.first) return x;
    if(x.first<y.first) return y;
    if(x.first==y.first)
    {
        if(x.second>y.second) return y; else return x;
    }
}

int get(int x)
{
    int su=0;
    while(x>0)
    {
        su+=bit[x];
        x-=x&(-x);
    }
    return su;
}

void inicjuj(int n, int k, int *D)
{
    N = n, K = k;
    for (int i = 0; i < n; ++i)
        t[i+1] = D[i];
    build(1,1,N);
    pair<int,int> sub=gett(1,1,N,1,N);
    while(sub.first>=K)
    {
        upd(sub.second,1);
        update2(1,1,N,sub.second,-oo);
        sub=gett(1,1,N,1,N);
    }
    return ;
}

void podlej(int a, int b)
{
    a++;
    b++;
    // cout << "concak" << endl;
    // cout << a << " " << b << endl;
    update(1,1,N,a,b,1);
    pair<int,int> sub=gett(1,1,N,1,N);
    // cout << sub.first << endl;
    while(sub.first>=K)
    {
        upd(sub.second,1);
        update2(1,1,N,sub.second,-oo);
        sub=gett(1,1,N,1,N);
    }
    // for(int i=1;i<=N;i++)
    // {
    //     cout << gett(1,1,N,i,i).first << " ";
    // }
    // cout << endl;
    return ;
}

int dojrzale(int a, int b)
{
    a++;
    b++;
    // for(int i=1;i<=N;i++)
    // {
    //     cout << gett(1,1,N,i,i).first << " ";
    // }
    // cout << endl;
    return get(b)-get(a-1) ;
}
