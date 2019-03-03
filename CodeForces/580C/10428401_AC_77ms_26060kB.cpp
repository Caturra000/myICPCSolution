#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 1e6+71;
int mark[maxn],vis[maxn],sum[maxn];
vector<int> G[maxn];
int n,m,from,to; 
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(G,0,sizeof G);memset(mark,0,sizeof mark);memset(vis,0,sizeof vis);memset(sum,0,sizeof sum);
		for(int i = 1; i <= n; i++){
			scanf("%d",&mark[i]);
		}
		for(int i = 1; i <= n-1; i++){
			scanf("%d%d",&from,&to);
			G[from].push_back(to);
			G[to].push_back(from);
		}
		queue<int> q; q.push(1);sum[1]=mark[1];vis[1]=1;
		while(!q.empty()){
			int u = q.front(); q.pop(); 
			for(int i = 0; i < G[u].size(); i++){
				int v = G[u][i];
				if(vis[v]) continue;
				if(mark[v]==0){
					sum[v]=0;
					q.push(v);vis[v]=1;
				}
				else{
					sum[v]=sum[u]+1;
					if(sum[u]+mark[v]<=m){
						//sum[v]=sum[u]+mark[v];
						q.push(v);vis[v]=1;
					}
				}
			}
		}
		int ans = 0;
//		for(int i = 1; i <= n; i++){
//			cout<<"i:"<<i<<" "<<sum[i]<<endl;
//			cout<<"size"<<G[i].size()<<endl;
//		}
		for(int i = 2; i <= n; i++){
			if(G[i].size()>1||!vis[i]) continue;
			if(sum[i]<=m) ans++;
		}
		printf("%d\n",n==1?0:ans);
	}
	return 0;
}