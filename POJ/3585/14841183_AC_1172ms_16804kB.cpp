#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
const int MOD = 1e9+7;
typedef long long ll;
unsigned int xjb=2333333;
int Rand(){
    return (xjb=xjb*12345+23333)%MOD+1;
}
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],head[MAXN],tot;
int deg[MAXN];
void add(int u,int v,int w){
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
ll f[MAXN],g[MAXN],n;
void DP(int u,int fa){
    f[u]=0;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        ll w=cost[i];
        if(v==fa) continue;
        DP(v,u);
        if(deg[v]==1) f[u]+=w;
        else f[u]+=min(w,f[v]);
    }
}
void dfs(int u,int fa){
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        ll w=cost[i];
        if(v==fa) continue;
        if(deg[u]==1) g[v]=f[v]+w;
        else g[v]=f[v]+min(w,g[u]-min(w,f[v]));
        dfs(v,u);
    }
}
int main(){
    int T=0; cin>>T;
    while(T--){
        init();
        memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        memset(deg,0,sizeof deg);
        n=read();
        rep(i,1,n-1){
            int u=read();
            int v=read();
            int w=read();
            add(u,v,w);
            add(v,u,w);
            deg[u]++;
            deg[v]++;
        }
        DP(1,0);g[1]=f[1];
        dfs(1,0);
        ll ans=0;
        rep(i,1,n) ans=max(ans,g[i]);
        println(ans);
    }
    return 0;
}