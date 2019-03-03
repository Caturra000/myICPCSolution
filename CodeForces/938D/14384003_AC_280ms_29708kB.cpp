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
struct Q{
    int v;
    ll w;
    Q(int vv,ll ww){
        v=vv;w=ww;
    }
};

typedef pair<ll,ll> P;vector<P> G[MAXN];
ll dis[MAXN];
#define INF 1000000005000
void DIJ(int st,int n)
{
    for(int i=0; i<=n+1; i++) dis[i]=INF;
    priority_queue<P,vector<P>,greater<P> > my_que;
    dis[st]=0;
    my_que.push(P(0,st));
    while(!my_que.empty())
    {
        P p=my_que.top(); my_que.pop();
        int v=p.second;
        if(dis[v]<p.first) continue;
        for(int i=0; i<(int)G[v].size(); i++)
        {
            if(dis[G[v][i].first]>dis[v]+G[v][i].second)
            {
                dis[G[v][i].first]=dis[v]+G[v][i].second;
                my_que.push(P(dis[G[v][i].first],G[v][i].first));
            }
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        rep(i,0,n+1) G[i].clear(); 
        rep(i,1,m){
            int u,v;ll w;
            u=read();
            v=read();
            w=read()<<1;
            G[u].push_back(P(v,w));
            G[v].push_back(P(u,w));
        }
        rep(i,1,n){
            ll w; w=read();
            G[n+1].push_back(P(i,w));
        }
        DIJ(n+1,n);
        rep(i,1,n){
            if(i==n) println(dis[i]);
            else printf("%lld ",dis[i]);
        }
    }
    return 0;
}