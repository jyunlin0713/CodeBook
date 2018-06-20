#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct edge{int to, cost;};
typedef pair<int, int> P; //f = min distance, s = v id
#define f first
#define s second
#define INF 2147483647

int V, E, S, F;
vector<edge> G[100];
int d[100];

void dijkstra()
{
    priority_queue<P, vector<P>, greater<P>> q;
    fill(d, d + V, INF);
    d[S] = 0;
    q.push(P(0, S));

    while(!q.empty())
    {
        P p = q.top(); q.pop();
        int v = p.s;
        if(d[v] < p.f) continue;
        for(int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge e1, e2;
        e1.to = b;
        e2.to = a;
        e1.cost = e2.cost = c;
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    cin >> F >> S;
    dijkstra();
    cout << d[F] << '\n';
}
