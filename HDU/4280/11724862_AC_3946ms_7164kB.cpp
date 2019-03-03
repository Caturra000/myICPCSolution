#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x7fffffff;
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
    cap[tot]=w;
    flow[tot]=0;
    head[u]=tot++;
}
struct QUEUE{
    int que[maxn];
    int front,rear;
    inline void init(){front=rear=0;}
    inline void push(int u){que[rear++]=u;}
    inline int pop(){return que[front++];}
    inline bool empty(){return front==rear;}
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
int main(){
    int T,x,y,u,v,w; scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        int mn=oo,mx=-oo;
        int mni=1,mxi=1;
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&x,&y);
            if(x<mn){
                mn=x;
                mni=i;
            }
            if(x>mx){
                mx=x;
                mxi=i;
            }
        }
        s=mni,t=mxi;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        printf("%d\n",isap());
    }
    return 0;
}