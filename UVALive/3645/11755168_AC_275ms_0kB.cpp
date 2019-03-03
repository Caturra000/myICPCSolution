#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
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
int trans(int a){
    return (a/100)*60+(a%100);
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
map<string,int> mp;
string ss,tt,s1,s2;
int a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
int st,ed,cnt,n1,m1,id1,id2;
int main(){
    // ios::sync_with_stdio(0);
    while(cin>>n1>>ss>>tt>>ed){
        init();mp.clear();cnt=0;
        if(!mp[ss]) mp[ss]=++cnt;
        if(!mp[tt]) mp[tt]=++cnt;
        id1=mp[ss];id2=mp[tt];
        
        scan(m1);
        rep(i,1,m1){
            cin>>s1>>s2>>c[i]>>d[i]>>e[i];
            if(!mp[s1]) mp[s1]=++cnt;
            if(!mp[s2]) mp[s2]=++cnt;
            a[i]=mp[s1];b[i]=mp[s2];
        }
        // rep(i,1,m1) cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<" "<<e[i]<<endl;
        s=3*m1+1;t=s+1;n=t;
        #define rg(x) ((x)+m1)
        #define chai(x) ((x)+2*m1)
        rep(i,1,m1){
            if(a[i]==id1) add(s,i,oo);
            if(b[i]==id2&&ed>=e[i]) add(rg(i),t,oo);
        }
        rep(i,1,m1){
            add(i,chai(i),c[i]);
            add(chai(i),rg(i),oo);
        }
        rep(i,1,m1){
            int time1=e[i];
            int id11=b[i];
            rep(j,1,m1){
                if(i==j)continue;
                int time2=d[j];
                int id22=a[j];
                if(id11==id22&&trans(time2)-trans(time1)>=30) add(rg(i),j,oo);
            }
        }
        int ans=isap();
        cout<<ans<<endl;
    }
    return 0;
}