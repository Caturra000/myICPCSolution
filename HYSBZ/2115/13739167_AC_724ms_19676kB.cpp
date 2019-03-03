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
#include<bitset>
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
const int MAXN = 3e5+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7; 
unsigned int SEED = 17;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1];ll cost[MAXN<<1];
int head[MAXN<<1],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll w){
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
bool vis[MAXN];
ll dis[MAXN],tot2;
ll a[MAXN],b[66],n;
void dfs(int u,int fa){
    vis[u]=1;
    erep(i,u){
        ll v=to[i],w=cost[i];
        if(v==fa)continue;
        if(!vis[v]){
            dis[v]=dis[u]^w;
            dfs(v,u);
        }else{
            a[++tot2]=dis[u]^dis[v]^w;//环的异或值
        }
    }
}
void cal(int n){
    memset(b,0,sizeof b);
    rep(i,1,n){
        rrep(j,62,0){
            if(a[i]>>j&1){
                if(b[j]) a[i]^=b[j];
                else{
                    b[j]=a[i];
                    rrep(k,j-1,0) if(b[k]&&(b[j]>>k&1))b[j]^=b[k];
                    rep(k,j+1,62) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        init();
        rep(i,1,m){
            int u=read();
            int v=read();
            ll w=read();
            add(u,v,w);
        }
        tot2=0;
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        dfs(1,-1);
        cal(tot2);
        ll ans=dis[n];
        rep(i,0,62) ans=max(ans,ans^b[i]);
        println(ans);
    }
    return 0;
}
