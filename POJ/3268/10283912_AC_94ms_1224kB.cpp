#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e4;
const int INF = 0x3f3f3f3f;
struct edge{
	int to,cost;
}; 
int T,N,from,n,m,to,cost,x,ans; 
typedef pair<int,int> P;//d id
vector<edge> G[maxn],G2[maxn];
int d[maxn],d2[maxn],cf[maxn];//come from
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que; //权相等时用queue 
	memset(d,INF,sizeof d); d[s] = 0;
	que.push(P(0,s));  
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v]<p.first) continue;
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			} 
		}
	}
} 
void dijkstra2(int s){
	priority_queue<P,vector<P>,greater<P> > que; //权相等时用queue 
	memset(d2,INF,sizeof d2); d2[s] = 0;
	que.push(P(0,s));  
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d2[v]<p.first) continue;
		for(int i = 0; i < G2[v].size(); i++){
			edge e = G2[v][i];
			if(d2[e.to]>d2[v]+e.cost){
				d2[e.to]=d2[v]+e.cost;
				que.push(P(d2[e.to],e.to));
			} 
		}
	}
} 

int main(){
	while(scanf("%d%d%d",&n,&m,&x)!=EOF){
		memset(G,0,sizeof G);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,cost});
			G2[to].push_back((edge){from,cost});
			//cf[i] = i;
		}
		dijkstra(x);//back
		dijkstra2(x);//to
		ans = 0;
		for(int i = 1;i <= m; i++){
			if(d[i]+d2[i]<INF)
				ans = max(ans,d[i]+d2[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}