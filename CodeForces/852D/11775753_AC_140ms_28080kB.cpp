#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+11;
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
int n,m,s,t;
int dis[maxn],pre[maxn],cur[maxn],gap[maxn];
bool vis[maxn];
struct QUEUE{
    int que[maxn];
    int front,rear;
    void init(){front=rear=0;}
    void push(int u){que[rear++]=u;}
    int pop(){return que[front++];}
    bool empty(){return front==rear;}
}que;
void bfs(){
    memset(vis,0,sizeof vis);
    que.init();
    que.push(t);
    vis[t]=1;dis[t]=0;
    while(que.empty()^1){
        int u = que.pop();
        for(int i = head[u]; ~i; i = nxt[i]){
            register int v=to[i],c=cap[i^1],f=flow[i^1];
            if(!vis[v]&&c>f){
                vis[v]=1;
                dis[v]=dis[u]+1;
                que.push(v);
            }
        }
    }
}
int aug(){
    int u=t,ans=oo;
    while(u!=s){
        ans=min(ans,cap[pre[u]]-flow[pre[u]]);
        u=to[pre[u]^1];
    }
    u=t;
    while(u!=s){
        flow[pre[u]]+=ans;
        flow[pre[u]^1]-=ans;
        u=to[pre[u]^1];
    }
    return ans;
}
int isap(){
    int ans=0;
    bfs();
    memset(gap,0,sizeof gap);
    memcpy(cur,head,sizeof head);
    for(int i = 1; i <= n; i++) gap[dis[i]]++;
    int u = s;
    while(dis[s]<n){
        if(u==t){
            ans+=aug();
            u=s;
        }
        bool ok=0;
        for(int i = cur[u]; ~i; i = nxt[i]){
            int v=to[i],c=cap[i],f=flow[i];
            if(c>f&&dis[u]==dis[v]+1){
                ok=1;
                pre[v]=i;
                cur[u]=i;
                u=v;
                break;
            }
        }
        if(!ok){
            int mn=n-1;
            for(int i = head[u]; ~i; i = nxt[i]){
                int v=to[i],c=cap[i],f=flow[i];
                if(c>f) mn=min(mn,dis[v]);
            }
            if(--gap[dis[u]]==0) break;
            dis[u]=mn+1;gap[dis[u]]++;cur[u]=head[u];
            if(u!=s) u=to[pre[u]^1];
        }
    }
    return ans;
}
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define repp(i,j,k) for(int i = j; i < k; i++)
#define repe(i,u) for(int i = head[u]; ~i; i = nxt[i])
#define scan(a) scanf("%d",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define scannn(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define println(a) printf("%d\n",a)
#define printbk(a) printf("%d ",a)
#define print(a) printf("%d",a)
int V,E,N,K,st[maxn];//V city
long long G[605][605];

int cost[maxn<<1];
void init2(){
	memset(head,-1,sizeof head);
	tot=0; 
} 
long long dd[maxn];
bool in[maxn];
void add2(int u,int v,int w){
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
	swap(u,v);
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
}
void spfa(int s){
	memset(dd,oo,sizeof dd);memset(in,0,sizeof in);
	queue<int> q;
	q.push(s);in[s]=1;dd[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();in[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(dd[v]>dd[u]+w){
				dd[v]=dd[u]+w;
				if(!in[v]){
					in[v]=1;
					q.push(v);
				}
			}
		}
	}
}
bool C(int mid){
    init();
    #define rg(x) ((x)+N)
    s=N+V+1; t=s+1; n=t;
    rep(i,1,N) add(s,i,1);
    rep(i,1,V) add(rg(i),t,1);
    rep(i,1,N){
        rep(j,1,V){
            if(G[st[i]][j]<=mid) 
                add(i,rg(j),1);
        }
    }
    int ans=isap();//cout<<mid<<" "<<ans<<endl;
    return ans>=K;
}
#define rr register
bool go[maxn];
int main(){
    while(scann(V,E)!=EOF){
        scann(N,K);memset(G,oo,sizeof G);init2();
        rep(i,1,N) scan(st[i]);
        rep(i,1,E){
            rr int f,t,w;
            scannn(f,t,w);
			add2(f,t,w);
        }
        memset(go,0,sizeof go);
        rep(i,1,N){
        	if(!go[st[i]]){
        		go[st[i]]=1;
        		spfa(st[i]);
			}
			else continue;
        	rep(j,1,V){
				G[st[i]][j]=min(G[st[i]][j],dd[j]);
				G[j][st[i]]=min(G[j][st[i]],dd[j]);
			} 
		}
        int l=0,r=1731311,mid;
        if(!C(r)){
        	println(-1);
        	continue;
		}
        while(l<=r){
            mid=l+(r-l)/2;
            if(C(mid)) r=mid-1;
            else l=mid+1;
        }
        println(l);
    }
    return 0;
}