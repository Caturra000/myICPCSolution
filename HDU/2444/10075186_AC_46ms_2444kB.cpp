#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 250;
int n,m,u,v,flag,cnt;
bool check[maxn];
int match[maxn],color[maxn];
vector<int> G[maxn];
void init(){
	flag = 0; cnt = 0;
	memset(match,0,sizeof match);
	memset(color,0,sizeof color);
	memset(G,0,sizeof G); 
}
bool go(int u,int c){
	if(color[u]) if(color[u]!=c) return false;
	color[u] = c;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(!color[v]){
			color[v] = -c;
			if(!go(v,-c)) return false;
		}
		else if(color[v]==color[u]){
			return false;
		}
	}
	return true;
}
bool dfs(int u){
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(check[v]) continue;
		check[v] = 1;
		if(!match[v]||dfs(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init(); 
		for(int i = 0; i < m; i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		flag = !go(1,1)||n==1;
		if(!flag) for(int i = 1; i <= n; i++){
			memset(check,0,sizeof check);
			if(dfs(i)) cnt++; //!match 
		}
		if(!flag) printf("%d\n",cnt/2);
		else printf("No\n");
	}
	return 0;
}