#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 405; 
vector<int> G[maxn];
bool check[maxn];
int match[maxn][2];//left0right1
int k,m,n,from,to,cnt;
void init(){
	cnt = 0;
	memset(G,0,sizeof G);
	memset(match,0,sizeof match);
}
bool dfs(int u){
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(check[v]) continue;
		check[v] = 1;
		if(!match[v][1]||dfs(match[v][1])){
			match[u][0] = v;
			match[v][1] = u;
			return true;
		}
	}
	return false;
}
int main(){
	//ios::sync_with_stdio(false);
	int T,num; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		init();
		for(int i = 1; i <= m; i++){
			scanf("%d",&num);
			for(int j = 0; j < num; j++){
				scanf("%d",&to);
				G[i].push_back(to);
			}
		}
		for(int i = 1; i <= m; i++){
			memset(check,0,sizeof check); //NOTE
			if(!match[i][0]&&dfs(i)) cnt++;
		}
		if(cnt==m) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
} 