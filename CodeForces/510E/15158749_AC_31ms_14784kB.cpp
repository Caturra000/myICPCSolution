#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
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
vector<int> vec,rec[MAXN];
bool vvis[2333],isprime[MAXN];
int v,a[MAXN];
void dfs(int x){
    vvis[x]=1;
    vec.push_back(x);
    for(int i=head[x];~i;i=nxt[i]){
        int y=to[i],f=flow[i];
        if(y==s||y==t||f==0||vvis[y]) continue;
        dfs(y);
    }
}
void printpath(){
    memset(vvis,0,sizeof vvis);
    rep(i,0,v) rec[i].clear();
    ll sz=0;
    rep(i,1,v) if(!vvis[i]){
        vec.clear();
        dfs(i);
        rec[i]=vec;
        sz++; 
    }
    println(sz);
    rep(i,1,v) if(rec[i].size()){
        printbk(rec[i].size());
        if(rec[i].size()==1){
            println(rec[i][0]);
            continue;
        }
        printbk(rec[i][0]);
        for(int j=(int)rec[i].size()-1;j;j--){
            if(j==1) println(rec[i][j]);
            else printbk(rec[i][j]);
        }
    }
}
void shai(){
    rep(i,0,MAXN-1) isprime[i]=1;
    isprime[1]=isprime[0]=0;
    for(int i=2;i<MAXN;i++){
        if(isprime[i]){
            for(ll j=(ll)i*i;j<MAXN;j+=i){
                isprime[j]=0;
            }
        }
    }
}
int main(){
    shai();
    while(cin>>v){
        rep(i,1,v) a[i]=read();
        init();
        s=v+1;t=s+1;n=t;
        rep(i,1,v){
            if(a[i]&1){
                add(s,i,2);
                rep(j,1,v){
                    if(isprime[a[i]+a[j]]){
                        add(i,j,1);
                    }
                }
            }else add(i,t,2);
        }
        ll ans=isap(); //cout<<ans<<endl;
        if(ans!=v) printf("Impossible\n");
        else printpath();
    }
    return 0;
}