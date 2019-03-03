#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int head[maxn],tot;
int to[maxn<<1],cost[maxn<<1],nxt[maxn<<1];
int d[maxn];
int n,u,v,w[maxn],x,y;
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
	memset(d,0x80,sizeof d);
	memset(cnt,0,sizeof cnt);
	queue<int> q; d[s]=0;
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		inq[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(d[v]<d[u]+w){
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
char str[100];
int main(){
	int kase=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		init(); 
		for(int i = 1; i <= n; i++) {scanf("%d",&w[i]);add(0,i,0);}
		while(scanf("%s",str)){
			if(str[0]=='#')break;
			scanf("%d%d",&u,&v);
//			if(strcmp(str,"FAS")==0){//d[u]+w[u]>=d[v]  d[v]<=d[u]+w[u]
//				add(u,v,w[u]); 
//			}
//			else if(strcmp(str,"FAF")==0){//d[u]+w[u]>=d[v]+w[v]  d[v]<=d[u]+w[u]-w[v]
//				add(u,v,w[u]-w[v]);
//			}
//			else if(strcmp(str,"SAF")==0){//d[u]>=d[v]+w[v]  d[v]<=d[u]-w[v]
//				add(u,v,-w[v]);
//			}
//			else{//SAS d[u]>=d[v] d[v]<=d[u]
//				add(u,v,0);
//			}
			if(strcmp(str,"FAS")==0){//d[u]+w[u]>=d[v]  d[v]<=d[u]+w[u]
				add(v,u,-w[u]); 
			}
			else if(strcmp(str,"FAF")==0){//d[u]+w[u]>=d[v]+w[v]  d[v]<=d[u]+w[u]-w[v]
				add(v,u,-w[u]+w[v]);
			}
			else if(strcmp(str,"SAF")==0){//d[u]>=d[v]+w[v]  d[v]<=d[u]-w[v]
				add(v,u,w[v]);
			}
			else{//SAS d[u]>=d[v] d[v]<=d[u]
				add(v,u,0);
			}
		}
		printf("Case %d:\n",++kase);
		if(spfa(0)) printf("impossible\n");
		else for(int i = 1; i <= n; i++) printf("%d %d\n",i,d[i]);
		printf("\n");
	}
	return 0; 
}