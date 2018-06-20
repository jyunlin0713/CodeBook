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
typedef long long ll;
int V;
vector<int> G[MAXV];
int match[MAXV];
bool used[MAXV];

void add_edge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

bool bfs(int v)
{
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i], w = match[u];
        if(w < 0 || (!used[w] && dfs(w)))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < V; v++)
    {
        if(match[v] < 0)
        {
            memset(used, 0, sizeof(used));
            if(dfs(v))res++;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

