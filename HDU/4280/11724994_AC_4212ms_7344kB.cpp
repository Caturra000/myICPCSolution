#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
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
int n,m,s,t;
int gap[maxn],dep[maxn],que[maxn];
int cur[maxn],stk[maxn];
void bfs(){
	memset(dep,-1,sizeof dep);
	memset(gap,0,sizeof gap);
	gap[0]=1;
	int front=0,rear=0;
	que[rear++]=t;dep[t]=0;
	while(front^rear){
		int u = que[front++];
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i];
			if(~dep[v])continue;
			que[rear++]=v;
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}	
}
int isap(){
	bfs();
	memcpy(cur,head,sizeof head);
	int ans=0,top=0,u=s;
	while(dep[s]<n){
		if(u==t){
			int mn=oo;
			int inser;
			for(int i = 0; i < top; i++){
				if(mn>cap[stk[i]]-flow[stk[i]]){
					mn=cap[stk[i]]-flow[stk[i]];
					inser=i;
				}
			}
			for(int i = 0; i < top; i++){
				flow[stk[i]]+=mn;
				flow[stk[i]^1]-=mn;
			}
			ans+=mn;
			top=inser;
			u=to[stk[top]^1];
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
			stk[top++]=cur[u];
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
		if(u!=s)u=to[stk[--top]^1];
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