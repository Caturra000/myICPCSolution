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
int mcmf(int &mc){
    mc=0;int mf=0;
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
    return mf;
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
int main(){
    int n1,m,a[maxn],b[maxn],c[maxn];
    while(scan(n1)!=EOF){
        if(n1==0)break;
        init();
        scan(m);
        rep(i,1,m){
            scannn(a[i],b[i],c[i]);
            add(a[i],b[i],1,c[i]);add(b[i],a[i],1,c[i]);
        }
        s=n1+1;t=s+1;n=t;
        add(s,1,2,0);add(n1,t,oo,0);
        int mc;
        int ans=mcmf(mc);
        if(ans<2)printf("Back to jail\n");
        else println(mc);
    }
    return 0;
}