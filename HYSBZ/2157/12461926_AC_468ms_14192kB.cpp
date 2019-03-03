#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e5+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int from[maxn<<1],to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],head[maxn],tot;
int size[maxn],fa[maxn],depth[maxn],top[maxn],son[maxn],dfn[maxn],pre[maxn],tot2;
void init(){
    memset(head,-1,sizeof head);
    memset(son,0,sizeof son);
    memset(size,0,sizeof size);
    memset(fa,0,sizeof fa);
    tot=tot2=0;
}
void add(int u,int v,int w=0){
    from[tot]=u;to[tot]=v;nxt[tot]=head[u];cost[tot]=w;
    head[u]=tot++;
    swap(u,v);
    from[tot]=u;to[tot]=v;nxt[tot]=head[u];cost[tot]=w;
    head[u]=tot++;
}
void dfs(int u,int p,int d){
    size[u]=1;fa[u]=p;depth[u]=d;
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        dfs(v,u,d+1);
        size[u]+=size[v];
        if(size[v]>size[son[u]]){//update
            son[u]=v;
        }
    }
}
void dfs2(int u,int tp){
    pre[++tot2]=u;
    dfn[u]=tot2;
    top[u]=tp;
    if(son[u]) dfs2(son[u],tp);//heavy --- ori top
    erep(i,u){
        int v=to[i];
        if(v==son[u]||v==fa[u])continue;
        dfs2(v,v);//light --- themselves
    }
}
int val[maxn<<2];
struct ST{
    int sum[maxn<<2],mx[maxn<<2],mn[maxn<<2];
    bool rev[maxn<<2];
    #define lc o<<1
    #define rc o<<1|1
    void pu(int o){
        sum[o]=sum[lc]+sum[rc];
        mx[o]=max(mx[lc],mx[rc]);
        mn[o]=min(mn[lc],mn[rc]);
    }
    void pd(int o){
        if(rev[o]){
            sum[lc]=-sum[lc];mx[lc]=-mx[lc];mn[lc]=-mn[lc];
            swap(mx[lc],mn[lc]);
            sum[rc]=-sum[rc];mx[rc]=-mx[rc];mn[rc]=-mn[rc];
            swap(mx[rc],mn[rc]);
            rev[lc]^=1;
            rev[rc]^=1;
            rev[o]=0;
        }
    }
    void build(int o,int l,int r){
        rev[o]=0;mx[o]=-oo;mn[o]=oo;
        if(l==r){
            sum[o]=mx[o]=mn[o]=val[pre[l]];//note
            return;
        }
        int m=l+r>>1;
        build(lc,l,m);
        build(rc,m+1,r);
        pu(o);
    }
    void update(int o,int l,int r,int k,int v){
        if(l==r){
            sum[o]=mx[o]=mn[o]=v;
            return;
        }
        pd(o);
        int m=l+r>>1;
        if(k<=m) update(lc,l,m,k,v);
        else update(rc,m+1,r,k,v);
        pu(o);
    }
    void flip(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            rev[o]^=1;
            sum[o]=-sum[o];
            mx[o]=-mx[o];
            mn[o]=-mn[o];
            swap(mx[o],mn[o]);
            return;
        }
        pd(o);
        int m=l+r>>1;
        if(L<=m) flip(lc,l,m,L,R);
        if(R>m) flip(rc,m+1,r,L,R);
        pu(o);
    }
    int query(int o,int l,int r,int L,int R,int op){
        if(L<=l&&r<=R){
            switch(op){
                case 1: return sum[o];
                case 2: return mx[o];
                case 3: return mn[o];
            }
        }
        pd(o);
        int m=l+r>>1;
        int ans;
        if(op==1){
            ans=0;
            if(L<=m) ans+=query(lc,l,m,L,R,op);
            if(R>m) ans+=query(rc,m+1,r,L,R,op);
        } 
        else if(op==2){
            ans=-oo;
            if(L<=m) ans=max(query(lc,l,m,L,R,op),ans);
            if(R>m) ans=max(query(rc,m+1,r,L,R,op),ans);
        }
        else{
            ans=oo;
            if(L<=m) ans=min(query(lc,l,m,L,R,op),ans);
            if(R>m) ans=min(query(rc,m+1,r,L,R,op),ans);
        }
        return ans;
    }
}st;
char str[555];
void solve(){
    int l,r,p1,p2,sum=0,mx=-oo,mn=oo;
    // iin(l);iin(r);l++;r++;
    l=read();r=read();l++;r++;
    p1=top[l];p2=top[r];
    while(p1!=p2){
        if(depth[p1]<depth[p2]){
            swap(p1,p2);
            swap(l,r);
        }
        if(str[0]=='N') st.flip(1,1,tot2,dfn[p1],dfn[l]);
        else if(str[0]=='S') sum+=st.query(1,1,tot2,dfn[p1],dfn[l],1);
        else if(str[1]=='I') mn=min(mn,st.query(1,1,tot2,dfn[p1],dfn[l],3));
        else if(str[1]=='A') mx=max(mx,st.query(1,1,tot2,dfn[p1],dfn[l],2));
        l=fa[p1];
        p1=top[l];
    }
    if(depth[l]>depth[r]) swap(l,r);
    if(l==r){
        // if(str[0]=='N') st.flip(1,1,tot2,dfn[l],dfn[r]);
        if(str[0]=='S') println(sum);
        else if(str[1]=='I') println(mn);
        else if(str[1]=='A') println(mx);
    }
    else{
        l=son[l];
        if(str[0]=='N'){
            st.flip(1,1,tot2,dfn[l],dfn[r]);
        }
        else if(str[0]=='S'){
            sum+=st.query(1,1,tot2,dfn[l],dfn[r],1);
            println(sum);
        }
        else if(str[1]=='I'){
            mn=min(mn,st.query(1,1,tot2,dfn[l],dfn[r],3));
            println(mn);
        }
        else if(str[1]=='A'){
            mx=max(mx,st.query(1,1,tot2,dfn[l],dfn[r],2));
            println(mx);
        }
    }
}
int main(){
    int n,u,v,w,x,y;
    while(~iin(n)){
        init();
        rep(i,1,n-1){
            u=read();v=read();w=read();
            // iin(u);iin(v);iin(w);
            u++;v++;
            add(u,v,w);
        }
        dfs(1,0,1);
        dfs2(1,1);
        rep(i,0,tot-1){
            if(depth[from[i]]>depth[to[i]]){//
                swap(from[i],to[i]);
            }
            val[to[i]]=cost[i];
        }
        st.build(1,1,tot2);
        int m=read();
        // int m; iin(m);
        rep(i,1,m){
            s0(str);
            if(str[0]=='C'){
                x=read();y=read();
                // iin(x);iin(y);
                st.update(1,1,tot2,dfn[to[(x-1)<<1]],y);//note
            }
            else solve();
        }
    }
    return 0;
}