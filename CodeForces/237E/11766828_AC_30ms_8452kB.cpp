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
int mcmf(){
    int mc=0,mf=0;
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
char str[500][500];
char st[maxn];
int num[maxn],n1,a[288];
inline int chai(int x){
    return x+n1;
}
inline int guai(int x){
    return x+2*n1;
}
int main(){
    while(scanf("%s",st)!=EOF){
        scan(n1);
        init();memset(a,0,sizeof a);
        int len=strlen(st);
        repp(i,0,len) a[st[i]-'a'+1]++;
        
        rep(i,1,n1){
            scanf("%s",str[i]);
            scan(num[i]);
        }
        // #define chai(x) ((x)+n1)
        // #define guai(x) ((x)+2*n1)
        rep(i,1,n1){
            add(i,chai(i),num[i],0);
            for(int j = 0; str[i][j]; j++){
                add(chai(i),guai(str[i][j]-'a'+1),1,i);
            }
        }
        s=2*n1+27;t=s+1;n=t;
        rep(i,1,n1) add(s,i,oo,0);
        rep(i,1,26) add(guai(i),t,a[i],0);
        int ans=mcmf();
        bool flag=0;
        repe(i,t){
            int v=to[i],c=cap[i^1],f=flow[i^1];
            // cout<<v<<" "<<c<<" "<<f<<endl;
            if(c&&f!=c) flag=1;
        }
        if(flag) println(-1);
        else println(ans);
    }
    return 0;
}