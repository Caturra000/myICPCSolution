#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MAXN = 1e6+11;
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
struct Q{ll st,ed,c;}a[MAXN];
ll b[MAXN];
int id[MAXN];
map<ll,ll> mp;
int main(){
    int v,k;
    while(cin>>v>>k){
        mp.clear();
        int cnt=0;
        rep(i,1,v){
            b[++cnt]=a[i].st=read();
            a[i].ed=b[++cnt]=a[i].st+read()-1;
            a[i].c=read();
        }
        init();
        sort(b+1,b+1+cnt);
        cnt=unique(b+1,b+1+cnt)-b-1;
        rep(i,1,cnt) mp[b[i]]=i;
        rep(i,2,cnt) add(i-1,i,k,0);
        s=1;t=cnt+2;n=t;
        add(cnt,cnt+1,k,0);add(cnt+1,t,k,0);
        rep(i,1,v){
            add(mp[a[i].st],mp[a[i].ed]+1,1,-a[i].c);
            id[i]=tot-2;
        }
        mcmf();
        rep(i,1,v){
            if(i==v) println(flow[id[i]]);
            else printbk(flow[id[i]]);
        }
    }
    return 0;
}