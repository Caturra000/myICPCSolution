#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1011;
int T,N,from,to,ans,n,m; 
double cost;
typedef pair<double,int> P;//d id
double G[maxn][maxn];
double save[maxn][maxn]; 
double d[maxn];
void dijkstra(int s){
	priority_queue<P> que; 
	memset(d,0,sizeof d); d[s] = 1;
	que.push(P(1.0,s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v]>p.first) continue; 
		for(int i = 1; i <= n; i++){
			if(i==v) continue;
			if(d[i]<d[v]*G[v][i]){
				d[i]=d[v]*G[v][i];
				que.push(P(d[i],i));
			} 
		}
	}
} 
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(G,0,sizeof G);
		memset(save,0,sizeof save);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				scanf("%lf",&cost);
				G[i][j]=cost;
			}
		}
		for(int i = 1; i <= n; i++){
			dijkstra(i);
			for(int j = 1; j <= n; j++){
				if(i==j) save[i][j]=G[i][j];
				else{
					save[i][j]=d[j];
				}	
			}
		}
		scanf("%d",&m);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&from,&to);
			if(save[from][to]!=0) printf("%.3lf\n",save[from][to]);
			else printf("What a pity!\n");
		}
	}
	return 0;
}

