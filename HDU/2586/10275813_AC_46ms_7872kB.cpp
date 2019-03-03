#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn = 40100;
int p[maxn],dis[maxn],ans[maxn],cnt,n,m,from,to,cost;
int *mp1,*mp2;
bool vis[maxn],in[maxn];
struct node1{
	int to,w;
	int next;
}edge[maxn<<1]; int head[maxn],tot;
struct node2{
	int to,next;
	int num;
}que[maxn<<1]; int h[maxn],tt;
void adde(int u,int v,int w){//单向 
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void addq(int u,int v,int num){//双向 
	que[tt].to = v;
	que[tt].num = num;
	que[tt].next = h[u];
	h[u] = tt++;
	que[tt].to = u;
	que[tt].num = num;
	que[tt].next = h[v];
	h[v] = tt++;
}
int find(int x){
	return p[x]==-1?x:p[x]=find(p[x]);
}
void link(int a,int b){
	a=find(a);b=find(b);
	if(a!=b) p[b]=a;
}
void lca(int u){
	for(int i = head[u]; i!=-1; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v]) continue;
		dis[v]=dis[u]+edge[i].w;
		lca(v);
		link(u,v);
	}
	vis[u]=1;
	for(int i = h[u]; i!=-1; i = que[i].next){
		int v = que[i].to;
		if(vis[v]){
			ans[que[i].num] = dis[u]+dis[v]-2*dis[find(v)];
		}
	}
}
inline void init(){
	memset(p,-1,sizeof p);
	memset(dis,0,sizeof dis);
	//memset(ans,0,sizeof ans);//
	memset(vis,0,sizeof vis);
	memset(in,0,sizeof in);
	//memset(edge,0,sizeof edge);
	memset(h,-1,sizeof h);//
	memset(head,-1,sizeof head);//
	//memset(que,0,sizeof h);
	tot=0;tt=0;cnt=0;
} 
int main(){
	int T;scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d",&from,&to,&cost);
			adde(from,to,cost);
			in[to]++;
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d",&from,&to);
			addq(from,to,i);
		}
		for(int i = 1; i <= n; i++){
			if(in[i]==0){
				lca(i);
				break;
			}
		}
		for(int i = 0; i < m; i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}