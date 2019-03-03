#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int to[maxn<<1],cost[maxn<<1],cap[maxn<<1],flow[maxn<<1],nxt[maxn<<1];
int head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,int c,int w){
    to[tot]=v;
    cap[tot]=c;
    flow[tot]=0;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    cap[tot]=0;
    flow[tot]=0;
    cost[tot]=-w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
struct QUEUE{
    int que[maxn];
    int front,rear;
    void init(){front=rear=0;}
    void push(int x){que[rear++]=x;}
    int pop(){return que[front++];}
    bool empty(){return front==rear;}
}que;
int n,m,s,t;
bool vis[maxn];
int pre[maxn],dis[maxn];
bool spfa(){
    que.init();
    memset(vis,0,sizeof vis);
    memset(pre,-1,sizeof pre);
    memset(dis,oo,sizeof dis);
    que.push(s);vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int u=que.pop(); vis[u]=0;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v=to[i],c=cap[i],f=flow[i],w=cost[i];
            if(c>f&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pre[v]=i;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    if(dis[t]==oo) return 0;
    else return 1;
}
int mc,mf;
void mcmf(){
    mc=mf=0;
    while(spfa()){
        int tf=oo+1;
        for(int i = pre[t]; ~i; i = pre[to[i^1]]){
            tf=min(tf,cap[i]-flow[i]);
        }
        mf+=tf;
        for(int i = pre[t]; ~i; i = pre[to[i^1]]){
            flow[i]+=tf;
            flow[i^1]-=tf;
        }
        mc+=dis[t]*tf;
    }
}
char G[233][233];
int row,col;
inline int ID(int a,int b){
    return (a-1)*col+b;
}
inline bool in(int a,int b){
    return a>=1&&a<=row&&b>=1&&b<=col;
}
int main(){
    while(scanf("%d%d",&row,&col)!=EOF){
        if(row==0) break;
        init();s=row*col+1;n=t=s+1;
        for(int i = 1; i <= row; i++){
            scanf("%s",G[i]+1);
        }
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(G[i][j]=='H') add((i-1)*col+j,t,1,0);
                if(G[i][j]=='m') add(s,(i-1)*col+j,1,0);
                if(in(i-1,j)) add(ID(i,j),ID(i-1,j),oo,1);
                if(in(i+1,j)) add(ID(i,j),ID(i+1,j),oo,1);
                if(in(i,j-1)) add(ID(i,j),ID(i,j-1),oo,1);
                if(in(i,j+1)) add(ID(i,j),ID(i,j+1),oo,1);
            }
        }
        mcmf();
        printf("%d\n",mc);
    }
    return 0;
}