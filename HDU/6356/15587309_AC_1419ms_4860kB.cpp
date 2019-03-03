#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
using namespace std;
const int MAXN = 1e5 + 11;
const int MOD = 1ll<<30;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
int ans[MAXN];
struct ST{
    int mx[MAXN<<2],mn[MAXN<<2];
    int lazy[MAXN<<2];
    #define lc o<<1
    #define rc o<<1|1
    void build(int o,int l,int r){
        mx[o]=mn[o]=lazy[o]=0;
        if(l==r) return;
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
    }
    void pu(int o){
        mx[o]=max(mx[lc],mx[rc]);
        mn[o]=min(mn[lc],mn[rc]);
    }
    void pd(int o){
        if(lazy[o]){
            mx[lc]=mx[rc]=mn[lc]=mn[rc]=lazy[lc]=lazy[rc]=lazy[o];
            lazy[o]=0;
        }
    }
    void query(int o,int l,int r,int L,int R){
        if(l==r) ans[l]=mn[o];
        if(l==r) return;
        int mid=l+r>>1;
        pd(o);
        if(L<=mid) query(lc,l,mid,L,R);
        if(R>mid)  query(rc,mid+1,r,L,R);
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(mn[o]>=v) return;
        if(l==r) mx[o]=mn[o]=max(mx[o],v);
        if(l==r) return;
        if(L<=l&&r<=R){
            if(mx[o]<=v){
                mx[o]=mn[o]=lazy[o]=v;
                return;
            }
        }
        int mid=l+r>>1;
        pd(o);
        if(L<=mid) update(lc,l,mid,L,R,v);
        if(R>mid)  update(rc,mid+1,r,L,R,v);
        pu(o);
    }
}st;
unsigned int X,Y,Z,W;
unsigned int rng(){
    X=X^(X<<11);
    X=X^(X>>4);
    X=X^(X<<5);
    X=X^(X>>14);
    W=X^(Y^Z);
    X=Y;
    Y=Z;
    Z=W;
    return Z;
}
int main(){
    int T=read();
    while(T--){
        int n=read();
        int m=read();
        X=read();
        Y=read();
        Z=read();
        st.build(1,1,n);
        while(m--){
            unsigned int f[3];
            rep(i,0,2) f[i]=rng();
            int l=min(f[0]%n,f[1]%n)+1;
            int r=max(f[0]%n,f[1]%n)+1;
            int v=f[2]%(1<<30);
            st.update(1,1,n,l,r,v);
        }
        st.query(1,1,n,1,n);
        ll res=0;
        rep(i,1,n) res=res^(1ll*i*ans[i]);
        println(res);
    }
    return 0;
}