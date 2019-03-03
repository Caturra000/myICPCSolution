#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
//int to[maxn<<1],nxt[maxn<<1],cap[maxn<<1],flow[maxn<<1];
//int head[maxn],tot;
//void init(){
//    memset(head,-1,sizeof head);
//    tot=0;
//}
//void add(int u,int v,int w){
//    to[tot]=v;
//    nxt[tot]=head[u];
//    cap[tot]=w;
//    flow[tot]=0;
//    head[u]=tot++;
//    swap(u,v);
//    to[tot]=v;
//    nxt[tot]=head[u];
//    cap[tot]=0;
//    flow[tot]=0;
//    head[u]=tot++;
//}
//int n,m,s,t;
//int dis[maxn],pre[maxn],cur[maxn],gap[maxn];
//bool vis[maxn];
//struct QUEUE{
//    int que[maxn];
//    int front,rear;
//    void init(){front=rear=0;}
//    void push(int u){que[rear++]=u;}
//    int pop(){return que[front++];}
//    bool empty(){return front==rear;}
//}que;
//void bfs(){
//    memset(vis,0,sizeof vis);
//    que.init();
//    que.push(t);
//    vis[t]=1;dis[t]=0;
//    while(que.empty()^1){
//        int u = que.pop();
//        for(int i = head[u]; ~i; i = nxt[i]){
//            register int v=to[i],c=cap[i^1],f=flow[i^1];
//            if(!vis[v]&&c>f){
//                vis[v]=1;
//                dis[v]=dis[u]+1;
//                que.push(v);
//            }
//        }
//    }
//}
//int aug(){
//    int u=t,ans=oo;
//    while(u!=s){
//        ans=min(ans,cap[pre[u]]-flow[pre[u]]);
//        u=to[pre[u]^1];
//    }
//    u=t;
//    while(u!=s){
//        flow[pre[u]]+=ans;
//        flow[pre[u]^1]-=ans;
//        u=to[pre[u]^1];
//    }
//    return ans;
//}
//int isap(){
//    int ans=0;
//    bfs();
//    memset(gap,0,sizeof gap);
//    memcpy(cur,head,sizeof head);
//    for(int i = 1; i <= n; i++) gap[dis[i]]++;
//    int u = s;
//    while(dis[s]<n){
//        if(u==t){
//            ans+=aug();
//            u=s;
//        }
//        bool ok=0;
//        for(int i = cur[u]; ~i; i = nxt[i]){
//            int v=to[i],c=cap[i],f=flow[i];
//            if(c>f&&dis[u]==dis[v]+1){
//                ok=1;
//                pre[v]=i;
//                cur[u]=i;
//                u=v;
//                break;
//            }
//        }
//        if(!ok){
//            int mn=n-1;
//            for(int i = head[u]; ~i; i = nxt[i]){
//                int v=to[i],c=cap[i],f=flow[i];
//                if(c>f) mn=min(mn,dis[v]);
//            }
//            if(--gap[dis[u]]==0) break;
//            dis[u]=mn+1;gap[dis[u]]++;cur[u]=head[u];
//            if(u!=s) u=to[pre[u]^1]; 
//        }
//    }
//    return ans;
//}
int GG[122][122];
struct Edge{
    int to,cap,rev;
};
int d[maxn],n,m;
vector<Edge> G[maxn];
void add(int u,int v,int w){
    G[u].push_back((Edge){v,w,G[v].size()});
    G[v].push_back((Edge){u,0,G[u].size()-1});
}
bool bfs(int s,int t){
    queue<int> q;
    while(!q.empty())q.pop();
    memset(d,-1,sizeof d);
    d[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].to;
            if(G[u][i].cap>0&&d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
int dfs(int u,int t,int micap){
    if(u==t)return micap;
    int tmp;
    for(int i = 0; i < G[u].size(); i++){
        Edge &e=G[u][i];
        if(e.cap>0&&d[u]+1==d[e.to]&&(tmp=dfs(e.to,t,min(e.cap,micap)))){
            e.cap-=tmp;
            G[e.to][e.rev].cap+=tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic(int s,int t){
    int ans=0,tmp;
    while(bfs(s,t)){
        while(1){
            tmp=dfs(s,t,oo);
            if(tmp==0)break;
            ans+=tmp;
        }
    }
    return ans;
}
int s,t;vector<Edge> vec[maxn];
int main(){
	int n1,ans,sum1,sum2,u,v;
	int a[maxn],b[maxn];
	while(scanf("%d%d",&n1,&m)!=EOF){
		memset(G,0,sizeof G);sum1=sum2=0;
		n=2*n1+2;s=n-1;t=n;
		for(int i = 1; i <= n1; i++) {scanf("%d",&a[i]);sum1+=a[i];add(s,i,a[i]);}
		for(int i = 1; i <= n1; i++) {scanf("%d",&b[i]);sum2+=b[i];add(i+n1,t,b[i]);}
		for(int i = 1 ;i <= n1; i++) add(i,i+n1,oo);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&u,&v);
			add(u,v+n1,oo);
			add(v,u+n1,oo);
		}
		
		for(int i = 0; i < n; i++) vec[i]=G[i];
		if(sum1!=sum2) printf("NO\n");
		else if(dinic(s,t)!=sum2) printf("NO\n");
		else{
			printf("YES\n");
			memset(GG,0,sizeof GG);
			for(int i = 1; i <= n1; i++){
				for(int j = 0; j < G[i].size(); j++){
					int v=G[i][j].to,f=vec[i][j].cap;
					if(f>0&&v!=s)GG[i][v-n1]=f-G[i][j].cap;
				}
			}
			for(int i = 1; i <= n1; i++){
				for(int j = 1; j <= n1; j++){
					if(j==n1) printf("%d\n",GG[i][j]);
					else printf("%d ",GG[i][j]);
				}
			}
		} 
	}
	return 0;
} 