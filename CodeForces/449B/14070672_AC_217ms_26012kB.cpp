#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 5e5+11;
const int NN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
ll read() {
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// vector<int> last[MAXN],from[MAXN];
// bool vis[MAXN];
// void sai(int n){
//     rep(i,0,n) last[i].clear(),from[i].clear();
//     rep(i,0,n) last[i].push_back(i);
//     rep(i,2,n){
//         from[i].push_back(i);
//         for(int j=2*i;j<=n;j+=i){
//             last[j].push_back(i);
//             from[i].push_back(j);
//         }
//     }
// }
// bool cmp(vector<int> a,vector<int> b){
//     return (int)a.size()<(int)b.size();
// }
// int n;
// typedef pair<int,int> P;
// P ans[MAXN];
// int main(){
//     while(cin>>n){
//         // rep(i,1,n) a[i]=read();
//         memset(vis,0,sizeof vis);
//         sai(n);
//         int cnt=0;
//         sort(last+1,last+1+n,cmp);
//         rep(ii,1,n){
//             if((int)last[ii].size()<=1) continue;
//             int i=last[ii][0];
//             // cout<<"flag"<<i<<endl;
//             if(vis[i]) continue;
//             int sz=last[i].size();sz--;
//             rrep(j,sz,1){
//                 if(!vis[last[ii][j]]){
//                     vis[last[ii][j]]=1;
//                     ans[++cnt]=P(i,last[ii][j]);
//                     break;
//                 }
//             }
//         }
//         println(cnt);
//         rep(i,1,cnt) cout<<ans[i].first<<" "<<ans[i].second<<endl;
//     }
//     return 0;
// }
typedef pair<ll,ll> P;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
bool train[MAXN<<1];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll w,int t=0){
    to[tot]=v;
    cost[tot]=w;
    train[tot]=t;
    nxt[tot]=head[u];
    head[u]=tot++;
}
bool vis[NN];
ll dis[NN];
int block[NN];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    memset(vis,0,sizeof vis);
    memset(block,0,sizeof block);
    memset(dis,0x3f,sizeof dis); dis[s]=0;
    // memset(vis,0,sizeof vis); vis[s]=1;
    while(!que.empty()){
        P p=que.top(); que.pop();
        int u=p.second;
        int ww=p.first;
        if(ww>dis[u] || vis[u]) continue;
        vis[u]=1;
        erep(i,u){
            int v=to[i],w=cost[i],t=train[i];
            if(dis[v]>dis[u]+w || (dis[v]==dis[u]+w&&!t)){
                dis[v]=dis[u]+w;
                block[v]=t;
                que.push(P(dis[v],v));
            }
        }
    }
}
// void spfa(int s){
//     memset(block,0,sizeof block);
//     memset(dis,0x3f,sizeof dis); dis[s]=0;
//     memset(vis,0,sizeof vis); vis[s]=1;
//     queue<int> que; que.push(s);
//     while(!que.empty()){
//         int u=que.front(); que.pop();
//         vis[u]=0;
//         erep(i,u){
//             int v=to[i],w=cost[i],t=train[i];
//             if(dis[u]+w<dis[v]||(dis[u]+w==dis[v]&&!t)){
//                 dis[v]=dis[u]+w;
//                 block[v]=t;
//                 if(!vis[v]){
//                     vis[v]=1;
//                     que.push(v);
//                 }
//             }
//             // if(t&&dis[u]+w==dis[v]){
//             //     block[t]=1;
//             // }
//         }
//     }
// }
int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        init();
        rep(i,1,m){
            int u=read();
            int v=read();
            int w=read();
            add(u,v,w);add(v,u,w);
        }
        rep(i,1,k){
            int v=read();
            int w=read();
            add(1,v,w,1);add(v,1,w,1);
        }
        // spfa(1);
        dijkstra(1);
        ll ans=k;
        // rep(i,0,tot){
        //     if(train[i]&&block[i]) ans--;
        // }
        rep(i,1,n) ans-=block[i];
        println(ans);
    }
    return 0;
}