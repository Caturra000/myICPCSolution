#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
vector<int> vec[MAXN];
int k[MAXN];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll w){
    to[tot]=v,cost[tot]=w,nxt[tot]=head[u];
    head[u]=tot++;
}
typedef pair<int,ll> P;
ll dis[MAXN];
vector<int> nextto[MAXN];
void dijkstra(int st,int n){
    memset(dis,0x3f,sizeof dis);
    dis[st]=0;
    priority_queue<P,vector<P>,greater<P> > que; 
    que.push(P(st,0));
    while(que.empty()^1){
        P p=que.top(); que.pop();
        int u=p.first;
        if(dis[u]<p.second) continue;
        for(int i=head[u];~i;i=nxt[i]){
            int v=to[i];ll w=cost[i];
            int t;
            vector<int>::iterator it=lower_bound(vec[u].begin(),vec[u].end(),dis[u]);
            if(it==vec[u].end()||u==n) t=0;
            else if(*it==dis[u]){
                int pos=it-vec[u].begin();
                if(nextto[u][pos]==-1){
                    t=1;
                }else{
                    t=1+vec[u][nextto[u][pos]]-dis[u];
                }
            }
            else t=0;
            if(dis[v]>dis[u]+w+t){
                dis[v]=dis[u]+w+t;
                que.push(P(v,dis[v]));
            }
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        init();
        rep(i,1,m){
            int u=read();
            int v=read();
            ll w=read();
            add(u,v,w);
            add(v,u,w);
        }
        rep(i,1,n){
            k[i]=read();
            vec[i].clear();
            nextto[i].clear();
            if(k[i]==0) continue;
            nextto[i].resize(k[i]);
            rep(j,1,k[i]){
                vec[i].push_back(read());
            }
            nextto[i][k[i]-1]=-1;
            rrep(j,k[i]-2,0){
                if(vec[i][j]==vec[i][j+1]||vec[i][j]==vec[i][j+1]-1){
                    if(j+1==k[i]-1) nextto[i][j]=j+1;
                    else if(nextto[i][j+1]==-1) nextto[i][j]=j+1;
                    else nextto[i][j]=nextto[i][j+1];
                }else{
                    nextto[i][j]=-1;
                }
            }
        }
        
        dijkstra(1,n);
        println(dis[n]==0x3f3f3f3f3f3f3f3f?-1:dis[n]);
    }
    return 0;
}