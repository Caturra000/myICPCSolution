#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#include<queue>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int to[maxn<<1],nxt[maxn<<1],cap[maxn<<1],flow[maxn<<1];
int head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,int w){
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=w;
    flow[tot]=0;
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    nxt[tot]=head[u];
    cap[tot]=0;
    flow[tot]=0;
    head[u]=tot++;
}
//int n,m,s,t;
//int dis[maxn],pre[maxn],cur[maxn],gap[maxn];
//bool vis[maxn];
struct QUEUE{
    int que[maxn];
    int front,rear;
    void init(){front=rear=0;}
    void push(int u){que[rear++]=u;}
    int pop(){return que[front++];}
    bool empty(){return front==rear;}
}que;
int n,m,s,t;
int gap[maxn],dep[maxn];
void bfs(){
	memset(dep,-1,sizeof dep);
	memset(gap,0,sizeof gap);
	gap[0]=1;
	que.init();
	que.push(t);dep[t]=0;
	while(!que.empty()){
		int u = que.pop();
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i];
			if(~dep[v])continue;
			que.push(v);
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}	
}
int cur[maxn],S[maxn];
int isap(){
	bfs();
	memcpy(cur,head,sizeof head);
	int ans=0,top=0,u=s;
	while(dep[s]<n){
		if(u==t){
			int mn=oo;
			int inser;
			for(int i = 0; i < top; i++){
				if(mn>cap[S[i]]-flow[S[i]]){
					mn=cap[S[i]]-flow[S[i]];
					inser=i;
				}
			}
			for(int i = 0; i < top; i++){
				flow[S[i]]+=mn;
				flow[S[i]^1]-=mn;
			}
			ans+=mn;
			top=inser;
			u=to[S[top]^1];
			continue;
		}
		bool flag=0;
		int v;
		for(int i = cur[u]; ~i; i = nxt[i]){
			v=to[i];
			if(cap[i]-flow[i]&&dep[v]+1==dep[u]){
				flag=1;
				cur[u]=i;
				break;
			}
		}
		if(flag){
			S[top++]=cur[u];
			u=v;
			continue;
		}
		int mn=n;
		for(int i = head[u]; ~i; i = nxt[i]){
			if(cap[i]-flow[i]&&dep[to[i]]<mn){
				mn=dep[to[i]];
				cur[u]=i;
			}
		}
		gap[dep[u]]--;
		if(!gap[dep[u]])return ans;
		dep[u]=mn+1;
		gap[dep[u]]++;
		if(u!=s)u=to[S[--top]^1];
	}
	return ans;
}
int G[122][122];
int main(){
	int n1,ans,sum1,sum2,u,v;
	int a[maxn],b[maxn];
	while(scanf("%d%d",&n1,&m)!=EOF){
		init();sum1=sum2=0;
		n=2*n1+2;s=n-1;t=n;
		for(int i = 1; i <= n1; i++) {scanf("%d",&a[i]);sum1+=a[i];add(s,i,a[i]);}
		for(int i = 1; i <= n1; i++) {scanf("%d",&b[i]);sum2+=b[i];add(i+n1,t,b[i]);}
		for(int i = 1 ;i <= n1; i++) add(i,i+n1,oo);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&u,&v);
			add(u,v+n1,oo);
			add(v,u+n1,oo);
		}
		if(sum1!=sum2) printf("NO\n");
		else if(isap()!=sum2) printf("NO\n");
		else{
			printf("YES\n");
			memset(G,0,sizeof G);
			for(int i = 1; i <= n1; i++){
				for(int j = head[i]; ~j; j = nxt[j]){
					int v=to[j],f=flow[j];
					if(f>0&&v!=s)G[i][v-n1]=f;
				}
			}
			for(int i = 1; i <= n1; i++){
				for(int j = 1; j <= n1; j++){
					if(j==n1) printf("%d\n",G[i][j]);
					else printf("%d ",G[i][j]);
				}
			}
		} 
	}
	return 0;
} 