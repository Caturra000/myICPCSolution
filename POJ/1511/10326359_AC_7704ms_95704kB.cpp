#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1000110,INF = 0x3f3f3f3f;
struct edge{
	int to,cost;
};
//vector<edge> E;
vector<edge> G[maxn],G2[maxn];
int d[maxn],cnt[maxn];
bool vis[maxn];
int n,m,from,to,cost;
bool SPFA(int s){
	memset(d,INF,sizeof d);memset(vis,0,sizeof vis);memset(cnt,0,sizeof cnt);
	d[s]=0; vis[s]=1;cnt[s]++;//是否在队列 
	stack<int> q; q.push(s);
	while(!q.empty()){
		int u = q.top(); q.pop();
		for(int i = 0; i < G[u].size(); i++){
			edge e = G[u][i];
			if(d[e.to] > d[u]+e.cost){
				d[e.to] = d[u]+e.cost;
				if(!vis[e.to]){
					q.push(e.to);
					vis[e.to]=1; cnt[e.to]++;
				}
			}
			if(cnt[e.to]>=n) return false;
		}
		vis[u]=0;
	}
	return true;
}
bool SPFA2(int s){
	memset(d,INF,sizeof d);memset(vis,0,sizeof vis);memset(cnt,0,sizeof cnt);
	d[s]=0; vis[s]=1;cnt[s]++;//是否在队列 
	stack<int> q; q.push(s);
	while(!q.empty()){
		int u = q.top(); q.pop();
		for(int i = 0; i < G2[u].size(); i++){
			edge e = G2[u][i];
			if(d[e.to] > d[u]+e.cost){
				d[e.to] = d[u]+e.cost;
				if(!vis[e.to]){
					q.push(e.to);
					vis[e.to]=1; cnt[e.to]++;
				}
			}
			if(cnt[e.to]>=n) return false;
		}
		vis[u]=0;
	}
	return true;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof G);memset(G2,0,sizeof G2);
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,cost});
			G2[to].push_back((edge){from,cost});
		}
		long long ans = 0;
		SPFA(1); for(int i = 2; i <= n; i++) ans+=d[i];
		SPFA2(1); for(int i = 2; i <= n; i++) ans+=d[i];
		printf("%lld\n",ans);
	}
	return 0;
}