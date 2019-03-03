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
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int to[MAXN<<1],nxt[MAXN<<1],from[MAXN<<1];
ll cost[MAXN<<1],cap[MAXN<<1],flow[MAXN<<1];
int head[MAXN],tot;
int n,m,s,t;
bool vis[MAXN];
ll pre[MAXN],dis[MAXN];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll c,ll w){
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
    memset(dis,0x3f,sizeof dis);
    que.push(s);
    vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int u=que.pop();vis[u]=0;
        for(int i = head[u]; ~i; i = nxt[i]){
            ll v=to[i],c=cap[i],f=flow[i],w=cost[i];
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

P mcmf(){
    ll mc=0,mf=0;
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
        mc+=tf*dis[t];
    }
    return P(mc,mf);
}
int lo[MAXN],hi[MAXN];
int cnt[MAXN],num[MAXN]; 
int main(){
    num[1]=1;
    rep(i,2,MAXN-1) num[i]=num[i-1]+2;
    int v,q;
    while(cin>>v>>q){
        rep(i,1,v) lo[i]=1,hi[i]=v;
        rep(i,1,q){
            int op=read();
            int l=read();
            int r=read();
            int c=read();
            if(op==1) rep(j,l,r) lo[j]=max(lo[j],c);
            if(op==2) rep(j,l,r) hi[j]=min(hi[j],c);
        }
        init();
        bool flag=0;
        memset(cnt,0,sizeof cnt);
        s=100+v+1;t=s+1;n=t;
        rep(i,1,v) add(s,i,1,0);
        rep(i,1,v){
            if(lo[i]>hi[i]){
                flag=1;
                break;
            }
            rep(j,lo[i],hi[i]){
                cnt[j]++;
                add(i,j+v,1,0);
                add(j+v,t,1,num[cnt[j]]);
            }
        }
        if(flag==1){
            println(-1);
            continue;
        }
        P ans=mcmf();
        println(ans.first);
    }
    return 0;
}