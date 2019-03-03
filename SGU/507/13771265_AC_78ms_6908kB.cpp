#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 5e4+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
set<ll> s[MAXN];
ll n,m,val[MAXN];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
ll merge(set<ll> &a,set<ll> &b){
    if(a.size()<b.size()) swap(a,b);
    set<ll>::iterator it,lb,ub;
    ll mn=INF;
    for(it=b.begin();it!=b.end();it++){
        lb=ub=a.lower_bound(*it);
        if(lb!=a.begin()/*&&lb!=a.end()*/)lb--; //多了会WA
        if(lb!=a.end()) mn=min(mn,abs((*it)-(*lb)));
        if(ub!=a.end()) mn=min(mn,abs((*it)-(*ub)));
        a.insert(*it);//
    }
    b.clear();
    return mn;
}
#define isleaf(x) (bool((x)>=n-m+1&&(x)<=n))
void dfs(int u,int p){
    if(isleaf(u)){
        s[u].insert(val[u]);
        val[u]=INF;//trick
        return;
    }
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        dfs(v,u);
        val[u]=min(val[u],val[v]);
        val[u]=min(val[u],merge(s[u],s[v]));
    }
}
int main(){
    while(cin>>n>>m){
        init();
        rep(i,1,n) val[i]=INF;
        rep(i,1,n) s[i].clear();
        rep(i,2,n) add(read(),i);
        rep(i,n-m+1,n) val[i]=read();
        dfs(1,-1);
        rep(i,1,n-m){
            if(i==n-m) println(val[i]);
            else printbk(val[i]);
        }
    }
    return 0;
}
