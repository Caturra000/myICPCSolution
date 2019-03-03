#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define clr(a) memset((a),0,sizeof (a))
using namespace std;
const int maxn = 1e4+8;
int p[maxn],a[maxn],r[maxn],id[maxn];
bool vis[maxn];
vector<int> G[maxn];
vector<int> Q[maxn];
int n,from,to,ans;
void init(){
	clr(G);clr(Q);clr(p);clr(r);clr(vis);clr(a);clr(id);
}
int find(int x){
	return p[x]?p[x]=find(p[x]):x;
}
void link(int a,int b){
	a=find(a);b=find(b);
	if(a==b) return ;
	if(r[a]<r[b]){
		p[a]=b;
		r[b]+=r[a];
	}
	else{
		p[b]=a;
		r[a]+=r[b];
	}
}
void lca(int u){
	a[u]=u;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		//if(vis[v]) continue;
		lca(v);
		a[v]=u;
		link(u,v);
		//a[find(u)]=u;
	}
	vis[u]=1;
	for(int i = 0; i < Q[u].size(); i++){
		int v = Q[u][i];
		if(vis[v]){
			ans = a[find(v)];
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i = 0; i < n-1; i++){
			scanf("%d%d",&from,&to);
			G[from].push_back(to);
			id[to]++;
		}
		scanf("%d%d",&from,&to);
		Q[from].push_back(to);
		Q[to].push_back(from);
		for(int i = 1; i <= n; i++) if(id[i]==0){
			lca(i);break;
		}
		printf("%d\n",ans);
	}
	return 0;
}