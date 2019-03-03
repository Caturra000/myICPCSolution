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
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
const int mod = 1000000009;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int from[maxn<<1],to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],head[maxn],tot;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
} 
void add(int u,int v,int w){
	from[tot]=u;to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
	swap(u,v);
	from[tot]=u;to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
}
int dp[maxn];
int dis[maxn];
int n,m;
typedef pair<int,int> P;
void dijkstra(int s){
	memset(dis,oo,sizeof dis);
//	memset(dp,0,sizeof dp);
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(s,0));
	dis[s]=0; dp[s]=1;
	while(!que.empty()){
		P p=que.top(); que.pop();
		int u=p.first;
		if(dis[u]<p.second)continue;
		erep(i,u){
			int v=to[i],w=cost[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push(P(v,dis[v]));
			}
		}
	}
}
bool vis[maxn];
bool findzero(int u){
	if(u==1)return 0;
	bool flag=0;
	erep(i,u){
		int v=to[i],w=cost[i];
		if(!vis[i]&&dis[u]==dis[v]+w){
			vis[i]=vis[i^1]=1;
			if(w==0) return 1;
			if(findzero(v)) return 1;
		}
	}
	return 0;
}
int DP(int u){
	if(~dp[u]) return dp[u];
	dp[u]=0;
	erep(i,u){
		int v=to[i],w=cost[i];
		if(!vis[i]&&dis[u]==dis[v]+w){
			vis[i]=1;
			vis[i^1]=1;
			dp[u]=(1ll*dp[u]+DP(v))%mod;
		}
	}
	return dp[u];
}
int main(){
	while(cin>>n>>m){
		init();
		rep(i,1,m){
			int u=read();
			int v=read();
			int w=read();
			add(u,v,w);
		}
		dijkstra(1);
		memset(vis,0,sizeof vis);
		bool flag=findzero(n);
		if(flag) println(-1);
		else{
			memset(dp,-1,sizeof dp);
			memset(vis,0,sizeof vis);
			dp[1]=1;
			println(DP(n));
//			rep(i,1,n){
//				cout<<i<<" "<<dp[i]<<endl;
//			}
			
		}
	}
	return 0;
}