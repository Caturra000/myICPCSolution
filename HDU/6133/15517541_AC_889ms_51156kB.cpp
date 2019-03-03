#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 2e6+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[MAXN],b[MAXN],c[MAXN];
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
struct FT{
    ll ft[MAXN];
    int tot;
    void init(int t){for(tot=t=t<<1|1;t;--t)ft[t]=0;}
    #define lowbit(x) (x&-x)
    void update(int k,int v){while(k<tot)ft[k]+=v,k+=lowbit(k);}
    ll query(int k){return k>0?ft[k]+query(k-lowbit(k)):0;}
}ft[2];
int size[MAXN],son[MAXN],st[MAXN],ed[MAXN],pre[MAXN],CLOCK;
void init(){
    memset(head,-1,sizeof head);
    tot=CLOCK=0;
}
void dfs(int u,int fa){
    size[u]=1;son[u]=0;
    st[u]=++CLOCK;pre[CLOCK]=u;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    ed[u]=CLOCK;
}
ll ans[MAXN];
void solve(int u,int fa,bool keep){
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        if(v==son[u]) continue;
        solve(v,u,0);
    }
    if(son[u]) solve(son[u],u,1);
    ll t=ans[son[u]];
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        if(v==son[u]) continue;
        rep(j,st[v],ed[v]){
            t+=a[pre[j]];
            t+=ft[0].query(c[pre[j]]-1);
            ft[0].update(c[pre[j]],a[pre[j]]);
            t+=(ft[1].query(ft[1].tot)-ft[1].query(c[pre[j]]-1))*a[pre[j]];
            ft[1].update(c[pre[j]],1);
        }
    }
    t+=a[u];
    t+=ft[0].query(c[u]-1);
    ft[0].update(c[u],a[u]);
    t+=(ft[1].query(ft[1].tot)-ft[1].query(c[u]-1))*a[u];
    ft[1].update(c[u],1);
    ans[u]=t;
    if(!keep) rep(j,st[u],ed[u]){
        ft[0].update(c[pre[j]],-a[pre[j]]);
        ft[1].update(c[pre[j]],-1);
    }
}
int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n) b[i]=a[i]=read();
        sort(b+1,b+1+n);
        int m=unique(b+1,b+1+n)-b-1;
        rep(i,1,n) c[i]=lower_bound(b+1,b+1+n,a[i])-b;
        rep(i,0,1) ft[i].init(max(n,m));
        init();
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);
            add(v,u);
        }
        memset(ans,0,sizeof ans);
        dfs(1,-1);
        solve(1,-1,1);
        rep(i,1,n) printbk(ans[i]); puts("");
    }
    return 0;
}