#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 3e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN<<1],tot;
int p[MAXN][21],dep[MAXN],dis[MAXN],d[MAXN];
bool vis[MAXN];
vector<int> block;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
void dfs(int u,int fa,int d){
    dep[u]=d;
    rep(j,0,20){
        if(u==1) p[u][j]=u;
        else if(j>0) p[u][j]=p[p[u][j-1]][j-1];
        else p[u][j]=fa;
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
void bfs(){
    queue<int> que;
    for(int i=0;i<block.size();i++){
        que.push(block[i]);
        dis[block[i]]=0;
        vis[block[i]]=1;
    }
    while(que.empty()^1){
        int u=que.front();
        que.pop(); vis[u]=0;
        erep(i,u){
            int v=to[i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                if(!vis[v]) que.push(v),vis[v]=1;
            }
        }
    }
}
int main(){
    while(cin>>n>>m){
        init();
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);
            add(v,u);
        }
        block.clear();
        block.push_back(1);
        dfs(1,-1,1);
        memset(dis,0x3f,sizeof dis);
        int SQRT=sqrt(m+1);
        //bfs();
        while(m--){
            int op=read();
            int u=read();
            if(op==1){
                block.push_back(u);
                if(block.size()==SQRT){
                    bfs();
                    block.clear();
                }
            }else{
                int res=dis[u];
                for(int i=0;i<block.size();i++){
                    int v=block[i];
                    res=min(res,dep[u]+dep[v]-2*dep[lca(u,v)]);
                }
                println(res);
            }
        }
    }
    return 0;
}