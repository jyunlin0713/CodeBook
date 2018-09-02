#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
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

double add(double a, double b) //e
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

bool cmp(P& lhs, P& rhs)
{
    return lhs.x==rhs.x ? lhs.y<rhs.y : lhs.x<rhs.x;
}

double len2(P a, P b)
{
    return (b-a).dot(b-a);
}

double cross(P a, P b, P c)//ab X ac
{
    return (b-a).det(c-a);    
}

#define MAXN 50010
int N, top;
P p[MAXN], Stack[MAXN];

bool cmp_cc(P &pa, P &pb)//sort as counter clockwise
{
    double t = cross(p[0],pa,pb);
    if(t>0)return true;
    if(t<0)return false;
    return len2(p[0],pa) < len2(p[0],pb);
}

void getfirst()//get first point right
{
    int i = 0;
    FOR(j,1,N-1)if(cmp(p[j],p[i]))i=j;
    swap(p[0], p[i]);
}

void Graham()
{
    p[N] = p[0];
    top = 1;
    Stack[0] = p[0];
    Stack[1] = p[1];
    FOR(i,1,N-1)
    {
        while( top>=1 && cross(Stack[top-1], Stack[top], p[i])<=0 )top--;
        Stack[++top] = p[i];
    }
}

double rotatingCaliper()
{
    double ans = 0;
    int x = 2;
    Stack[top+1] = Stack[0];
    FOR(i,0,top)
    {
        while( cross( Stack[x+1], Stack[i], Stack[i+1] ) > 
                cross( Stack[x], Stack[i], Stack[i+1] ) )x=(x+1)%top;
        ans = max( ans, len2(Stack[i], Stack[x]) );
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    cin >> N;
    FOR(i,0,N-1){cin >> p[i].x >> p[i].y;}
    
    getfirst();
    sort(p+1, p+N, cmp_cc);
    Graham();
    
    cout << (ll)rotatingCaliper() << '\n';

    return 0;
}

