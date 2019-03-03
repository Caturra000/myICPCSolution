#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MAXN = 2e5+11;
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
int a[MAXN],b[MAXN],p[MAXN];
char str[MAXN],ss[MAXN];
struct NODE{
    int lo,hi;
    NODE(int ll,int hh){
        lo=ll;
        hi=hh;
    }
    bool operator < (const NODE &r) const{
        if(lo!=r.lo) return lo<r.lo;
        return hi<r.hi;
    }
};
vector<NODE> vec[MAXN];
int main(){
    int len;
    while(cin>>len){
        scanf("%s",str+1);
        
        int v=read();
        int cnt=0;
        rep(i,1,v){
            scanf("%s",ss+1); p[i]=read();
            int len2=strlen(ss+1);
            rep(j,1,len-len2+1){
                bool flag=1;
                rep(jj,1,len2){
                    if(ss[jj]!=str[j+jj-1]){
                        flag=0;
                        break;
                    }
                }
                if(flag) vec[i].push_back(NODE(j,j+len2-1)),b[++cnt]=j,b[++cnt]=j+len2-1;
            }
        }
        int k=read();
        sort(b+1,b+1+cnt);
        cnt=unique(b+1,b+1+cnt)-b-1;
        rep(i,1,v){
            for(int j=0;j<vec[i].size();j++){
                vec[i][j].lo=lower_bound(b+1,b+1+cnt,vec[i][j].lo)-b;
                vec[i][j].hi=lower_bound(b+1,b+1+cnt,vec[i][j].hi)-b;
                // cout<<vec[i][j].lo<<" "<<vec[i][j].hi<<endl;
            }
        }
        int tt=cnt+1;s=1;t=tt+1;n=t;
        init();
        rep(i,1,tt) add(i,i+1,k,0);
        rep(i,1,v){
            for(int j=0;j<vec[i].size();j++){
                add(vec[i][j].lo,vec[i][j].hi+1,1,-p[i]);
            }
        }
        P ans=mcmf();
        println(-ans.first);
    }
    return 0;
}