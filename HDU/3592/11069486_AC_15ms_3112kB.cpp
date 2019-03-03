#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
int head[maxn],tot;
int to[maxn<<1],cost[maxn<<1],nxt[maxn<<1];
int d[maxn];
int n,u,v,w,x,y;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int u,int v,int w){
	to[tot]=v;cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot++;
} 
bool inq[maxn];
int cnt[maxn];
bool spfa(int s){
	memset(inq,0,sizeof inq);
	memset(d,oo,sizeof d);
	memset(cnt,0,sizeof cnt);
	queue<int> q; d[s]=0;
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		inq[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				cnt[v]++;
				if(cnt[v]>n)return 1;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d%d",&n,&x,&y);
		for(int i = 0; i < x; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		for(int i = 0; i < y; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,-w);
		}
		for(int i = 2; i <= n; i++){
			add(i,1,0);
		}
		if(!spfa(1)){
			if(d[n]!=oo) printf("%d\n",d[n]);
			else printf("-2\n");
		}
		else printf("-1\n"); 
	}
	return 0;
}