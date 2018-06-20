#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define INF 2147483647
typedef long long ll;
#define MAXN 32
int n, m, Max;
ll v[MAXN], deg[MAXN]; //neighbors

void update_maximum(ll R)
{
    int Size = 0;
    while(R)
    {
        if(R&1)Size++;
        R>>=1;
    }
    Max = max(Size, Max);
}

int pickPivot(ll P)
{
    int pivot = -1, Max = -1;
    memset(deg, 0, sizeof(deg));
    for(int i = 0; i < n; i++)
    {
        if(P&(1LL<<i)) //i is in P
        {
            if(pivot == -1) //i = default pivot
            {
                pivot = i;
                Max = deg[i];
            }
            for(int j = 0; j < i; j++)
            {
                if((P&(1LL<<j))&&(v[i]&(1LL<<j)))
                {
                    deg[i]++;
                    if(deg[i] > Max)
                    {
                        Max = deg[i];
                        pivot = i;
                    }
                    deg[j]++;
                    if(deg[j] > Max)
                    {
                        Max = deg[j];
                        pivot = j;
                    }
                }
            }
        }
    }
    return pivot;
}

void BronKerbosch(ll R, ll P, ll X)
{
    if(!P) //P is empty, no candidates left
    {
        if(!X)
        {
            //clique
             update_maximum(R);
        }
        return;
    }
    int u = pickPivot(P|X);
    for(int i = 0; i <= n-1; i++)
    {
        if(P&(~v[u])&(1LL<<i)) //vi is in P
        {
            BronKerbosch( R|(1LL<<i), P&v[i], X&v[i] );
            P&=(~(1LL<<i));
            X|=(1LL<<i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n)
    {
        cin >> m;

        Max = 0;
        FOR(i,0,n-1)v[i] = 0;

        int a, b;
        FOR(i,1,m)
        {
            cin >> a >> b;
            v[a]|=(1LL<<b);
            v[b]|=(1LL<<a);
        }
        BronKerbosch(0, (1LL<<n)-1, 0);
        cout << Max << '\n';
    }

    return 0;
}

/*
Test Case :
31 10
0 1
0 2
0 3
0 4
1 2
1 3
1 4
2 3
2 4
3 4

5 6
0 1
1 2
1 3
1 4
2 3
3 4

*/
