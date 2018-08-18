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

double add(double a, double b)
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

bool par(P p1, P p2, P p3, P p4)
{
	return (p2-p1).det(p4-p3)==0;
}

bool operator<(const P& lhs, const P& rhs)
{
    return (lhs.x==rhs.x)?lhs.y<rhs.y:lhs.x<rhs.x;
}

bool operator==(const P& lhs, const P& rhs)
{
    return lhs.x==rhs.x&&lhs.y==rhs.y;
}

double len(P vec)
{
    return sqrt(add(vec.x*vec.x, vec.y*vec.y));
}

double dis(P p1, P p2)
{
    return len(p2-p1);
}

struct seg
{
    seg(){}
    seg(P _p1, P _p2)
    {
        p[0]=_p1;
        p[1]=_p2;
        if(p[1]<p[0])swap(p[0],p[1]);
    }
    P p[2];
};

bool par(seg& lhs, seg& rhs)
{
	return par(lhs.p[0],lhs.p[1],rhs.p[0],rhs.p[1]);
}

P intersection(seg& lhs, seg& rhs)//p and q Must not be parallel
{
    return intersection(lhs.p[0],lhs.p[1],rhs.p[0],rhs.p[1]);
}

bool on_seg(seg& sg, P q)
{
    return on_seg(sg.p[0],sg.p[1],q);
}
