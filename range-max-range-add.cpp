//range max, range add
struct
{
    ll Get(int id){ return st[id]+ad[id]; }
    void up(int id)
    {
        st[id] = max(Get(id*2), Get(id*2+1));
    }
    void down(int l, int r, int id)
    {
        ll val = ad[id];
        ad[id] = 0;
        st[id]+=val;
        if(l==r)return;
        ad[id*2]+=val, ad[id*2+1]+=val;
    }
    void build(int l, int r, int id)
    {
        ad[id] = 0;
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
    ll Max(int L, int R, int l, int r, int id)
    {
        down(l,r,id);
        if( l>=L && r<=R )return st[id];
        if( l>R || r<L )return 0;
        int m = (l+r)/2;
        return max(Max(L,R,l,m,id*2),Max(L,R,m+1,r,id*2+1));
    }
    void Add(int L, int R, ll x, int l, int r, int id)
    {
        down(l,r,id);
        if( l>=L && r<=R )
        {
            ad[id]+=x;
            return;
        }
        if( l>R || r<L )return;

        int m = (l+r)/2;
        Add(L,R,x,l,m,id*2);
        Add(L,R,x,m+1,r,id*2+1);
        up(id);
    }
    ll st[MXN*4], ad[MXN*4];
}segt;
