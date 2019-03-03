#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int to[maxn<<1],nxt[maxn<<1];
double cap[maxn<<1],flow[maxn<<1];
double cost[maxn<<1];
int head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,double c,double w){
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
int pre[maxn];
double dis[maxn];
bool spfa(){
    que.init();
    memset(vis,0,sizeof vis);
    memset(pre,-1,sizeof pre);
    for(int i = 0; i < n+12; i++) dis[i]=oo;
    que.push(s);vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int u=que.pop(); vis[u]=0;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v=to[i];
            double c=cap[i],f=flow[i],w=cost[i];
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
double mcmf(double &mf){
    double mc=0;
    mf=0;
    while(spfa()){
        double tf=oo+1;
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
    return mc;
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
double x[maxn],y[maxn];
double ddis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int n1;
int chai(int x){
    return x+n1;
}
int main(){
    while(scan(n1)!=EOF){
        init();
        rep(i,1,n1){
            scanf("%lf%lf",&x[i],&y[i]);
        }
        s=2*n1+1;t=s+1;n=t;
        rep(i,1,n1){
            add(s,i,2,0);
            add(chai(i),t,1,0);
        }
        rep(i,1,n1){
            rep(j,1,n1){
                if(i==j)continue;
                double ddd=ddis(x[i],y[i],x[j],y[j]);
                if(y[i]>y[j]) add(i,chai(j),1,ddd);
            }
        }
        double mf;
        double ans=mcmf(mf);
        if(mf!=n1-1) println(-1);
        else printf("%.15lf\n",ans);
    }
    return 0;
}