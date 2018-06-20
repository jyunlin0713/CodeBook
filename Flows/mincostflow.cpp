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

#define MAXV 10000
struct edge {int to, cap, cost, rev;};
int V,E,S,T,F;
vector<edge> G[MAXV];
int h[MAXV], dist[MAXV], prevv[MAXV], preve[MAXV];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].pb((edge){to, cap, cost, G[to].size()});
    G[to].pb((edge){from, 0, -cost, G[from].size()-1});
}

int min_cost_flow(int S, int T, int F)
{
    int res = 0;
    fill(h, h+V, 0);
    while(F > 0)
    {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        fill(dist, dist+V, INF);
        dist[S] = 0;
        pq.push(mkp(0,S));
        while(!pq.empty())
        {
            pii p = pq.top(); pq.pop();
            int v = p.s;
            if(dist[v] != p.f)continue;
            for(int i = 0; i < G[v].size(); i++)
            {
                edge& e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(mkp(dist[e.to], e.to));
                }
            }
        }
        if(dist[T] == INF)return -1;//can't send f
        for(int v = 0; v < V; v++)
        {
            h[v] += dist[v];
        }
        int d = F;
        for(int v = T; v != S; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        F-=d;
        res+=d*h[T];
        for(int v = T; v != S; v = prevv[v])
        {
            edge& e = G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> S >> T >> F;
    int u, v, c, d;
    FOR(i,1,E)
    {
        cin >> u >> v >> c >> d;
        add_edge(u,v,c,d);
    }
    cout << min_cost_flow(S,T,F) << '\n';

    return 0;
}

/**********\
TESTCASES 1:

5 7 0 4 9
0 1 10 2
0 2 2 4
1 2 6 6
1 3 6 2
2 4 5 2
3 2 3 3
3 4 8 6

\**********/
