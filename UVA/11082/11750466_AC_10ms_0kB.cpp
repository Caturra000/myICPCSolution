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
int nxxt[maxn];
int aug(){
    int u=t,ans=oo;
    while(u!=s){
        ans=min(ans,cap[pre[u]]-flow[pre[u]]);
        //*************************************************
        nxxt[to[pre[u]^1]]=u;//NOTE
        //*************************************************
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
int main(){
    int T,kase=0,R,C,a[maxn],b[maxn],G[50][50]; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&C);
        for(int i = 1; i <= R; i++) scanf("%d",&a[i]);
        for(int i = 1; i <= C; i++) scanf("%d",&b[i]);
        for(int i = R; i >= 1; i--) a[i]=a[i]-a[i-1];
        for(int i = C; i >= 1; i--) b[i]=b[i]-b[i-1];
        init();s=R+C+1;t=s+1;n=t;
        for(int i = 1; i <= R; i++) add(s,i,a[i]-C);
        for(int i = 1; i <= C; i++) add(i+R,t,b[i]-R);
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                add(i,j+R,19);
            }
        }
        int ans=isap();
        memset(G,0,sizeof G);
        for(int i = 1; i <= R; i++){
            for(int j = head[i]; ~j; j=nxt[j]){
                int v=to[j],c=cap[j],f=flow[j];
                if(c==0||v==s)continue;
                G[i][v-R]=flow[j]+1;
            }
        }
        printf("Matrix %d\n",++kase);
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                if(j!=C) printf("%d ",G[i][j]);
                else printf("%d\n",G[i][j]);
            }
        }
        if(T) printf("\n");
    }
    return 0;
}