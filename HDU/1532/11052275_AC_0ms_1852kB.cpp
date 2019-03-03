#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
const int oo = 1<<30;
struct Edge{
	int to,cap,rev;
};
int d[maxn],n,m;
vector<Edge> G[maxn];
void add(int u,int v,int w){
	G[u].push_back((Edge){v,w,G[v].size()});
	G[v].push_back((Edge){u,0,G[u].size()-1});
}
bool bfs(int s,int t){
	queue<int> q;
	while(!q.empty())q.pop();
	memset(d,-1,sizeof d);
	d[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].to;
			if(G[u][i].cap>0&&d[v]==-1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[t]!=-1;
}
int dfs(int u,int t,int micap){
	if(u==t)return micap;
	int tmp;
	for(int i = 0; i < G[u].size(); i++){
		Edge &e=G[u][i];
		if(e.cap>0&&d[u]+1==d[e.to]&&(tmp=dfs(e.to,t,min(e.cap,micap)))){
			e.cap-=tmp;
			G[e.to][e.rev].cap+=tmp;
			return tmp;
		}
	}
	return 0;
}
int dinic(int s,int t){
	int ans=0,tmp;
	while(bfs(s,t)){
		while(1){
			tmp=dfs(s,t,oo);
			if(tmp==0)break;
			ans+=tmp;
		}
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(G,0,sizeof G);
		int u,v,w;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		printf("%d\n",dinic(1,m));
	}
	return 0;
}