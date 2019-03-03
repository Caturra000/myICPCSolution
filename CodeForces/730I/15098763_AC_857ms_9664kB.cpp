#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
typedef long long ll;
using namespace std;
const int maxn = 1e5+11;
const int MAXN = maxn;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[maxn<<1],nxt[maxn<<1];
ll cost[maxn<<1],cap[maxn<<1],flow[maxn<<1];
int head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll c,ll w){
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
ll pre[maxn],dis[maxn];
bool spfa(){
    que.init();
    memset(vis,0,sizeof vis);
    memset(pre,-1,sizeof pre);
    memset(dis,0x3f,sizeof dis);
    que.push(s);vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int u=que.pop(); vis[u]=0;
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
typedef pair<ll,ll> P;
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
        mc+=dis[t]*tf;
    }
    return P(mc,mf);
}
// char str[MAXN],ss[233][233];
// int tong[28],limit[233];
// int sz[233];
// int a[233][28];
// int main(){
//     while(cin>>str){
//         init();
//         int len=strlen(str);
//         rep(i,0,len-1) tong[str[i]-'a'+1]++;
//         int v=read();
//         int totsz=0;
//         rep(i,1,v){
//             cin>>ss[i]>>limit[i];
//             sz[i]=strlen(ss[i]);
//             totsz+=sz[i];
//         }
//         s=totsz+26+v+1;t=s+1;n=t;
//         rep(i,1,v) add(totsz+i,t,limit[i],0);
//         rep(i,1,26) if(tong[i]) add(s,i,tong[i],0);
//         int curid=26;
//         rep(i,1,v){
//             curid+=sz[i-1];
//             rep(j,0,sz[i]-1){
//                 add(curid+j+1,totsz+i,1,i);
//                 if(tong[ss[i][j]-'a'+1]) add(ss[i][j]-'a'+1,curid+j+1,1,0);
//             }
//         }
//         P p=mcmf();
//         if(p.second!=len) println(-1);
//         else println(p.first);
//     }
//     return 0;
// }
int a[MAXN][2],v,p,q;
int main(){
    while(cin>>v>>p>>q){
        rep(i,1,v) a[i][0]=read();
        rep(i,1,v) a[i][1]=read();
        init();
        int ss=3*v+1;s=ss+1;
        int tt1=s+1,tt2=s+2;t=tt2+1;n=t;
        add(s,ss,p+q,0); add(tt1,t,p,0); add(tt2,t,q,0);
        rep(i,1,v) add(ss,i,1,0);
        rep(i,1,v){
            add(i,v+i,1,-a[i][0]); 
            add(i,2*v+i,1,-a[i][1]);
            add(v+i,tt1,1,0);
            add(2*v+i,tt2,1,0);
        }
        P pp=mcmf();
        println(-pp.first);
        stack<int> stk[2];
        erep(i,tt1){
            int u=to[i],f=flow[i];
            if(u==t||f==0) continue;
            stk[0].push(u-v);
        }
        erep(i,tt2){
            int u=to[i],f=flow[i];
            if(u==t||f==0) continue;
            stk[1].push(u-2*v);
        }
        rep(i,0,1) while(!stk[i].empty()){
            if(stk[i].size()==1) println(stk[i].top());
            else printbk(stk[i].top());
            stk[i].pop();
        }
    }
    return 0;
}