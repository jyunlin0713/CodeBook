typedef pair<ll,ll> pll;

ll gcd(ll x, ll y)
{
    if(y == 0)return x;
    return gcd(y, x%y);
}

pll extgcd(ll x, ll y)
{
    if(y == 0)return pll(1, 0);
    pll res = extgcd(y, x%y);
    return pll(res.second, res.first - (x/y)*res.second);
}

pll modinv(ll x, ll y) //x*x' % y == 1, 0<x'<y 
{
    if(gcd(x, y) != 1)return pll(0, 0);
    ll rt = extgcd(x,y).first;
    rt = (rt%y+y)%y;
    return pll(rt, 1);
}

#define MXP 10
ll Pri[MXP];
ll C; //mul of all Pri
int P;
ll crt()
{
    ll ans = 0;
    FOR(i,0,P-1)
    {
        ll mi = C/Pri[i];
        ll yi = modinv(mi, Pri[i]).fi;
        ans+=R[i]*mi*yi%C;
    }
    return ans%C;
}
