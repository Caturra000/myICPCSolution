#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;
const int maxn = 5e5+11;
const int oo = 0x3f3f3f3f;
typedef pair<int,int> P;
int head[maxn],tot;
int to[maxn<<1],cost[maxn<<1],nxt[maxn<<1];
int d[maxn];
int n,u,v,w;
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
void spfa(int s){
	memset(inq,0,sizeof inq);
	memset(d,oo,sizeof d);
	queue<int> q; d[s]=0;
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		inq[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		int r=0;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d",&u,&v,&w);
			if(u>v)swap(u,v);
			add(u,v+1,-w);r=max(r,max(u,v+1));
		}
		for(int i = 0; i < r; i++){
			add(i,i+1,0);add(i+1,i,1);
		}
		for(int i = 1; i <= r; i++){
			add(0,i,0);
		} 
		spfa(0);
		printf("%d\n",-d[r]);
	}
	return 0;
}