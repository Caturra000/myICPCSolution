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
int a[MAXN],b[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int stb[MAXN<<2],sta[MAXN<<2],len[MAXN<<2];
    bool lazy[MAXN<<2];
    void pd(int o){
        if(lazy[o]){
            sta[lc]=sta[rc]=sta[o];//a-start
            stb[lc]=stb[rc]=stb[o];//b-start
            len[lc]=len[rc]=len[o];
            lazy[lc]=lazy[rc]=1;
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r){
        lazy[o]=stb[o]=sta[o]=len[o]=0;
        if(l==r) return;
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);   
    }
    void update(int o,int l,int r,int L,int R,int L1,int R1){
        if(L<=l&&r<=R){
            lazy[o]=1;
            sta[o]=L1,stb[o]=L;
            len[o]=R1-L1+1;
            return;
        }
        pd(o);
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R,L1,R1);
        if(R>mid) update(rc,mid+1,r,L,R,L1,R1);
    }
    int query(int o,int l,int r,int x){
        if(l==r){
            if(sta[o]==0) return b[l];
            int from=sta[o];
            int to=stb[o];
            int d=l-to;
            return a[from+d];
        }
        pd(o);
        int mid=l+r>>1;
        if(x<=mid) return query(lc,l,mid,x);
        else return query(rc,mid+1,r,x);
    }
}st;
int main(){
    int n,m;
    while(cin>>n>>m){
        rep(i,1,n) a[i]=read();
        rep(i,1,n) b[i]=read();
        st.build(1,1,n);
        while(m--){
            int op=read();
            if(op==2) println(st.query(1,1,n,read()));
            else{
                int L1=read();
                int bs=read();
                int le=read();
                int R1=le+L1-1;
                st.update(1,1,n,bs,bs+le-1,L1,R1);
            }
        }
    }
    return 0;
}