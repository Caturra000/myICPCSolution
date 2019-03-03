#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+11;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
struct Edge{
    int to,cost;
};
struct Grpah{
    int head[maxn];
    int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],tot;
    vector<Edge> edge[maxn]; 
    void init(){
        memset(edge,0,sizeof edge);
    }
    void add(int from,int to,int cost){
        edge[from].push_back((Edge){to,cost});
    }
    int d[maxn];
    void dijkstra(int s){
        priority_queue<P,vector<P>,greater<P> > pq;
        memset(d,oo,sizeof d);d[s]=0;
        pq.push(P(0,s));
        while(!pq.empty()){
            P p = pq.top();pq.pop();
            int u = p.second;
            if(d[u]<p.first) continue;
            for(int i=0; i<edge[u].size(); i++){
                int v=edge[u][i].to,w=edge[u][i].cost;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    pq.push(P(d[v],v));
                }
            }
        }
    }
}G;
int dp[maxn];
int dfs(int cur){
    if(cur==2)return 1;
    if(dp[cur]>0) return dp[cur];
    int ans=0;
    for(int i=0; i<G.edge[cur].size(); i++){
        int to=G.edge[cur][i].to;
        if(G.d[cur]>G.d[to]) ans+=dfs(to);
    }
    return dp[cur]=ans;
}
int n,m,from,to,cost;
int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        scanf("%d",&m);
        G.init();memset(dp,0,sizeof dp);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&from,&to,&cost);
            G.add(from,to,cost);
            G.add(to,from,cost);
        }
        G.dijkstra(2);
        printf("%d\n",dfs(1));
    }
    return 0;
}