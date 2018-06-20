#include <iostream>
using namespace std;
int d[100][100];
int v, e, s, f;
#define INF 2147483647

void init()
{
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
}

void floyd_warshall()
{
    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                if(d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> v >> e;
    init();
    int a, b, c;
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }
    floyd_warshall();
    cin >> s >> f;
    cout << d[s][f] << '\n';
}
