#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
void init(int n){
    memset(head,-1,(n+2)*sizeof(int));
    tot=0;
}
void add(int u,int v,ll w){
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int size[MAXN],n;
double dfs(int u,int fa){
    size[u]=1;
    double ans=0;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        ll  w=cost[i];
        if(v==fa) continue;
        ans+=dfs(v,u);
        size[u]+=size[v];
        ans+=(double)(w*size[v]*(n-size[v]))/n/(n-1)*2.0;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>n;
        init(n);
        rep(i,1,n-1){
            ll u,v,w;
            cin>>u>>v>>w;
            u++; v++;
            add(u,v,w);
            add(v,u,w);
        }
        cout<<fixed<<setprecision(8)<<dfs(1,-1)<<endl;
    }
    return 0;
}