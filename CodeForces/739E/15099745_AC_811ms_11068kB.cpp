#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MAXN = 1e5+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f; 
const double EPS = 1e-7;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int to[MAXN<<1],nxt[MAXN<<1],from[MAXN<<1];
double cost[MAXN<<1];
ll cap[MAXN<<1],flow[MAXN<<1];
int head[MAXN],tot;
int n,m,s,t;
bool vis[MAXN];
ll pre[MAXN];
double dis[MAXN];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll c,double w){
    from[tot]=u;
    to[tot]=v;
    cap[tot]=c;
    flow[tot]=0;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    from[tot]=u;
    to[tot]=v;
    cap[tot]=0;
    flow[tot]=0;
    cost[tot]=-w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
struct QUEUE{
    int que[MAXN];
    int front,rear;
    void init(){front=rear=0;}
    void push(int x){que[rear++]=x;}
    int pop(){return que[front++];}
    bool empty(){return front==rear;}
}que;
bool spfa(){
    que.init();
    memset(vis,0,sizeof vis);
    memset(pre,-1,sizeof pre);
    rep(i,0,MAXN-1) dis[i]=1e19;
    que.push(s);
    vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int u=que.pop();vis[u]=0;
        for(int i = head[u]; ~i; i = nxt[i]){
            ll v=to[i],c=cap[i],f=flow[i];
            double w=cost[i];
            if(c>f&&dis[v]-(dis[u]+w)>EPS){
                dis[v]=dis[u]+w;
                pre[v]=i;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    if(dis[t]>=1e19) return 0;
    else return 1;
}

double mcmf(){
    ll mf=0; double mc=0;
    while(spfa()){
        ll tf=oo+1;
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
double p[MAXN],q[MAXN];
int main(){
    int v,a,b;
    while(cin>>v>>a>>b){
        init();
        rep(i,1,v) scanf("%lf",&p[i]);
        rep(i,1,v) scanf("%lf",&q[i]);
        int ss1=3*v+1;
        int ss2=3*v+2;
        s=ss2+1;t=s+1;n=t;
        add(s,ss1,a,0);
        add(s,ss2,b,0);
        rep(i,1,v) add(ss1,i,1,0);
        rep(i,1,v) add(ss2,i+v,1,0);
        rep(i,1,v) add(i,i+2*v,1,-p[i]);
        rep(i,1,v) add(i+v,i+2*v,1,-q[i]);
        rep(i,1,v) add(i+2*v,t,1,0);
        rep(i,1,v) add(i+2*v,t,1,p[i]*q[i]);
        double ans=mcmf();
        printf("%.4lf\n",-ans);
    }
    return 0;
}