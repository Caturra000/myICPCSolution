#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 2e3+11;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
struct Grpah{
    int head[maxn];
    int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],tot;
    void init(){
        memset(head,-1,sizeof head);
        tot=0;
    }
    void add(int u,int v,int w){
        to[tot]=v;cost[tot]=w;
        nxt[tot]=head[u];
        head[u]=tot;
        tot++;
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
            for(int i=head[u]; ~i; i=nxt[i]){
                int v=to[i],w=cost[i];
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    pq.push(P(d[v],v));
                }
            }
        }
    }
}G;
int T,N,from,to,cost;
int main(){
    while(scanf("%d%d",&T,&N)!=EOF){
        G.init();
        for(int i = 0; i < T; i++){
            scanf("%d%d%d",&from,&to,&cost);
            G.add(from,to,cost);
            G.add(to,from,cost);
        }
        G.dijkstra(1);
        printf("%d\n",G.d[N]);
    }
    return 0;
}