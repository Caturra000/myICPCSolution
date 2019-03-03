#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e6+11;
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
int v,e,g;
int val[MAXN],bet[MAXN];
bool black[MAXN],appoint[MAXN],isfriend[MAXN];
vector<int> vec[MAXN];
int main(){
    while(cin>>v>>e>>g){
        ll sum=0; init();
        rep(i,1,e) vec[i].clear();
        rep(i,1,v) black[i]=read();
        rep(i,1,v) val[i]=read();
        rep(i,1,e){
            appoint[i]=read();
            bet[i]=read(); sum+=bet[i];
            int k=read();
            while(k--) vec[i].push_back(read());
            isfriend[i]=read();
        }
        s=v+e+1; t=s+1; n=t;
        rep(i,1,v){
            if(black[i]) add(s,i,val[i]);
            else add(i,t,val[i]);
        }
        rep(i,1,e){
            if(appoint[i]) add(s,i+v,bet[i]+(isfriend[i]?g:0));
            else add(i+v,t,bet[i]+(isfriend[i]?g:0));
            unordered_set<int> us;
            iter(j,vec[i]){
                us.insert(vec[i][j]);
                if(black[vec[i][j]]^appoint[i]){
                    if(appoint[i]) add(i+v,vec[i][j],oo);
                    else add(vec[i][j],i+v,oo);
                }
            }
            rep(j,1,e) if(appoint[i]^appoint[j]){
                iter(k,vec[j]) if(us.find(vec[j][k])!=us.end()){
                    if(appoint[i]) add(i+v,j+v,oo);
                    else add(j+v,i+v,oo);
                    break;
                }
            }
        }
        println(sum-isap());
    }
    return 0;
}