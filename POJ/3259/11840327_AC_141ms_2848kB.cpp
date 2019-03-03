#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1e5+11,INF = 0x3f3f3f3f;

int head[maxn],tot;
int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,int w){
    to[tot]=v;cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int d[maxn],vis[maxn],cnt[maxn],pre[maxn];
int n,m,lll,mmax,last,w;
struct QUEUE{
    int que[maxn<<1];
    int frontt,rear;
    void init(){frontt=rear=0;}
    void push(int x){que[rear++]=x;}
    int front(){return que[frontt];}
    void pop(){frontt++;}
    bool empty(){return rear==frontt;}
}q;
bool spfa(int s){
	q.init();
	memset(d,INF,sizeof d);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	d[s]=0; q.push(s);
	vis[s]=1;
	while(!q.empty()){
		mmax = 0;
		int u = q.front(); q.pop();
		if(mmax<d[u]) mmax = d[u],last = u;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(d[v]>d[u]+w){
				// pre[e.to] = u;
				d[v] = d[u]+w;
				cnt[v]++;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
			
			if(cnt[v]>=n) return 1;
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
		int ww;
		scanf("%d%d%d",&n,&m,&ww);
		int u,v,w;init();
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&u,&v,&w);
// 			G[from].push_back((edge){to,cost});
// 			G[to].push_back((edge){from,cost});
			add(u,v,w);add(v,u,w);
		}
		for(int i = 0; i < ww; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,-w);
// 			G[from].push_back((edge){to,-cost});
		}
		bool flag = spfa(1);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}