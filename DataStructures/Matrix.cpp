#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
int t;
ll N, a1, a2, b1, w, x, y, z;

struct Mat
{
    ll m[4][4];
    Mat(){memset(m, 0, sizeof(m));}
};

Mat matMul(const Mat &A, const Mat &B)
{
    Mat rtn;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
            {
                rtn.m[i][j]+=(A.m[i][k]*B.m[k][j])%MOD;
                rtn.m[i][j]%=MOD;
            }
    return rtn;
}

Mat matPow(Mat M, ll p)
{
    if(p == 0)
    {
        Mat iden;
        iden.m[0][0] = iden.m[1][1] = iden.m[2][2] = iden.m[3][3] = 1;
        return iden;
    }
    if(p == 1)return M;
    Mat rtn = matPow(M, p/2);
    if(p%2)return matMul(matMul(rtn, rtn), M);
    else return matMul(rtn, rtn);
}
