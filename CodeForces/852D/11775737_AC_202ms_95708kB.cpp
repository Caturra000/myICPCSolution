#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
struct Edge{
    int to,cap,rev;
};
int d[maxn],n,m;
vector<Edge> GG[maxn];
void add(int u,int v,int w){
    GG[u].push_back((Edge){v,w,GG[v].size()});
    GG[v].push_back((Edge){u,0,GG[u].size()-1});
}
bool bfs(int s,int t){
    queue<int> q;
    while(!q.empty())q.pop();
    memset(d,-1,sizeof d);
    d[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i = 0; i < GG[u].size(); i++){
            int v = GG[u][i].to;
            if(GG[u][i].cap>0&&d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
int dfs(int u,int t,int micap){
    if(u==t)return micap;
    int tmp;
    for(int i = 0; i < GG[u].size(); i++){
        Edge &e=GG[u][i];
        if(e.cap>0&&d[u]+1==d[e.to]&&(tmp=dfs(e.to,t,min(e.cap,micap)))){
            e.cap-=tmp;
            GG[e.to][e.rev].cap+=tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic(int s,int t){
    int ans=0,tmp;
    while(bfs(s,t)){
        while(1){
            tmp=dfs(s,t,oo);
            if(tmp==0)break;
            ans+=tmp;
        }
    }
    return ans;
}
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define repp(i,j,k) for(int i = j; i < k; i++)
#define repe(i,u) for(int i = head[u]; ~i; i = nxt[i])
#define scan(a) scanf("%d",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define scannn(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define println(a) printf("%d\n",a)
#define printbk(a) printf("%d ",a)
#define print(a) printf("%d",a)
int V,E,N,K,st[maxn];//V city
long long G[605][605];

void init(){
	memset(GG,0,sizeof GG);
}
int head[maxn],tot;
int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1];
void init2(){
	memset(head,-1,sizeof head);
	tot=0; 
} 
long long dd[maxn];
bool in[maxn];
void add2(int u,int v,int w){
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
	swap(u,v);
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
}
void spfa(int s){
	memset(dd,oo,sizeof dd);memset(in,0,sizeof in);
	queue<int> q;
	q.push(s);in[s]=1;dd[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();in[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(dd[v]>dd[u]+w){
				dd[v]=dd[u]+w;
				if(!in[v]){
					in[v]=1;
					q.push(v);
				}
			}
		}
	}
}
bool C(int mid){
    init();
    #define rg(x) ((x)+N)
    int s=N+V+1; int t=s+1; n=t;
    rep(i,1,N) add(s,i,1);
    rep(i,1,V) add(rg(i),t,1);
    rep(i,1,N){
        rep(j,1,V){
            if(G[st[i]][j]<=mid) 
                add(i,rg(j),1);
        }
    }
    int ans=dinic(s,t);//cout<<mid<<" "<<ans<<endl;
    return ans>=K;
}
#define rr register
bool go[maxn];
int main(){
    while(scann(V,E)!=EOF){
        scann(N,K);memset(G,oo,sizeof G);init2();
        rep(i,1,N) scan(st[i]);
        rep(i,1,E){
            rr int f,t,w;
            scannn(f,t,w);
			add2(f,t,w);
        }
        memset(go,0,sizeof go);
        rep(i,1,N){
        	if(!go[st[i]]){
        		go[st[i]]=1;
        		spfa(st[i]);
			}
			else continue;
        	rep(j,1,V){
				G[st[i]][j]=min(G[st[i]][j],dd[j]);
				G[j][st[i]]=min(G[j][st[i]],dd[j]);
			} 
		}
        int l=0,r=1731311,mid;
        if(!C(r)){
        	println(-1);
        	continue;
		}
        while(l<=r){
            mid=l+(r-l)/2;
            if(C(mid)) r=mid-1;
            else l=mid+1;
        }
        println(l);
    }
    return 0;
}