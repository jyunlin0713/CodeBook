#include <iostream>
#include <algorithm>
using namespace std;
struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}

struct dset
{
    dset(int n):size(n){ p = new int [n]; for(int i = 0; i < size; i++)p[i] = i; }
    ~dset(){delete [] p;}

    void Union(int x, int y) //請先檢查兩人屬於不同group
    {
        p[Find(x)] = Find(y);
    }
    int Find(int i)
    {
        if(p[i] != i) p[i] = Find(p[i]);
        return p[i];
    }

    int size;
    int * p;
};

edge es[100];
int v, e;

int kruskal()
{
    sort(es, es + e, comp);
    dset s(v);
    int res = 0;
    for(int i = 0; i < e; i++)
    {
        edge E = es[i];
        if(s.Find(E.u) != s.Find(E.v))
        {
            s.Union(E.u, E.v);
            res += E.cost;
        }
    }
    return res;
}

int main()
{
    cin >> v >> e;
    for(int i = 0; i < e; i++)
        cin >> es[i].u >> es[i].v >> es[i].cost;
    cout << kruskal() << '\n';
}











