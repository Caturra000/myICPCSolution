#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 4e4+100;
const int INF = 0x3f3f3f3f;
struct edge{
	int to,cost;
}; 
int T,N,from,to,cost; 
int n,m;
typedef pair<int,int> P;
vector<edge> G[maxn];
int d[maxn];
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
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
	int T; scanf("%d",&T); 
	while(T--){
		memset(G,0,sizeof G);
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,cost});
			G[to].push_back((edge){from,cost});
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d",&from,&to);
//			cout<<"ok";
			dijkstra(from);
			printf("%d\n",d[to]);
		}
	}
	return 0;
}