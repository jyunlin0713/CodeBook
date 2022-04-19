#define MXA 12000001
const int mxa = 12000000;
int mnp[MXA];//minimum pf
vector<int> prime;
 
void sieve()
{
    for( int i = 1; i <= mxa; i++ ) mnp[i]=i;
    for( int i = 2; i <= mxa; i++ )
    {
        if( mnp[i]==i )
        {
            prime.pb(i);
        }
        for( int pi : prime )
        {
            int j = pi*i;
            if( j>mxa )break;
            mnp[j] = pi;
            if( i%pi==0 )break;
        }
    }
}
 
void dfs( int now, int i, int n, const vector<pii> & v )
{
    if(i==n)
    {
        cnt[now]++;
        return;
    }
    for( int j = 0; j <= v[i].s; j++ )
    {
        dfs( now, i+1, n, v );
        now*=v[i].f;
    }
}
 
void enum_factor(int x)
{
    vector<pii> vec;
    int pi = mnp[x];
    while( pi!=1 )
    {
        if( vec.empty() || vec.back().f!=pi )vec.pb( mkp(pi, 1) );
        else vec.back().s++;
        x /= pi;
        pi = mnp[x];
    }
    int n = vec.size();
    dfs( 1, 0, n, vec );
}

vector<pii> getpf(int x)
{
    vector<pii> vec;
    int pi = mnp[x];
    while( pi!=1 )
    {
        if( vec.empty() || vec.back().fi!=pi )vec.pb( mkp(pi, 1) );
        else vec.back().sc++;
        x /= pi;
        pi = mnp[x];
    }
    return vec;
}
