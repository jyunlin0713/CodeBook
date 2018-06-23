#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
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

double EPS = 1e-10;

double add(double a, double b) //加起來夠小直接=0
{
    if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0;
    else return a+b;
}

struct P//struct for 2d vector/point
{
    double x,y;
    P(){}
    P(double x, double y):x(x),y(y){}
    P operator+(P p){return P(add(x,p.x), add(y,p.y));}
    P operator-(P p){return P(add(x,-p.x), add(y,-p.y));}
    P operator*(double d){return P(x*d,y*d);}
    double dot(P p){return add( x*p.x, y*p.y );}
    double det(P p){return add( x*p.y, -y*p.x );}
};

//is point q on p1p2
bool on_seg(P p1, P p2, P q)
{
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}

P intersection(P p1, P p2, P q1, P q2)//p and q Must not be parallel
{
    return p1 + (p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}

#define MAXN 20
#define MAXQ 2000
int N, Q;
P p[MAXN], q[MAXN];
int Q1[MAXQ], Q2[MAXQ];

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

void solve()
{
    dset Ds(N+1);
    FOR(i,2,N)
        FOR(j,1,i-1)
        {
            //case: parallel
            if((q[i]-p[i]).det(q[j]-p[j])==0)
            {
                if(on_seg(p[i],q[i],p[j]) || on_seg(p[i],q[i],q[j])
                || on_seg(p[i],q[i],p[j]) || on_seg(p[i],q[i],q[j]))
                    if(Ds.Find(i)!=Ds.Find(j))Ds.Union(i,j);
            }
            else//case: not parallel
            {
                P r = intersection(p[i],q[i],p[j],q[j]);
                if( on_seg(p[i],q[i],r) && on_seg(p[j],q[j],r) )
                    if(Ds.Find(i)!=Ds.Find(j))Ds.Union(i,j);
            }
        }
    FOR(i,0,Q-1)
        if(Ds.Find(Q1[i])==Ds.Find(Q2[i]))cout << "CONNECTED\n";
        else cout << "NOT CONNECTED\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while(N)
    {
        FOR(i,1,N)cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
        Q = 0;
        cin >> Q1[Q] >> Q2[Q];
        while(Q1[Q])
        {
            Q++;
            cin >> Q1[Q] >> Q2[Q];
        }
        solve();
        cin >> N;
    }

    return 0;
}
