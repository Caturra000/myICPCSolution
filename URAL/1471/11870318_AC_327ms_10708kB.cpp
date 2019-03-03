#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define clr(a,b) memset(a,b,sizeof a);
using namespace std;
const int maxn = 1e5+11;
int to[maxn<<2],nxt[maxn<<2],cost[maxn<<2];
int head[maxn],tot;
int fa[maxn][20],dep[maxn];
void init(){
    memset(head,-1,sizeof head);
    memset(fa,0,sizeof fa);
    tot=0;
}
void add(int u,int v,int w){
    to[tot]=v;cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int dis[maxn];
void bfs(int root){
	queue<int> que;
	memset(dis,0,sizeof dis);
	memset(fa,0,sizeof fa);
	memset(dep,0,sizeof dep);
	fa[root][0]=root;dep[root]=0;dis[root]=0;
	que.push(root);
	while(!que.empty()){
		int u = que.front(); que.pop();
		for(int i = 1; i < 20; i++) fa[u][i]=fa[fa[u][i-1]][i-1];
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(v==fa[u][0])continue;
			dep[v]=dep[u]+1;dis[v]=dis[u]+w;fa[v][0]=u;
			que.push(v);
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i = 0; i < 20; i++) if((dep[u]-dep[v])&(1<<i)) u=fa[u][i];
	if(u==v)return u;
	for(int i = 19; i >= 0; i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main(){
    int n,m,u,v,w,x;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i = 1; i <= n-1; i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }
        bfs(1);
        scanf("%d",&m);
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&u,&v);
            x=lca(u,v);
            printf("%d\n",dis[u]+dis[v]-2*dis[x]);
        }
    }
    return 0;
}
