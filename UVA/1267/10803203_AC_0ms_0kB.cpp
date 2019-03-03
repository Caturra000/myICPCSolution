#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
int n,s,k,from,to;
vector<int> G[maxn],lv[maxn];
int p[maxn],d[maxn];//lvnum[maxn];
bool cover[maxn],vis[maxn];
int lvcnt,dmax,ans;//init
typedef pair<int,int> P;
void dfs(int u,int dep,int fa){
    p[u]=fa;d[u]=dep;dmax=max(dmax,dep);
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(v==fa) continue;
        dfs(v,dep+1,u);
    }
    if(G[u].size()==1) {lv[dep].push_back(u);/*islv[u]=1;*/lvcnt++;}
//    if(!fa) ch[fa].push_back(u);
}
int cnt;//init
void dfs2(int u,int dis,int fa,int flag){
	if(dis>k) return;
//    if(islv[u]&&!cover[u]) {cover[u]=1;cnt++;}
	cover[u]=1;
    for(int i = 0; i < G[u].size(); i++){
        int v=G[u][i];
        if(v!=fa) dfs2(v,dis+1,u,1);
    }
    if(flag){
    	int f=u;
    	for(int i = 0; i < k; i++){
    		f=p[f];
		}	
		dfs2(f,dis,p[f],0);
    }
}
void bfs(int u,int dis,int fa){
	queue<P> q;while(!q.empty())q.pop();
	q.push(P(u,dis));cover[u]=1;
	memset(vis,0,sizeof vis);
	while(!q.empty()){
		P x=q.front();u=x.first;q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if(x.second>0) cover[v]=1;
			if(!vis[v]&&x.second>0){
				q.push(P(v,x.second-1));
				vis[v]=1;
			}
		}
	}
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&s,&k);
        ans=dmax=lvcnt=cnt=0;
        memset(G,0,sizeof G);memset(lv,0,sizeof lv);
        //memset(islv,0,sizeof islv);
		memset(p,0,sizeof p);memset(d,0,sizeof d);memset(cover,0,sizeof cover);
        for(int i = 0; i < n-1; i++){
            scanf("%d%d",&from,&to);
            G[from].push_back(to);
            G[to].push_back(from);
        }
        dfs(s,0,0);
        dfs2(s,0,0,0);
        for(int i = dmax; i > k; i--){
            for(int j = 0; j < lv[i].size(); j++){
                int u=lv[i][j];
                if(cover[u]) continue;
                int fa=u;
                for(int kk = 0; kk < k; kk++){
                    fa=p[fa];
                }
				bfs(fa,k,p[fa]);
				ans++;
            }
        }
		printf("%d\n",ans);
    }
    return 0;
}