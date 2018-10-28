#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

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
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

//TO ADD: dset, spfa, bit

//MODEXP & MODMUL

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
