#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e6+11;
const int MOD = 10007;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int from[MAXN<<1],to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],head[MAXN],tot;
int dfn[MAXN],dfned[MAXN],pre[MAXN],CLOCK,dep[MAXN],e[MAXN],val[MAXN];
map<string,int> mp;
typedef pair<int,int> P;
vector<P> vec;
void init(){
    memset(head,-1,sizeof head);
    tot=CLOCK=0;
}
void add(int u,int v,int w){
    from[tot]=u;
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    from[tot]=u;
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
void dfs(int u,int fa,int t,int d){
    dfn[u]=++CLOCK;pre[CLOCK]=u;dep[u]=d;
    val[u]=t;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i],w=cost[i];
        if(v==fa) continue;
        dfs(v,u,val[u]^w,d+1);
    }
    dfned[u]=CLOCK;
}
struct ST{
    int even[MAXN<<2],odd[MAXN<<2];
    int lazy[MAXN<<2];
    #define lc o<<1
    #define rc o<<1|1
    void pu(int o){
        even[o]=even[lc]+even[rc];
        odd[o]=odd[lc]+odd[rc];
    }
    void build(int o,int l,int r){
        lazy[o]=0;
        if(l==r){
            even[o]=odd[o]=0;
            if(val[pre[l]]==1) odd[o]++;
            else even[o]++;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    void pd(int o){
        if(lazy[o]){
            swap(even[lc],odd[lc]);
            swap(even[rc],odd[rc]);
            lazy[lc]^=1;
            lazy[rc]^=1;
            lazy[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            swap(even[o],odd[o]);
            lazy[o]^=1;
            return;
        }
        int mid=l+r>>1;
        pd(o);
        if(L<=mid) update(lc,l,mid,L,R);
        if(R>mid) update(rc,mid+1,r,L,R);
        pu(o);
    }
}st;
int main(){
    int kase=0,T=read();
    while(T--){
        int n=read();
        int id=0;mp.clear();
        init();vec.clear();
        rep(i,1,n){
            string str;
            cin>>str;
            mp[str]=++id;
        }
        string s1,s2;
        rep(i,1,n-1){
            cin>>s1>>s2;
            int v=read();
            add(mp[s1],mp[s2],v);
            vec.push_back(P(mp[s1],mp[s2]));
        }
        dfs(1,-1,0,1);
        for(int i=0;i<vec.size();i++){
            int u=vec[i].first,v=vec[i].second;
            if(dep[u]<dep[v]) swap(u,v);
            e[i+1]=u;
        }
        int m=read();
        char op[34];
        st.build(1,1,CLOCK);
        printf("Case #%d:\n",++kase);
        while(m--){
            scanf("%s",op+1);
            if(op[1]=='Q'){
                ll x=st.even[1],y=st.odd[1];
                println(x*y<<1);
            }else{
                int t=read();
                st.update(1,1,CLOCK,dfn[e[t]],dfned[e[t]]);
            }
        }
    }
    return 0;
}