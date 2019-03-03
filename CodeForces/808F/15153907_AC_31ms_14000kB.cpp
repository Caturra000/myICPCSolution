#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 2e5+11;
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

struct CARD{int p,c,l;}card[MAXN];
int v,k;
bool isprime[MAXN];
void shai(){
    rep(i,0,MAXN-1) isprime[i]=1;
    isprime[0]=isprime[1]=0;
    for(int i=2;i<MAXN;i++){
        if(isprime[i]){
            for(ll j=(ll)i*i;j<MAXN;j+=i){
                isprime[j]=0;
            }
        }
    }
}
bool C(int x){
    init();
    s=v+1;t=s+1;n=t;
    ll sum=0;
    bool _1=0;
    int pos=0,mxp=-1;
    rep(i,1,v){
        if(card[i].c!=1||card[i].l>x) continue;
        if(!_1) _1=1,pos=i,mxp=card[i].p;//cout<<mxp<<endl;
        else if(mxp<card[i].p){
            mxp=card[i].p;
            if(mxp>=k) return 1;
            pos=i;
        }
    }
    if(_1&&mxp>=k) return 1;
    rep(i,1,v) if(card[i].l<=x){
        if(card[i].c&1){
            if(card[i].c==1&&pos!=i) continue;
            sum+=card[i].p;
            add(s,i,card[i].p);
            rep(j,1,v) if(card[j].l<=x){
                if(i==j) continue;
                if(isprime[card[i].c+card[j].c]) add(i,j,oo);
            }
        }else{
            sum+=card[i].p;
            add(i,t,card[i].p);
        }
    }
    ll ans=sum-isap();
    return ans>=k;
}
int main(){
    shai();
    while(cin>>v>>k){
        rep(i,1,v){
            card[i].p=read();
            card[i].c=read();
            card[i].l=read();
        }
        int lo=1,hi=233;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(C(mid)) hi=mid;
            else lo=mid+1;
        }
        if(!C(lo)) println(-1);
        else println(lo);
    }
    return 0;
}