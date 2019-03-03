#include<bits/stdc++.h>
#include<unordered_map>
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
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
int sz[MAXN],p[MAXN][21],dep[MAXN];
void add(int u,int v){
    to[tot]=v,nxt[tot]=head[u];
    head[u]=tot++;
}
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void dfs(int u,int fa,int d){
    dep[u]=d;sz[u]=1;
    rep(i,0,20){
        if(u==1) p[u][i]=u;
        else if(i) p[u][i]=p[p[u][i-1]][i-1];
        else p[u][i]=fa;
    }
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u,d+1);
        sz[u]+=sz[v];
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int t=dep[u]-dep[v];
    rep(i,0,20){
        if(t>>i&1) u=p[u][i];
    }
    if(u==v) return u;
    rrep(i,20,0){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int rmq(int u,int k){
    rep(i,0,20){
        if(k>>i&1) u=p[u][i];
    }
    return u;
}
int main(){
    int n,m;
    while(cin>>n){
        init();
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);add(v,u);
        }
        dfs(1,-1,1);
        m=read();
        while(m--){
            int u=read();
            int v=read();
            int anc=lca(u,v);
            int dis=dep[u]+dep[v]-2*dep[anc];
            if(dis&1){
                println(0);
                continue;
            }
            if(u==v){
                println(n);
                continue;
            }
            dis>>=1;
            if(dep[u]<dep[v]) swap(u,v);
            if(dep[anc]==dep[u]-dis){
                println(n-sz[rmq(u,dis-1)]-sz[rmq(v,dis-1)]);
            }else{
                println(sz[rmq(u,dis)]-sz[rmq(u,dis-1)]);
            }
        }
    }
    return 0;
}