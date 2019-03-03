#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+22;
typedef long long ll;
typedef pair<ll,int> P; 

int head[maxn];
int to[maxn<<1],nxt[maxn<<1],tot;
ll cost[maxn<<1];
const ll oo = 1ll<<61;

void add(int u,int v,int w){
    to[tot]=v;cost[tot]=w;
    nxt[tot]=head[u];head[u]=tot++;
}
bool belong[105][maxn];//belong[i][j]=1 j边是第i个最短路树之中的边
ll d[105][105];
int last[105];
int n,m,u,v,w,l; 
bool dele[maxn];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > pq;
    memset(belong[s],0,sizeof belong[s]);
    memset(last,-1,sizeof last); 
    for(int i = 1; i <= n; i++) d[s][i]=oo;
    d[s][s]=0;
    pq.push(P(0,s));
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int u=p.second;
        if(d[s][u]<p.first)continue;
        for(int i = head[u]; ~i; i=nxt[i]){
        	
            int v=to[i],w=cost[i];
            if(d[s][u]+w<d[s][v]){
                d[s][v]=d[s][u]+w;
                if(~last[v]) belong[s][last[v]]=0; 
                belong[s][i]=1;last[v]=i;
                pq.push(P(d[s][v],v));
            }
        }
    }
}
ll dijkstra2(int s){
    priority_queue<P,vector<P>,greater<P> > pq;
    for(int i = 1; i <= n; i++) d[s][i]=oo;
    d[s][s]=0;
    pq.push(P(0,s));
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int u=p.second;
        if(d[s][u]<p.first)continue;
        for(int i = head[u]; ~i; i=nxt[i]){
        	if(dele[i])continue;
            int v=to[i],w=cost[i];
            if(d[s][u]+w<d[s][v]){
                d[s][v]=d[s][u]+w;
                // belong[s][i]=1;
                pq.push(P(d[s][v],v));
            }
        }
    }
    ll sum=0;
    for(int i = 1; i <= n; i++) sum+=d[s][i]==oo?l:d[s][i];
    return sum;
}
ll ts[105];
void init(){
    memset(head,-1,sizeof head); tot=0;
    memset(belong,0,sizeof belong);
    memset(ts,0,sizeof ts);
}
int main(){
    while(scanf("%d%d%d",&n,&m,&l)!=EOF){
        init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }
        ll sum=0;
        for(int i = 1; i <= n; i++){
            dijkstra(i);
            for(int j = 1; j <= n; j++){
                ts[i]+=d[i][j]==oo?l:d[i][j];
            }
            sum+=ts[i];
        }
        ll tsum=0;
        for(int i = 0; i < 2*m; i+=2){
        	dele[i]=dele[i+1]=1;
            ll tmp=cost[i],tcnt=0;
            for(int j = 1; j <= n; j++){
                if(!belong[j][i]&&!belong[j][i+1]) tcnt+=ts[j];
                else tcnt+=dijkstra2(j);
            }
            tsum=max(tsum,tcnt);
            dele[i]=dele[i+1]=0;
        }
        printf("%lld %lld\n",sum,tsum);
    }
    return 0;
}