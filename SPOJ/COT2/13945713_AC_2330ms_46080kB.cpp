#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
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
int color[MAXN],belong[MAXN],depth[MAXN],dfn[MAXN];
int stk[MAXN],bit[32],limit,root,cnt,CLOCK,top;
int anc[MAXN][20];
map<int,int> haxi; 
bool vis[MAXN];
int ANS,cntNum[MAXN],ans[MAXN];
struct QQQ{
    int u,v,a,b,id;
    bool operator < (const QQQ &rhs) const{
        if(belong[u]!=belong[rhs.u]){
            return belong[u]<belong[rhs.u];
        }else{
            return dfn[v]<dfn[rhs.v];
        }
    }
}Q[MAXN];

int dfs(int u,int fa,int d){
    dfn[u]=++CLOCK;
    anc[u][0]=fa; depth[u]=d;
    rep(i,1,16){
        if(depth[u]<bit[i]) break;
        anc[u][i]=anc[anc[u][i-1]][i-1];
    }
    int num=0;
    erep(i,u){
        int v=to[i];
        if(v==fa) continue;
        num+=dfs(v,u,d+1);
        if(num>=limit){
            ++cnt;
            rep(i,1,num) belong[stk[top--]]=cnt;
            num=0;
        }
    }
    stk[++top]=u; num++;
    return num;
}
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int d=depth[u]-depth[v];
    for(int i=0;bit[i]<=d;i++){
        if(d>>i&1) u=anc[u][i];
    }
    for(int i=16;i>=0;i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    if(u==v) return u;
    else return anc[u][0];
}
void rev(int u){
    if(!vis[u]){
        vis[u]=1;
        if(cntNum[color[u]]==0) ANS++;
        cntNum[color[u]]++;
    }else{
        vis[u]=0;
        if(cntNum[color[u]]==1) ANS--;
        cntNum[color[u]]--;
    }
}
void viss(int u,int v){
    while(u!=v){
        if(depth[u]>depth[v]) rev(u),u=anc[u][0];
        else rev(v),v=anc[v][0];
    }
}
int main(){
    int n,m;
    bit[0]=1;rep(i,1,30) bit[i]=bit[i-1]<<1;
    while(cin>>n>>m){
        init(); limit=sqrt(n)+1;
        haxi.clear(); int haxiid=0;
        rep(i,1,n){
            int t=read();
            if(haxi[t]==0) haxi[t]=++haxiid;
            color[i]=haxi[t];
		}
        rep(i,1,n-1){
            int u=read();
            int v=read();
            // if(u*v==0) root=u|v;
            // else 
            add(u,v),add(v,u);
        }
        root=1;
        top=cnt=CLOCK=0;
        memset(anc,0,sizeof anc);
        dfs(root,0,1);
        if(top){
            cnt++;
            while(top) belong[stk[top--]]=cnt;
        }
        rep(i,1,m){
            Q[i].u=read();
            Q[i].v=read();
            // Q[i].a=read();
            // Q[i].b=read();
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m); ANS=0;
        int t=lca(Q[1].u,Q[1].v);
        memset(vis,0,sizeof vis);
        viss(Q[1].u,Q[1].v);
        rev(lca(Q[1].u,Q[1].v));
        ans[Q[1].id]=ANS;
        rev(lca(Q[1].u,Q[1].v));
        // if(cntNum[Q[1].a]&&cntNum[Q[1].b]&&Q[1].a!=Q[1].b){
        //     ans[Q[1].id]--;
        // }
        rep(i,2,m){
            viss(Q[i-1].u,Q[i].u);
            viss(Q[i-1].v,Q[i].v);
            rev(lca(Q[i].u,Q[i].v));
            ans[Q[i].id]=ANS;
            // if(cntNum[Q[i].a]&&cntNum[Q[i].b]&&Q[i].a!=Q[i].b){
            //     ans[Q[i].id]--;
            // }
            rev(lca(Q[i].u,Q[i].v));
        }
        rep(i,1,m) println(ans[i]);
    }
    return 0;
}