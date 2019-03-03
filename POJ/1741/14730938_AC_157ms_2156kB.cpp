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
//#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
bool vis[MAXN],block[MAXN];
int dis[MAXN],belong[MAXN],cnt[MAXN],sz[MAXN];
int to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],head[MAXN],tot;
vector<int> vec;
void init(){
    memset(head,-1,sizeof head);
    memset(vis,0,sizeof vis);
    memset(block,0,sizeof block);
    tot=0;
}
void add(int u,int v,int w){
    to[tot]=v;cost[tot]=w;
    nxt[tot]=head[u];head[u]=tot++;
}
int mxsize,mxson,V;//V==N // each V of subtrees can obtain using sz
int getroot(int u,int fa){
    sz[u]=1;
    int tmp=0;//max size of subtrees while u deleted
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        if(block[v]) continue;
        getroot(v,u);
        sz[u]+=sz[v];
        tmp=max(tmp,sz[v]);
    }
    tmp=max(tmp,V-sz[u]);
    if(tmp<mxsize){
        mxsize=tmp;
        mxson=u;// top and down compared
    }
    return mxson;
}
bool cmp(int a,int b){return dis[a]<dis[b];}
void prepare(int u,int fa,int d,int son,int rt){
    dis[u]=d; vec.push_back(u);
    belong[u]=son; cnt[son]=0;
    erep(i,u){
        int v=to[i],w=cost[i];
        if(v==fa) continue;
        if(block[v]) continue;
        prepare(v,u,d+w,son==rt?v:son,rt);
    }
}
int getV(int u,int fa){
    sz[u]=1;
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        if(block[v]) continue;
        getV(v,u);
        sz[u]+=sz[v];
    }
    return sz[u];
}

ll solve(int u,int fa){
    if(vis[u]||u<1) return 0;
    vis[u]=1;
    
    ll ans=0;
    vec.clear();
    prepare(u,fa,0,u,u);
    sort(vec.begin(),vec.end(),cmp);
    int L,R=vec.size();R--;
    for(int i=0;i<vec.size();i++) cnt[belong[vec[i]]]++;
    bool flag=0;
    for(int i=0;i+1<(int)vec.size();i++){//enum L
        L=i;cnt[belong[vec[L]]]--;
        while(dis[vec[L]]+dis[vec[R]]>k){
            if(L>=R) break;
            cnt[belong[vec[R]]]--;
            R--;
        }
        if(L>=R) break;
        ans+=(ll)R-L-cnt[belong[vec[L]]];
    }
    while(L<vec.size()) cnt[belong[vec[L++]]]=0;
    block[u]=1;
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        if(block[v]) continue;
        V=getV(v,u);
        mxson=v,mxsize=INF;
        int rt=getroot(v,u);
        ans+=solve(rt,u);
    }
    return ans;
}
int main(){
    while(cin>>n>>k){
        if(n==0&&k==0) break;
        init();
        rep(i,1,n-1){
            int u=read();
            int v=read();
            int w=read();
            add(u,v,w);
            add(v,u,w);
        }
        mxsize=INF;mxson=1;V=n;
        int rt=getroot(1,-1);
        println(solve(rt,-1));
    }
    return 0;
}