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
int T,N,from,to,cost; 
typedef pair<int,int> P;//d id
vector<edge> G[maxn];
int d[maxn];
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

int main(){
	while(scanf("%d%d",&T,&N)!=EOF){
		memset(G,0,sizeof G);
		for(int i = 0; i < T; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,cost});
			G[to].push_back((edge){from,cost});
		}
		dijkstra(1);
//		int ans = INF;
//		for(int i = 2; i <= N; i++){
//			ans = min(ans,d[i]);
//		}
		printf("%d\n",d[N]);
	}
	return 0;
}