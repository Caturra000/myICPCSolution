#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int b[MAXN];
bitset<MAXN> a[31];
struct ST{
    int val[MAXN<<2],num[MAXN<<2];
    bool flip[MAXN<<2];
    #define lc o<<1
    #define rc o<<1|1
    void pu(int o){
        val[o]=val[lc]+val[rc];
        num[o]=num[lc]+num[rc];
    }
    void build(int o,int l,int r,int i){
        num[o]=val[o]=flip[o]=0;
        if(l==r){
            val[o]=a[i][l];
            num[o]=1;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid,i);
        build(rc,mid+1,r,i);
        pu(o);
    }
    void pd(int o){
        if(flip[o]){
            val[lc]=num[lc]-val[lc];
            val[rc]=num[rc]-val[rc];
            flip[lc]^=1;
            flip[rc]^=1;
            flip[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(v==0) return;
        if(L<=l&&r<=R){
            val[o]=num[o]-val[o];
            flip[o]^=1;
            return;
        }
        pd(o);
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R,v);
        if(R>mid) update(rc,mid+1,r,L,R,v);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return val[o];
        }
        pd(o);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid) ans+=query(lc,l,mid,L,R);
        if(R>mid) ans+=query(rc,mid+1,r,L,R);
        return ans;
    }
}st[31];
int main(){
    int n,m,op,l,r,x;
    while(cin>>n){
        rep(i,1,n) b[i]=read();
        rep(i,0,30) a[i].reset();
        rep(i,0,30){
            rep(j,1,n){
                a[i][j]=b[j]>>i&1;
            }
            st[i].build(1,1,n,i);
        }
        m=read();
        while(m--){
            op=read();
            l=read();
            r=read();
            if(op==1){
                ll res=0;
                rep(i,0,30){
                    res+=st[i].query(1,1,n,l,r)<<i;
                }
                println(res);
            }else{
                x=read();
                rep(i,0,30){
                    st[i].update(1,1,n,l,r,x>>i&1);
                }
            }
        }
    }
    return 0;
}