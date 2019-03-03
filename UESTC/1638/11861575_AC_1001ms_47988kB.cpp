#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
int head[maxn],hhead[maxn],tot,ttot;
int to[maxn<<1],tto[maxn<<1],nxt[maxn<<1],nnxt[maxn<<1],cost[maxn<<1],ccost[maxn<<1];
int n,m;
void init(){
	memset(head,-1,sizeof head);
	memset(hhead,-1,sizeof hhead);
	tot=ttot=0;
}
void add(int u,int v,int w){
	to[tot]=v;cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot++;
}
void aadd(int u,int v,int w){
	tto[ttot]=v;ccost[ttot]=w;
	nnxt[ttot]=hhead[u];
	hhead[u]=ttot++;
}
int dis[maxn],cnt[maxn];
bool inq[maxn];
bool spfa(int s){
	memset(dis,-1,sizeof dis);
	memset(inq,0,sizeof inq);
	memset(cnt,0,sizeof cnt);
	stack<int> que;que.push(s);
	dis[s]=0;inq[s]=1;cnt[s]++;
	while(!que.empty()){
		int u = que.top(); que.pop(); inq[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;//cout<<dis[v];
				if(!inq[v]){
					inq[v]=1;cnt[v]++;
					que.push(v);
				}
			}
			if(cnt[v]>n+3)return 0;
		}
	}
	for(int i = 1; i <= n; i++) if(dis[i]<0||dis[i]>100) return 0;
	return 1;
}
int ddis[maxn];
bool sspfa(int s){
	memset(ddis,0x3f,sizeof ddis);
	memset(inq,0,sizeof inq);
	memset(cnt,0,sizeof cnt);
	stack<int> que;que.push(s);
	ddis[s]=100;inq[s]=1;cnt[s]++;
	while(!que.empty()){
		int u = que.top(); que.pop(); inq[u]=0;
		for(int i = hhead[u]; ~i; i = nnxt[i]){
			int v=tto[i],w=ccost[i];
			if(ddis[v]>ddis[u]+w){
				ddis[v]=ddis[u]+w;
				if(!inq[v]){
					inq[v]=1;cnt[v]++;
					que.push(v);
				}
			}
			if(cnt[v]>n+3)return 0;
		}
	}
	for(int i = 1; i <= n; i++) if(ddis[i]<0||ddis[i]>100) return 0;
	return 1;
}
int main(){
	int u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i = 1; i <= m; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,w);
			aadd(u,v,-w);
		}
		for(int i = 1; i <= n; i++){
			add(n+1,i,0);aadd(n+1,i,0);
		}
		bool flag1=spfa(n+1);
		bool flag2=sspfa(n+1);
		if(!flag1||!flag2){printf("-1\n");continue;}
		for(int i = 1; i <= n; i++){
			printf("%d %d\n",dis[i],ddis[i]);
		}
	}
	return 0;
}
