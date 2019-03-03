#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1e3,INF = 0x3f3f3f3f;
struct edge{
	int to,cost;
}; 
vector<edge> G[maxn];
int d[maxn],vis[maxn],cnt[maxn],pre[maxn];
int n,m,from,to,cost,lll,mmax,last,w;
bool spfa(int s){
	queue<int> q;
	memset(d,INF,sizeof d);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	d[s]=0; q.push(s);
	vis[s]=1;
	while(!q.empty()){
		mmax = 0;
		int u = q.front(); q.pop();
		if(mmax<d[u]) mmax = d[u],last = u;
		for(int i = 0; i < G[u].size(); i++){
			edge e = G[u][i];
			if(d[e.to]>d[u]+e.cost){
				pre[e.to] = u;
				d[e.to] = d[u]+e.cost;
				if(!vis[e.to]){
					q.push(e.to);
					vis[e.to]=1;
					cnt[e.to]++;
				}
			}
			if(cnt[e.to]>=n) return 1;
		}
		vis[u] = 0;
	}
	return 0;
}
void print(int u){
	if(d[u]!=0)
		print(pre[u]);
	
	cout<<pre[u]<<" ";
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof G);
		scanf("%d%d%d",&n,&m,&w);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,cost});
			G[to].push_back((edge){from,cost});
		}
		for(int i = 0; i < w; i++){
			scanf("%d%d%d",&from,&to,&cost);
			G[from].push_back((edge){to,-cost});
		}
		bool flag = spfa(1);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}