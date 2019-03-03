#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3+11;
int head[maxn],to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],tot;
int n,m,mx,u,v,w;
int vis[maxn],d[maxn];
void init(){
	memset(head,-1,sizeof head);
	tot=0;
	mx=0;
}
void add(int u,int v,int w){
	to[tot]=v;cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot++;
}
bool cycle(int u,int x){
	vis[u]=1;
	for(int i = head[u]; ~i; i = nxt[i]){
		int v=to[i],w=cost[i];
		if(d[v]<d[u]+x-w){//<?
			d[v]=d[u]+x-w;
			if(vis[v]||cycle(v,x)) return 1;
		}
	}
	vis[u]=0;
	return 0;
}
bool check(int x){
	memset(vis,0,sizeof vis);
	memset(d,0,sizeof d);
	for(int i = 1; i <= n; i++) if(cycle(i,x)) return 0;
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			mx=max(mx,w); 
		}
		if(!check(1)){
			printf("No Solution\n");
			continue;
		}
		if(check(mx+1)){
			printf("Infinite\n");
			continue;
		}
		int l=1,r=mx,mid;
		while(l<r){
			mid=l+(r-l+1)/2;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}