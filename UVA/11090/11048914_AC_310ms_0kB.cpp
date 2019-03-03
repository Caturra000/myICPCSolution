#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int head[maxn],tot,to[maxn<<1],nxt[maxn<<1];
bool vis[maxn];
double d[maxn],cost[maxn<<1];
int n,m,u,v;
double w;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int u,int v,double w){
	to[tot]=v;cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot++;
}
bool cycle(int u){
	vis[u]=1;
	for(int i = head[u]; ~i; i = nxt[i]){
		int v = to[i]; double w = cost[i];
		if(d[v]>d[u]+w){
			d[v]=d[u]+w;
			if(vis[v]||cycle(v)){
				vis[v]=0;return 1;
			}
		}
	}
	vis[u]=0;
	return 0;
} 
bool check(double x){
	bool flag=0;
	memset(d,0,sizeof d);
	memset(vis,0,sizeof vis);
	for(int i = 0; i < tot; i++) cost[i]-=x;
	for(int i = 1; i <= n; i++) if(cycle(i)) {flag=1;break;};
	for(int i = 0; i < tot; i++) cost[i]+=x;
	return flag; 
}
int main(){
	int T,kase=0; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);init();
		for(int i = 0; i < m; i++){
			scanf("%d%d",&u,&v);scanf("%lf",&w);
			add(u,v,w);
		}
		printf("Case #%d: ",++kase);
		if(!check(1e7)){
			printf("No cycle found.\n");
			continue;
		}
		double l=0,r=1e12,mid;
		for(int i = 0; i < 100; i++){
			mid=(l+r)/2.0;
			if(check(mid)) r=mid;
			else l=mid;
		}
		printf("%.2lf\n",l);
	}
	return 0;
}