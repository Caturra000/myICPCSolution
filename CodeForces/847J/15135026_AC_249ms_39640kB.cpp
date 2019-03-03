#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 5e5+11;
const int MAXN = maxn;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

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
int b[MAXN],a[MAXN][2],deg[MAXN];
int v,p;
int vec[MAXN][2];
bool C(int x){
    init();
    s=p+v+1;t=s+1;n=t;
    rep(i,1,p) add(s,v+i,1);
    rep(i,1,p) add(v+i,a[i][0],1),add(v+i,a[i][1],1);
    rep(i,1,v) add(i,t,min(deg[i],x));//min can del
    ll ans=isap();
    if(ans<p) return 0;
    
    
    for(int i=head[s];~i;i=nxt[i]){
        int vv=to[i];
        for(int j=head[vv];~j;j=nxt[j]){
            int vvv=to[j];
            if(vvv==s||flow[j]==0) continue;
            int vvvv=0;
            if(vvv==a[vv-v][0]) vvvv=a[vv-v][1];
            else vvvv=a[vv-v][0];
            vec[vv-v][0]=vvv;
            vec[vv-v][1]=vvvv;
            break;
        }
    }
    return 1;
}

void printpath(){
    for(int i=1;i<=p;i++){
        printbk(vec[i][0]);
        println(vec[i][1]);
    }
}
int main(){
    while(cin>>v>>p){
        memset(deg,0,sizeof deg);
        rep(i,1,p){
            a[i][0]=read();
            a[i][1]=read();
            deg[a[i][0]]++;
            deg[a[i][1]]++;
        }
        int lo=0,hi=23333;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(C(mid)) hi=mid;
            else lo=mid+1;
        }
        println(lo);
        printpath();
    }
    return 0;
}