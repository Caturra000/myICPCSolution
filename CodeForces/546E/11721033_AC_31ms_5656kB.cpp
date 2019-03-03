#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int GG[122][122];
struct Edge{
    int to,cap,rev;
};
int d[maxn],n,m;
vector<Edge> G[maxn];
void add(int u,int v,int w){
    G[u].push_back((Edge){v,w,G[v].size()});
    G[v].push_back((Edge){u,0,G[u].size()-1});
}
bool bfs(int s,int t){
    queue<int> q;
    while(!q.empty())q.pop();
    memset(d,-1,sizeof d);
    d[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].to;
            if(G[u][i].cap>0&&d[v]==-1){
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
    for(int i = 0; i < G[u].size(); i++){
        Edge &e=G[u][i];
        if(e.cap>0&&d[u]+1==d[e.to]&&(tmp=dfs(e.to,t,min(e.cap,micap)))){
            e.cap-=tmp;
            G[e.to][e.rev].cap+=tmp;
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
int s,t;vector<Edge> vec[maxn];
int main(){
	int n1,ans,sum1,sum2,u,v;
	int a[maxn],b[maxn];
	while(scanf("%d%d",&n1,&m)!=EOF){
		memset(G,0,sizeof G);sum1=sum2=0;
		n=2*n1+2;s=n-1;t=n;
		for(int i = 1; i <= n1; i++) {scanf("%d",&a[i]);sum1+=a[i];add(s,i,a[i]);}
		for(int i = 1; i <= n1; i++) {scanf("%d",&b[i]);sum2+=b[i];add(i+n1,t,b[i]);}
		for(int i = 1 ;i <= n1; i++) add(i,i+n1,oo);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&u,&v);
			add(u,v+n1,oo);
			add(v,u+n1,oo);
		}
		
		for(int i = 0; i < n; i++) vec[i]=G[i];
		if(sum1!=sum2) printf("NO\n");
		else if(dinic(s,t)!=sum2) printf("NO\n");
		else{
			printf("YES\n");
			memset(GG,0,sizeof GG);
			for(int i = 1; i <= n1; i++){
				for(int j = 0; j < G[i].size(); j++){
					int v=G[i][j].to,f=vec[i][j].cap;
					if(f>0&&v!=s)GG[i][v-n1]=f-G[i][j].cap;
				}
			}
			for(int i = 1; i <= n1; i++){
				for(int j = 1; j <= n1; j++){
					if(j==n1) printf("%d\n",GG[i][j]);
					else printf("%d ",GG[i][j]);
				}
			}
		} 
	}
	return 0;
} 