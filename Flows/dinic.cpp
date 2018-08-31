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
#define MAXV 100
#define INF 2147483647
int N, M, S, T;

struct edge{ int to, cap, rev; };
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];

void add_edge(int from, int to, int cap)
{
    G[from].pb((edge){to, cap, G[to].size()});
    G[to].pb((edge){from, 0, G[from].size()-1});
}

void bfs(int S)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[S] = 0;
    q.push(S);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v]+1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v==t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int S, int T)
{
    int flow = 0;
    while(true)
    {
        bfs(S);
        if(level[T] < 0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(S, T, INF)) > 0)flow+=f;
    }
}

/*

testcase 1:
5 7 4 5
4 1 10
4 2 2
1 2 6
1 3 6
3 2 3
2 5 5
3 5 8

*/
