struct DSU
{
    int pa[MXN], sz[MXN];
    void init(int n)
    {
        FOR(i,0,n)
        {
            pa[i]=i;
            sz[i]=1;
        }
    }
    int Find(int x)
    {
        return (x==pa[x]) ? x : (pa[x]=Find(pa[x]));
    }
    int Merge(int x, int y)
    {
        x = Find(x), y = Find(y);
        if(x==y)return 0;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        pa[y]=x;
        return 1;
    }
} dsu;
