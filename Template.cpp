#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define fi first
#define sc second
#define MOD 1000000007
#define mkp make_pair
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define CL(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define LL_MAX (1LL<<61)
#define FND(S,x) (S.find(x)!=S.end())
#define bit(x,y) (!!(((ll)x)&(1LL<<y)))
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
#define DI(x) (int)(x-'0')

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

//==============================================
//MACRO 2
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define DB 0
typedef long long ll;

//==============================================

//POJ 專用
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <string>
#include <cstring>
#include <assert.h>
#include <climits>
#include <time.h>

//TO ADD: dset, spfa, bit

//CNK & MODEXP & MODMUL

ll F[MXN];
ll mx = 200000;
ll c(ll n, ll k)
{
    if(!F[0])
    {
        F[0]=1;
        FOR(i,1,mx)F[i]=F[i-1]*i%MOD;
    }
    if(k>n)return 0;
    ll r = F[n];
    r = r*modexp(F[n-k], MOD-2)%MOD;
    r = r*modexp(F[k], MOD-2)%MOD;
    return r;
}

ll modexp(ll x, ll y)
{
    ll Pow = x%MOD, rtn = 1;
    while(y)
    {
        if(y&1)rtn=(rtn*Pow)%MOD;
        y>>=1;
        Pow=(Pow*Pow)%MOD;
    }
    return rtn;
}

ll modmul(ll x, ll y)
{
    y%=MOD;
    ll x2p = x%MOD, rtn = 0;
    while(y)
    {
        if(y&1)rtn=(rtn+x2p)%MOD;
        y=y>>1;
        x2p=(x2p*2)%MOD;
    }
    return rtn;
}

ll modexp(ll x, ll y) //SAFER BUT SLOWER VER
{
    ll Pow = x%MOD, rtn = 1;
    while(y)
    {
        if(y&1)rtn=modmul(rtn,Pow);
        y=y>>1;
        Pow=modmul(Pow,Pow);
    }
    return rtn;
}

ll gcd(ll x, ll y)
{
    if(y == 0)return x;
    return gcd(y, x%y);
}

pll extgcd(ll x, ll y)
{
    if(y == 0)return pll(1, 0);
    pll res = extgcd(y, x%y);
    return pll(res.s, res.f - (x/y)*res.s);
}

pll modinv(ll x, ll y)
{
    if(gcd(x, y) != 1)return pll(0, 0);
    return pll(extgcd(x, y).f, 1);
}

//random number
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937_64 mt(seed);
//usage : mt() returns a random number

//range sum, single add
struct
{
    void up(int id)
    {
        st[id] = st[id*2] + st[id*2+1];
    }
    void build(int l, int r, int id)
    {
        if(l==r)
        {
            st[id]=0;
            return;
        }
        int m = (l+r)/2;
        build(l,m,id*2);
        build(m+1,r,id*2+1);
        up(id);
    }
    ll Sum(int L, int R, int l, int r, int id)
    {
        if( l>=L && r<=R )return st[id];
        if( l>R || r<L )return 0;
        int m = (l+r)/2;
        return Sum(L,R,l,m,id*2)+Sum(L,R,m+1,r,id*2+1);
    }
    void Add(int p, ll x, int l, int r, int id)
    {
        if(l==r)
        {
            st[id]+=x;
            return;
        }
        int m = (l+r)/2;
        if(p<=m)Add(p,x,l,m,id*2);
        else Add(p,x,m+1,r,id*2+1);
        up(id);
    }
    ll st[MXN*4];
}segt1;

//range max, range add
struct
{
    ll Get(int id){ return st[id]+ad[id]; }
    void up(int id)
    {
        st[id] = max(Get(id*2), Get(id*2+1));
    }
    void down(int l, int r, int id)
    {
        ll val = ad[id];
        ad[id] = 0;
        st[id]+=val;
        if(l==r)return;
        ad[id*2]+=val, ad[id*2+1]+=val;
    }
    void build(int l, int r, int id)
    {
        ad[id] = 0;
        if(l==r)
        {
            st[id]=0;
            return;
        }
        int m = (l+r)/2;
        build(l,m,id*2);
        build(m+1,r,id*2+1);
        up(id);
    }
    ll Max(int L, int R, int l, int r, int id)
    {
        down(l,r,id);
        if( l>=L && r<=R )return st[id];
        if( l>R || r<L )return 0;
        int m = (l+r)/2;
        return max(Max(L,R,l,m,id*2),Max(L,R,m+1,r,id*2+1));
    }
    void Add(int L, int R, ll x, int l, int r, int id)
    {
        down(l,r,id);
        if( l>=L && r<=R )
        {
            ad[id]+=x;
            return;
        }
        if( l>R || r<L )return;

        int m = (l+r)/2;
        Add(L,R,x,l,m,id*2);
        Add(L,R,x,m+1,r,id*2+1);
        up(id);
    }
    ll st[MXN*4], ad[MXN*4];
}segt2;

struct DSU
{
    int pa[MXN], sz[MXN];
    void init(int n)
    {
        FOR(i,0,n)
        {
            pa[i]=i;
            sz[i]=1;
        }
    }
    int Find(int x)
    {
        return (x==pa[x]) ? x : (pa[x]=Find(pa[x]));
    }
    int Merge(int x, int y)
    {
        x = Find(x), y = Find(y);
        if(x==y)return 0;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        pa[y]=x;
        return 1;
    }
} dsu;
