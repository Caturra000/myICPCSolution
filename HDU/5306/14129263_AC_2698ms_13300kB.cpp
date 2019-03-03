#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e6+11;
const int NN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
ll read() {
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int mx[MAXN<<2],smx[MAXN<<2],mxcnt[MAXN<<2];
    ll sum[MAXN<<2];
    bool lazy[MAXN<<2];
    void init(){
        memset(mx,0x80,sizeof mx);
        memset(smx,0x80,sizeof smx);
        memset(mxcnt,0,sizeof mxcnt);
        memset(sum,0,sizeof sum);
        memset(lazy,0,sizeof lazy);
    }
    void pu(int o){
        mx[o]=max(mx[lc],mx[rc]);
        sum[o]=sum[lc]+sum[rc];
        smx[o]=max(smx[lc],smx[rc]);
        mxcnt[o]=0;
        if(mx[lc]!=mx[rc]) smx[o]=max(smx[o],min(mx[lc],mx[rc]));//
        if(mx[lc]==mx[o]) mxcnt[o]+=mxcnt[lc];
        if(mx[rc]==mx[o]) mxcnt[o]+=mxcnt[rc];
    }
    void pd(int o){
        if(lazy[o]){
            if(mx[lc]>mx[o]){
                lazy[lc]=1;
                sum[lc]-=1ll*(mx[lc]-mx[o])*mxcnt[lc];
                mx[lc]=mx[o];
            }
            if(mx[rc]>mx[o]){
                lazy[rc]=1;
                sum[rc]-=1ll*(mx[rc]-mx[o])*mxcnt[rc];
                mx[rc]=mx[o];
            }
            lazy[o]=0;
            // lazy[lc]=lazy[rc]=1;
        }
    }
    void build(int o,int l,int r){
        mx[o]=smx[o]=-INF;mxcnt[o]=lazy[o]=sum[o]=0;
        if(l==r){
            sum[o]=mx[o]=a[l];
            // smx[o]=-INF;
            mxcnt[o]=1;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(mx[o]<=v) return; // quan ju jian zhi
        if(L<=l&&r<=R){
            // if(mx[o]<=v)return;
            if(smx[o]<v){//zhi gai bian zui da zhi
                // pd(o);
                lazy[o]=1;
                sum[o]-=1ll*(mx[o]-v)*mxcnt[o];
                mx[o]=v;//mxcnt bu bian
                return;
            }
        }
        pd(o);
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R,v);
        if(R>mid) update(rc,mid+1,r,L,R,v);
        pu(o);
    }
    ll queryMax(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return mx[o];
        }
        pd(o);
        int mid=l+r>>1;
        ll res=-INF;
        if(L<=mid) res=max(res,queryMax(lc,l,mid,L,R));
        if(R>mid) res=max(res,queryMax(rc,mid+1,r,L,R));
        return res;
    }
    ll querySum(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return sum[o];
        }
        pd(o);
        int mid=l+r>>1;
        ll res=0;
        if(L<=mid) res+=querySum(lc,l,mid,L,R);
        if(R>mid) res+=querySum(rc,mid+1,r,L,R);
        return res;
    }
}st;
int main(){
    int T=read();
    while(T--){
        int n=read();
        int m=read();
        rep(i,1,n) a[i]=read();
        st.build(1,1,n);
        rep(i,1,m){
            int op=read();
            int x=read();
            int y=read();
            if(op==0){
                int t=read();
                st.update(1,1,n,x,y,t);
            }else if(op==1){
                println(st.queryMax(1,1,n,x,y));
            }else{
                println(st.querySum(1,1,n,x,y));
            }
        }
    }
    return 0;
}