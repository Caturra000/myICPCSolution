#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pr = pair<ll,ll>;
const int MAXN = 2e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
const ll MOD = 1000000007;
ll f[MAXN],g[MAXN];
//f[]:子树下的最远点
//g[]:子树以外的最远点
bool mark[MAXN];
int best[MAXN],p[MAXN];
int n,m,d;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
ll dfs0(int u,int fa){
    if(~f[u]) return f[u];
    ll ans=-INF; //子树下没有mark就是负无穷
    if(mark[u]) ans=0;
    ll tmp=-INF;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        ans=max(ans,dfs0(v,u)+1);
        if(best[u]==-1||f[v]>tmp){
            tmp=f[v];
            best[u]=v;
        }
    }
    return f[u]=ans;
}
void dfs1(int u,int fa){
    p[u]=fa;
    ll ans=-INF;
    if(mark[u]) ans=0;
    if(~fa) ans=max(ans,g[fa]+1);
    if(~fa){
        if(u==best[fa]){ //best点不必优先处理,但是best的g要枚举所有其他兄弟
            for(int i=head[fa];~i;i=nxt[i]){
                int v=to[i];
                if(v==u) continue;
                if(v==p[fa]) continue;
                ans=max(ans,f[v]+2);
            }
        }else if(~best[fa]){ //而非best点只需从best里转移过来即可
            ans=max(ans,f[best[fa]]+2);
        }
    }
    g[u]=ans;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs1(v,u);
    }
}
int main(){
    fastIO;
    while(cin>>n>>m>>d){
        init();
        memset(f,-1,sizeof f);
        memset(g,-1,sizeof g);
        memset(mark,0,sizeof mark);
        memset(best,-1,sizeof best);
        rep(i,1,m){
            int t;
            cin>>t;
            mark[t]=1;
        }
        rep(i,1,n-1){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs0(1,-1);
        dfs1(1,-1);
        int ans=0;
        rep(i,1,n) if(max(f[i],g[i])<=d) ans++;
        cout<<ans<<endl;
    }
    return 0;
}