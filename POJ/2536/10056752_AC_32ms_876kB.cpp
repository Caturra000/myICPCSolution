#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 105; 
vector<int> G[maxn];
bool check[maxn];
int match[maxn][2];//left0right1
struct point{
	double x,y;
};
vector<point> p1,p2;
int k,m,n,from,to,cnt,s,v;
double x,y;
void init(){
	cnt = 0;
	memset(G,0,sizeof G);
	memset(match,-1,sizeof match);
	p1.clear();
}
bool dfs(int u){
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(check[v]) continue;
		check[v] = 1;
		if(match[v][1]==-1||dfs(match[v][1])){ //NOTE ==
			match[u][0] = v;
			match[v][1] = u;
			return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF){
		init();
		for(int i = 0; i < n; i++){
			scanf("%lf%lf",&x,&y);
			p1.push_back((point){x,y});
		}
		for(int j = 0; j < m; j++){
			scanf("%lf%lf",&x,&y);
			for(int k = 0; k < n; k++){
				double d = (p1[k].x-x)*(p1[k].x-x)+(p1[k].y-y)*(p1[k].y-y);
				if(s*s*v*v-d>=0) G[j].push_back(k);
			}
		}
		for(int i = 0; i < m; i++){
			memset(check,0,sizeof check);
			if(dfs(i)) cnt++; //NOTE ==
		}
		printf("%d\n",n-cnt); 
	}
	return 0;
} 