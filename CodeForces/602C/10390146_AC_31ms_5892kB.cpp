#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> P;
const int maxn = 444,INF=0x3f3f3f3f,INF2=1060000000;
struct edge{
	int to,cost; 
};
vector<edge> G[maxn],G2[maxn];
int d[maxn],d2[maxn];
int map[maxn][maxn];
int n,m,from,to;
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > q; q.push(P(0,s));
	memset(d,0x3f3f3f3f,sizeof d); d[s]=0;
	while(!q.empty()){
		P p = q.top(); q.pop();
		int v = p.second; 
		if(d[v]<p.first) continue;
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	} 
}
void dijkstra2(int s){
	priority_queue<P,vector<P>,greater<P> > q; q.push(P(0,s));
	memset(d2,0x3f3f3f3f,sizeof d2); d2[s]=0;
	while(!q.empty()){
		P p = q.top(); q.pop();
		int v = p.second; 
		if(d2[v]<p.first) continue;
		for(int i = 0; i < G2[v].size(); i++){
			edge e = G2[v][i];
			if(d2[e.to]>d2[v]+e.cost){
				d2[e.to]=d2[v]+e.cost;
				q.push(P(d2[e.to],e.to));
			}
		}
	} 
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(G,0,sizeof G);memset(G2,0,sizeof G2);memset(map,0,sizeof map);
		for(int i = 0; i < m; i++){
			scanf("%d%d",&from,&to);
			map[from][to]=1;map[to][from]=1;
			G[from].push_back((edge){to,1});
			G[to].push_back((edge){from,1});
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(map[i][j]==0){
					G2[i].push_back((edge){j,1});
					G2[j].push_back((edge){i,1});
					map[i][j]=1;map[j][i]=1;
				}
			}
		}
		dijkstra(1);dijkstra2(1);
		if(d[n]>=INF||d2[n]>=INF) printf("-1\n");
		else printf("%d\n",max(d[n],d2[n]));
		
	}
	return 0;
} 