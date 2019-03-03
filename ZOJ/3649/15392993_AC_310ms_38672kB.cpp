#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],head[MAXN],tot;
int pp[MAXN];
int p[MAXN][17],dep[MAXN];
int mn[MAXN][17],mx[MAXN][17];
int f[MAXN][17],g[MAXN][17];
int a[MAXN];
bool vis[MAXN];
struct EDGE{
    int from,to,cost;
    EDGE(){}
    EDGE(int f,int t,int c){
        from=f;
        to=t;
        cost=c;
    }
    bool operator<(const EDGE &rhs)const{
        return cost>rhs.cost;
    }
}e[MAXN];
void init(){
    memset(head,-1,sizeof head);
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    memset(mx,0,sizeof mx);
    memset(mn,0x3f,sizeof mn);
    memset(vis,0,sizeof vis);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int find(int x){return x==pp[x]?x:pp[x]=find(pp[x]);}
ll MST(int n,int m){
    sort(e+1,e+1+m);
    ll ans=0;
    rep(i,0,n) pp[i]=i;
    rep(i,1,m){
        int u=e[i].from;
        int v=e[i].to;
        int w=e[i].cost;
        int aa=find(u),bb=find(v);
        if(aa==bb) continue;
        pp[aa]=bb;
        ans+=1ll*w;
        add(u,v); add(v,u);
    }
    return ans;
}
void dfs(int u,int fa,int d){
    dep[u]=d; vis[u]=1;
    if(fa==-1) rep(j,0,16) p[u][j]=u,mn[u][j]=mx[u][j]=a[u];
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa||vis[v]) continue;
        rep(j,0,16){
            if(j){
                p[v][j]=p[p[v][j-1]][j-1];
                mx[v][j]=max(mx[v][j-1],mx[p[v][j-1]][j-1]);
                mn[v][j]=min(mn[v][j-1],mn[p[v][j-1]][j-1]);
                f[v][j]=max(f[v][j-1],f[p[v][j-1]][j-1]);
                g[v][j]=max(g[v][j-1],g[p[v][j-1]][j-1]);
                f[v][j]=max(f[v][j],mx[p[v][j-1]][j-1]-mn[v][j-1]);
                g[v][j]=max(g[v][j],mx[v][j-1]-mn[p[v][j-1]][j-1]);
            }else{
                p[v][j]=u;
                mn[v][j]=min(a[v],a[u]);
                mx[v][j]=max(a[v],a[u]);
                f[v][j]=a[u]-a[v];
                g[v][j]=a[v]-a[u];
            }
        }
        dfs(v,u,d+1);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    rep(j,0,16) if(d>>j&1){
        u=p[u][j];
    }
    if(u==v) return u;
    rrep(j,16,0) if(p[u][j]!=p[v][j]){
        u=p[u][j];
        v=p[v][j];
    }
    return p[u][0];
}
int MIN(int u,int anc){
    int d=dep[u]-dep[anc];
    int ans=1<<30;
    rep(j,0,16) if(d>>j&1){
        ans=min(ans,mn[u][j]);
        u=p[u][j];
    }
    return ans;
}
int MAX(int u,int anc){
    int d=dep[u]-dep[anc];
    int ans=0;
    rep(j,0,16) if(d>>j&1){
        ans=max(ans,mx[u][j]);
        u=p[u][j];
    }
    return ans;
}
int LEFT(int u,int anc){
    int d=dep[u]-dep[anc];
    int ans=0;
    int tmin=1<<29;
    rep(j,0,16) if(d>>j&1){
        ans=max(ans,f[u][j]);
        ans=max(ans,mx[u][j]-tmin);
        tmin=min(tmin,mn[u][j]);
        u=p[u][j];
    }
    return ans;
}
int RIGHT(int u,int anc){
    int d=dep[u]-dep[anc];
    int ans=0,tmax=0;
    rep(j,0,16) if(d>>j&1){
        ans=max(ans,g[u][j]);
        ans=max(ans,tmax-mn[u][j]);
        tmax=max(tmax,mx[u][j]);
        u=p[u][j];
    }
    return ans;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        init();
        rep(i,1,n) a[i]=read();
        int m=read();
        rep(i,1,m){
            int u=read();
            int v=read();
            int w=read();
            e[i]=EDGE(u,v,w);
        }
        println(MST(n,m));
        rep(i,1,n) if(!vis[i]) dfs(i,-1,1);
        int q=read();
        while(q--){
            int u=read();
            int v=read();
            int anc=lca(u,v);
            int ans=MAX(v,anc)-MIN(u,anc);
            ans=max(ans,LEFT(u,anc));
            ans=max(ans,RIGHT(v,anc));
            println(max(0,ans));
        }
    }
    return 0;
}