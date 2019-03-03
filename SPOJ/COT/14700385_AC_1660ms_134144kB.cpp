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
const int MAXN = 2e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll n,m,nn,a[MAXN],b[MAXN],c[MAXN];
int dep[MAXN],p[MAXN][21],dfn[MAXN],pre[MAXN],dfned[MAXN],CLOCK;
map<ll,ll> mp;
void init(){
    memset(head,-1,sizeof head);
    tot=CLOCK=0;
}
void add(int u,int v){
    to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
}
void dfs(int u,int fa,int d){
    dep[u]=d; //dfn[u]=++CLOCK;pre[CLOCK]=u;
    rep(j,0,20){
        if(u==1) p[u][j]=u;
        else if(!j) p[u][j]=fa;
        else p[u][j]=p[p[u][j-1]][j-1];
    }
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u,d+1);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    rep(i,0,20){
        if((dep[u]-dep[v])>>i&1){
            u=p[u][i];
        }
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
struct FST{
    int lc[MAXN<<5],rc[MAXN<<5];
    int cnt[MAXN<<5];
    int T[MAXN],tot;
    void init(){tot=0;}
    int build(int l,int r){
        int cur=++tot;
        lc[cur]=rc[cur]=cnt[cur]=0;
        if(l==r) return cur;
        int mid=l+r>>1;
        lc[cur]=build(l,mid);
        rc[cur]=build(mid+1,r);
        return cur;
    }
    inline void copy(int cur,int old){
        lc[cur]=lc[old];
        rc[cur]=rc[old];
        cnt[cur]=cnt[old];
    }
    int update(int old,int l,int r,int k,int v){
        int cur=++tot;
        copy(cur,old);
        cnt[cur]+=v;
        if(l==r) return cur;
        int mid=l+r>>1;
        if(k<=mid) lc[cur]=update(lc[old],l,mid,k,v);
        else rc[cur]=update(rc[old],mid+1,r,k,v);
        return cur;
    }
    int query(int T1,int T2,int T3,int T4,int l,int r,int k){
        while(1){
            if(l==r) return l;
            int t=cnt[lc[T1]]+cnt[lc[T2]]-cnt[lc[T3]]-cnt[lc[T4]];
            if(k<=t){
                T1=lc[T1];
                T2=lc[T2];
                T3=lc[T3];
                T4=lc[T4];
                r=l+r>>1;
            }else{
                k-=t;
                T1=rc[T1];
                T2=rc[T2];
                T3=rc[T3];
                T4=rc[T4];
                l=l+r>>1;l++;
            }
        }
    }
}fst;
void fstbuild(int u,int fa){
    if(u==1) fst.T[u]=fst.update(fst.T[0],1,nn,c[1],1);
    else fst.T[u]=fst.update(fst.T[fa],1,nn,c[u],1);
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        fstbuild(v,u);
    }
}
int main(){
    while(cin>>n>>m){
        init(); mp.clear();
        rep(i,1,n) b[i]=a[i]=read();
        sort(b+1,b+1+n);
        nn=unique(b+1,b+1+n)-b-1;
        rep(i,1,n) c[i]=lower_bound(b+1,b+1+nn,a[i])-b;
        //rep(i,1,n) mp[c[i]]=a[i];
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);
            add(v,u);
        }
        dfs(1,-1,1);
        fst.init(); fst.T[0]=fst.build(1,nn);
        //rep(i,1,n) fst.T[i]=fst.update(fst.T[i-1],1,CLOCK,a[pre[i]],1);
        //fst.T[1]=fst.update(fst.T[0],1,nn,c[1],1);
        //rep(i,2,n) fst.T[i]=fst.update(fst.T[p[i][0]],1,nn,c[i],1);
        fstbuild(1,-1);
        rep(i,1,m){
            int u=read();
            int v=read();
            int k=read();
            int anc=lca(u,v);
            //if(dfn[u]>dfn[v]) swap(u,v);
            //println(fst.query(fst.T[dfn[u]],fst.T[dfn[v]],fst.T 1,CLOCK,k));
            println(b[fst.query(fst.T[u],fst.T[v],fst.T[anc],fst.T[p[anc][0]==anc?0:p[anc][0]],1,nn,k)]);
        }
    }
    return 0;
}