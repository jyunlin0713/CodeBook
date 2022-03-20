//range sum, single add
struct
{
    void up(int id)
    {
        st[id] = st[id*2] + st[id*2+1];
    }
    void build(int l, int r, int id)
    {
        if(l==r)
        {
            st[id]=0;
            return;
        }
        int m = (l+r)/2;
        build(l,m,id*2);
        build(m+1,r,id*2+1);
        up(id);
    }
    ll Sum(int L, int R, int l, int r, int id)
    {
        if( l>=L && r<=R )return st[id];
        if( l>R || r<L )return 0;
        int m = (l+r)/2;
        return Sum(L,R,l,m,id*2)+Sum(L,R,m+1,r,id*2+1);
    }
    void Add(int p, ll x, int l, int r, int id)
    {
        if(l==r)
        {
            st[id]+=x;
            return;
        }
        int m = (l+r)/2;
        if(p<=m)Add(p,x,l,m,id*2);
        else Add(p,x,m+1,r,id*2+1);
        up(id);
    }
    ll st[MXN*4];
}segt;
