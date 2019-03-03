#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++) 
using namespace std;
const int maxn = 4e4+11;
typedef long long ll;
const int oo = 0x3f3f3f3f;
vector<int> vec[333];//block 
int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],head[maxn],tot;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int u,int v,int w){
	to[tot]=v;nxt[tot]=head[u];cost[tot]=w;
	head[u]=tot++;
	swap(u,v);
	to[tot]=v;nxt[tot]=head[u];cost[tot]=w;
	head[u]=tot++;
}
int dis[maxn];
bool vis[maxn];
bool xx[666];
int n,m,k,e;
int spfa(int day1,int day2){
	if(day1>day2)swap(day1,day2);
	memset(dis,oo,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(xx,0,sizeof xx);
	for(int day=day1;day<=day2;day++){
		for(int t = 0; t < vec[day].size(); t++){
			xx[vec[day][t]]=1;
		}
	}
	stack<int> que; 
	que.push(1);vis[1]=1;dis[1]=0;
	while(!que.empty()){
		int u=que.top(); que.pop();vis[u]=0;
		for(int i=head[u]; ~i; i=nxt[i]){
			int v=to[i],w=cost[i];
			if(!xx[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
	return dis[m];
}
ll dp[333]; 
ll rec[333][333];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);
		init();
		for(int i = 0; i < 333; i++) vec[i].clear();
		int u,v,w,t,a,b,c;
		rep(i,1,e){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		scanf("%d",&t);
		rep(i,1,t){
			scanf("%d%d%d",&c,&a,&b);
			rep(j,a,b) vec[j].push_back(c);
		}
		rep(i,1,n) rep(j,1,n) rec[i][j]=1ll<<60; 
		rep(i,1,n) rep(j,i,n) rec[i][j]=spfa(i,j);
		rep(i,1,n) dp[i]=rec[1][i]*i;
		dp[0]=0;
		rep(i,1,n){
			rep(j,0,i-1){
				dp[i]=min(dp[i],dp[j]+rec[j+1][i]*(i-j)+k);
			}
		}
		printf("%lld\n",dp[n]);
	
	return 0;
}