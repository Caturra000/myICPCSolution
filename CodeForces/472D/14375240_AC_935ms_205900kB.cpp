#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e3+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int d[MAXN][MAXN],p[MAXN];
int head[2][MAXN],tot[2];
struct Edge{
    int from,to,nxt;
    ll cost;
    bool operator < (const Edge &rhs) const{
        return cost<rhs.cost;
    }
}edge[2][MAXN*MAXN];

void init(){
    memset(head,-1,sizeof head);
    rep(i,0,MAXN-1) p[i]=i;
    tot[0]=tot[1]=0;
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void add(int u,int v,ll w,int i=0){
    // from[tot]=u,to[tot]=v,cost[tot]=w;
    // nxt[tot]=head[u];head[u]=tot++;
    edge[i][tot[i]].from=u;edge[i][tot[i]].to=v;edge[i][tot[i]].cost=w;
    edge[i][tot[i]].nxt=head[i][u];head[i][u]=tot[i]++;
}
void MST(){
    sort(edge[0],edge[0]+tot[0]);
    rep(i,0,tot[0]-1){
        int u=edge[0][i].from,v=edge[0][i].to;
        ll w=edge[0][i].cost;
        int a=find(u),b=find(v);
        if(a==b) continue;
        p[b]=a;add(u,v,w,1);add(v,u,w,1);
    }
}
typedef pair<int,ll> P;
ll dis[MAXN];
void dijkstra(int st){
    memset(dis,0x3f,sizeof dis);dis[st]=0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(st,0));
    while(que.empty()^1){
        P p=que.top();que.pop();
        int u=p.first;
        if(dis[u]<p.second) continue;
        for(int i=head[1][u];~i;i=edge[1][i].nxt){ 
            int v=edge[1][i].to;
            ll w=edge[1][i].cost;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                que.push(P(v,dis[v]));
            }
        }
    }
}
int main(){
    int n;
    while(cin>>n){
        init();
        rep(i,1,n) rep(j,1,n){
            d[i][j]=read();
            add(i,j,d[i][j]);
        }
        MST();
        bool flag=0;
        rep(i,1,n){
            dijkstra(i);
            rep(j,1,n){
                if(dis[j]!=d[i][j]||(i!=j&&d[i][j]<1)){
                    flag=1;break;
                }
            }
            if(flag==1){
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}